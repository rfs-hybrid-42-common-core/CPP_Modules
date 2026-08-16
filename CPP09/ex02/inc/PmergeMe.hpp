/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:47:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/24 03:19:20 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <exception>
#include <deque>
#include <vector>
#include <string>
#include <cstddef>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class PmergeMe
 * @brief Implements the Ford-Johnson Merge-Insert sort algorithm for 
 * std::vector and std::deque.
 * @details Utilizes the Ford-Johnson sorting algorithm to sort a sequence of 
 * positive integers. Instead of utilizing standard recursive structures, it 
 * uses an advanced memory-chunking architecture (stride method) to sort 
 * elements in-place before employing a Jacobsthal-based binary search to 
 * achieve optimal comparison counts. Benchmarks the execution time of both 
 * std::vector and std::deque.
 */
class PmergeMe
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        std::deque<unsigned int>  _deque;
        std::vector<unsigned int> _vector;

        /* ------------------------------------------------------------------ */
        /* PRIVATE METHODS                                                    */
        /* ------------------------------------------------------------------ */
        void _parseInput(char **argv);
        bool _isSorted(void) const;
        void _printSequence(std::string const & label) const;

        /* ------------------------------------------------------------------ */
        /* PRIVATE TEMPLATE METHODS                                           */
        /* ------------------------------------------------------------------ */
        template <typename Container>
        void _fordJohnsonMergeInsert(Container& container, size_t chunk_size = 1);
    
        template <typename Container>
        void _jacobsthalInsert(Container& mainChain, Container const & pendChain, size_t chunk_size);

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        PmergeMe(void);
        PmergeMe(PmergeMe const & other);
        ~PmergeMe(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        PmergeMe& operator=(PmergeMe const & other);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void processInput(char **argv);

    /* ====================================================================== */
    /* EXCEPTIONS                                                             */
    /* ====================================================================== */

    /**
     * @class Exception
     * @brief Generic exception for the PmergeMe class.
     * @details Inherits from std::exception. Serves as the base class for all 
     * specific parsing and validation exceptions, allowing polymorphic 
     * catching.
     */
    class Exception : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class NoNumbersException
     * @brief Exception thrown when the input yields no valid integers.
     * @details Triggered if the input strings consisted entirely of 
     * whitespaces or empty strings, leaving the initial containers empty.
     */
    class NoNumbersException : public Exception
    {
        public:
            virtual const char* what() const throw();        
    };

    /**
     * @class DuplicateNumbersException
     * @brief Exception thrown when a duplicate number is found in the sequence.
     * @details Triggered during the parsing phase. A std::set is utilized to 
     * verify uniqueness in O(N log N) time before the sorting algorithm begins.
     */
    class DuplicateNumbersException : public Exception
    {
        public:
            virtual const char* what() const throw();        
    };

    /**
     * @class NumericLimitsException
     * @brief Exception thrown when a number is zero or overflows unsigned int 
     * limits.
     * @details Triggered exclusively when parsed values exceed the maximum 
     * capacity of a standard unsigned int, or if the value is explicitly 0 
     * (since the sequence must consist strictly of positive integers).
     */
    class NumericLimitsException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class InvalidInputException
     * @brief Exception thrown when non-numeric characters are encountered.
     * @details Triggered when the string contains alphabetical characters, 
     * negative signs, special symbols, or fails the strict std::istringstream 
     * extraction test.
     */
    class InvalidInputException : public Exception
    {
        public:
            virtual const char* what() const throw();        
    };
};

#include "PmergeMe.tpp"

#endif
