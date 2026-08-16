/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:48:15 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/24 21:45:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "PmergeMe.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <ctime>

/* ========================================================================== */
/* PRIVATE METHODS                                                            */
/* ========================================================================== */

/**
 * @fn void PmergeMe::_parseInput(char **argv)
 * @brief Parses and validates the raw command-line input arguments.
 * @details Filters out completely whitespace arguments. Uses 
 * std::istringstream for strict numeric extraction, rejecting garbage trails. 
 * Ensures values are strictly positive and fit within an unsigned int. Uses a 
 * std::set to verify no duplicates exist across the dataset before appending 
 * the numbers to both benchmark containers.
 * @param argv The null-terminated array of argument strings.
 * @throws     InvalidInputException if the format contains non-numeric characters.
 * @throws     NumericLimitsException if a value overflows or equals zero.
 * @throws     NoNumbersException if the final containers contain zero elements.
 * @throws     DuplicateNumbersException if identical numbers are detected.
 */
void PmergeMe::_parseInput(char **argv)
{
    for (; *argv; ++argv)
    {
        std::string str = *argv;

        if (str.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
            continue;

        if (str.find_first_not_of(" \t\n\v\f\r0123456789+") != std::string::npos)
            throw InvalidInputException();

        std::istringstream iss(str);
        std::string token;
        unsigned long value;

        while (iss >> token)
        {
            std::istringstream tokenStream(token);
            tokenStream >> value;

            if (tokenStream.fail() || !tokenStream.eof())
                throw InvalidInputException();
            
            if (value > std::numeric_limits<unsigned int>::max() || value == 0)
                throw NumericLimitsException();

            _deque.push_back(static_cast<unsigned int>(value));
            _vector.push_back(static_cast<unsigned int>(value));
        }
    }

    if (_deque.empty() || _vector.empty())
        throw NoNumbersException();

    std::set<unsigned int> uniqueNumbers;
    for (std::deque<unsigned int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it)
    {
        if (uniqueNumbers.find(*it) != uniqueNumbers.end())
            throw DuplicateNumbersException();
        uniqueNumbers.insert(*it);
    }
}

/**
 * @fn bool PmergeMe::_isSorted(void) const
 * @brief Checks if the base sequence is natively sorted.
 * @details Iterates through the deque evaluating adjacent elements to verify 
 * strict ascending order. Bypasses the sorting algorithm if already sorted.
 * @return true if perfectly sorted or if size < 2, false otherwise.
 */
bool PmergeMe::_isSorted(void) const
{
    if (_deque.size() < 2)
        return true;
    
    for (std::deque<unsigned int>::const_iterator it = _deque.begin(); it + 1 != _deque.end(); ++it)
        if (*it > *(it + 1)) return false;

    return true;
}

/**
 * @fn void PmergeMe::_printSequence(std::string const & label) const
 * @brief Formats and prints the sequence contents.
 * @details Iterates through the reference deque and prints its contents 
 * separated by spaces. Used to print the mandatory "Before:" and "After:" 
 * lines.
 * @param label The prefix tag identifying the current sequence state.
 */
void PmergeMe::_printSequence(std::string const & label) const
{
    std::cout << label;
    for (std::deque<unsigned int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
}

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn PmergeMe::PmergeMe(void)
 * @brief Default constructor for PmergeMe.
 * @details Initializes an empty PmergeMe instance. The underlying std::deque 
 * and std::vector containers are automatically default-constructed and await 
 * population via the processInput method.
 */
PmergeMe::PmergeMe(void) {}

/**
 * @fn PmergeMe::PmergeMe(PmergeMe const & other)
 * @brief Copy constructor for PmergeMe.
 * @details Safely performs a deep copy of both the vector and deque containers.
 * @param other The PmergeMe instance to copy.
 */
PmergeMe::PmergeMe(PmergeMe const & other) : _deque(other._deque), _vector(other._vector) {}

/**
 * @fn PmergeMe::~PmergeMe(void)
 * @brief Destructor for PmergeMe.
 * @details Safely destroys the PmergeMe object. Memory management is 
 * implicitly handled by the STL containers' own destructors, ensuring no 
 * memory leaks occur during tear-down.
 */
PmergeMe::~PmergeMe(void) {}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn PmergeMe& PmergeMe::operator=(PmergeMe const & other)
 * @brief Copy assignment operator overload.
 * @details Safely replaces the internal containers with copies from 'other', 
 * strictly guarding against self-assignment.
 * @param other The PmergeMe object to assign from.
 * @return      A reference to the active object.
 */
PmergeMe& PmergeMe::operator=(PmergeMe const & other)
{
    if (this != &other)
    {
        _deque = other._deque;
        _vector = other._vector;
    }
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void PmergeMe::processInput(char **argv)
 * @brief Manages the execution pipeline and benchmarking timers.
 * @details Uses the standard C++ <ctime> clock() to measure strict CPU cycles 
 * rather than wall-clock time, neutralizing arbitrary OS delays. Calculates 
 * elapsed microsecond times safely using double promotion before 
 * mathematically aligning with CLOCKS_PER_SEC limits to ensure cross-platform 
 * precision. Incorporates the initial data management and parsing overhead 
 * into the final benchmark times to reflect total processing cost accurately.
 * @param argv The raw array of input string arguments, offset to bypass the 
 * executable name.
 */
void PmergeMe::processInput(char **argv)
{
    clock_t parseStart = clock();
    _parseInput(argv);
    clock_t parseEnd = clock();

    double parseTime = (static_cast<double>(parseEnd - parseStart) / CLOCKS_PER_SEC) * 1000000.0;
    double dataManagementTime = parseTime / 2.0;

    if (_isSorted())
    {
        std::cout << "Sequence is already sorted." << std::endl;
        return;
    }

    _printSequence("Before:");

    clock_t dequeStart = clock();
    _fordJohnsonMergeInsert(_deque);
    clock_t dequeEnd = clock();
    double dequeTime = (static_cast<double>(dequeEnd - dequeStart) / CLOCKS_PER_SEC) * 1000000.0;

    clock_t vectorStart = clock();
    _fordJohnsonMergeInsert(_vector);
    clock_t vectorEnd = clock();
    double vectorTime = (static_cast<double>(vectorEnd - vectorStart) / CLOCKS_PER_SEC) * 1000000.0;

    _printSequence("After: ");

    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " 
              << std::fixed << std::setprecision(5) << (dequeTime + dataManagementTime) << " us" << std::endl;

    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << (vectorTime + dataManagementTime) << " us" << std::endl;
}

/* ========================================================================== */
/* EXCEPTIONS                                                                 */
/* ========================================================================== */

/**
 * @fn const char* PmergeMe::Exception::what() const throw()
 * @brief Returns the generic error message.
 * @details Overrides std::exception::what() to provide a statically allocated 
 * error message acting as a generic fallback for polymorphic exception 
 * handling within the PmergeMe pipeline.
 * @return A C-style character string describing the error.
 */
const char* PmergeMe::Exception::what() const throw()
{
    return ("encountered a generic error.");
}

/**
 * @fn const char* PmergeMe::NoNumbersException::what() const throw()
 * @brief Returns the specific error message for empty numerical datasets.
 * @details Inherits from Exception to provide a specific, statically allocated 
 * string indicating that the parsing phase yielded no valid integers to sort.
 * @return A C-style character string describing the error.
 */
const char* PmergeMe::NoNumbersException::what() const throw()
{
    return ("no numbers found in container.");
}

/**
 * @fn const char* PmergeMe::DuplicateNumbersException::what() const throw()
 * @brief Returns the specific error message for duplicate datasets.
 * @details Inherits from Exception to provide a specific, statically allocated 
 * string indicating that the input sequence contained non-unique values.
 * @return A C-style character string describing the error.
 */
const char* PmergeMe::DuplicateNumbersException::what() const throw()
{
    return ("duplicate numbers found in container.");
}

/**
 * @fn const char* PmergeMe::NumericLimitsException::what() const throw()
 * @brief Returns the specific error message for values exceeding standard 
 * limits.
 * @details Inherits from Exception to provide a specific, statically allocated 
 * string indicating that a parsed token either overflowed the standard 
 * unsigned integer limits or was explicitly equal to zero.
 * @return A C-style character string describing the error.
 */
const char* PmergeMe::NumericLimitsException::what() const throw()
{
    return ("numeric limits exceeded.");
}

/**
 * @fn const char* PmergeMe::InvalidInputException::what() const throw()
 * @brief Returns the specific error message for illegal formatting or 
 * characters.
 * @details Inherits from Exception to provide a specific, statically allocated 
 * string indicating a failure during string stream extraction, typically 
 * caused by alphabetical characters, negative signs, or other invalid symbols.
 * @return A C-style character string describing the error.
 */
const char* PmergeMe::InvalidInputException::what() const throw()
{
    return ("invalid input format.");
}
