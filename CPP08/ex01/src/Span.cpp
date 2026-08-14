/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:18:24 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 23:40:07 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include "Span.hpp"

/* --------------------------- Standard Libraries --------------------------- */
#include <algorithm>
#include <limits>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Span::Span(void)
 * @brief Default constructor for the Span class.
 * @details Initializes an empty Span with a maximum capacity of 0.
 */
Span::Span(void) : _N(0) {}

/**
 * @fn Span::Span(unsigned int N)
 * @brief Parameterized constructor for the Span class.
 * @details Initializes the Span with a specific maximum capacity and reserves 
 * the corresponding memory in the internal vector to optimize insertions.
 * @param N The maximum number of integers the Span can store.
 */
Span::Span(unsigned int N) : _N(N)
{
    _numbers.reserve(_N);
}

/**
 * @fn Span::Span(Span const & other)
 * @brief Copy constructor for the Span class.
 * @details Performs a deep copy of the capacity and stored numbers from the 
 * 'other' Span object.
 * @param other The Span object to copy from.
 */
Span::Span(Span const & other) : _N(other._N), _numbers(other._numbers) {}

/**
 * @fn Span::~Span(void)
 * @brief Destructor for the Span class.
 * @details Safely destroys the Span object. Standard vector destruction 
 * handles internal memory deallocation automatically.
 */
Span::~Span(void) {}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Span& Span::operator=(Span const & other)
 * @brief Copy assignment operator overload.
 * @details Safely assigns the values of 'other' to the current instance, 
 * protecting against self-assignment.
 * @param other The Span object to assign from.
 * @return      A reference to the newly assigned Span object.
 */
Span& Span::operator=(Span const & other)
{
    if (this != &other)
    {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Span::addNumber(int const num)
 * @brief Adds a single number to the Span.
 * @details Checks if the maximum capacity has been reached before inserting 
 * the new integer into the internal container.
 * @param  num The integer to add to the Span.
 * @throws     std::out_of_range if there are already N elements stored.
 */
void Span::addNumber(int const num)
{
    if (_numbers.size() >= _N)
        throw std::out_of_range("span has already reached max capacity");
    _numbers.push_back(num);
}

/**
 * @fn unsigned int Span::shortestSpan(void) const
 * @brief Calculates the shortest span between all numbers stored.
 * @details Sorts a local copy of the internal container to efficiently find 
 * the minimum distance between any two adjacent elements in linear time. Uses 
 * an early exit optimization if a span of 0 is found.
 * @return The shortest distance between any two numbers in the Span.
 * @throws NoSpanFoundException if there are no numbers stored, or only one.
 */
unsigned int Span::shortestSpan(void) const
{
    if (_numbers.size() < 2)
        throw NoSpanFoundException();

    std::vector<int> temp(_numbers);
    std::sort(temp.begin(), temp.end());

    unsigned int min = std::numeric_limits<unsigned int>::max();
    std::vector<int>::const_iterator it = temp.begin();
    std::vector<int>::const_iterator next_it = temp.begin() + 1;
    std::vector<int>::const_iterator ite = temp.end();
    
    for (; next_it != ite; ++it, ++next_it)
    {
        unsigned int res = static_cast<unsigned int>(*next_it) - static_cast<unsigned int>(*it);
        if (res < min)
        {
            min = res;
            if (min == 0)
                break;
        }
    }

    return min;
}

/**
 * @fn unsigned int Span::longestSpan(void) const
 * @brief Calculates the longest span between all numbers stored.
 * @details Utilizes standard algorithms (std::min_element, std::max_element) 
 * to find the lowest and highest values in linear time without mutating or 
 * sorting the container.
 * @return The longest distance between any two numbers in the Span.
 * @throws NoSpanFoundException if there are no numbers stored, or only one.
 */
unsigned int Span::longestSpan(void) const 
{
    if (_numbers.size() < 2)
        throw NoSpanFoundException();

    unsigned int highest = static_cast<unsigned int>(*(std::max_element(_numbers.begin(), _numbers.end())));
    unsigned int lowest = static_cast<unsigned int>(*(std::min_element(_numbers.begin(), _numbers.end())));

    return (highest - lowest);
}

/* ========================================================================== */
/* EXCEPTIONS                                                                 */
/* ========================================================================== */

/**
 * @fn const char* Span::Exception::what() const throw()
 * @brief Returns the generic error message for Span errors.
 * @details Overrides the what() function from std::exception to provide a 
 * statically allocated, generic error message. This serves as the fallback 
 * message for the base exception class, enabling clean polymorphic error 
 * handling without dynamic memory allocation overhead.
 * @return A C-style character string describing the error.
 */
const char* Span::Exception::what() const throw()
{
    return ("encountered a generic error.");
}

/**
 * @fn const char* Span::NoSpanFoundException::what() const throw()
 * @brief Returns the error message for invalid span calculations.
 * @details Inherits from Span::Exception to provide specific error 
 * handling for when the container is empty or contains only one element. 
 * By overriding the what() method, it integrates seamlessly into the 
 * polymorphic exception catching structure.
 * @return A C-style character string describing the error.
 */
const char* Span::NoSpanFoundException::what() const throw()
{
    return ("not enough numbers to find span.");
}
