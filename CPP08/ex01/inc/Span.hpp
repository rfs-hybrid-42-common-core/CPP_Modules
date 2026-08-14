/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 02:20:35 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/16 03:17:54 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <iterator>
#include <vector>
#include <exception>
#include <stdexcept>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Span
 * @brief A container class capable of storing a maximum of N integers.
 * @details Calculates the shortest and longest span (distance) between all 
 * the numbers stored. It enforces a maximum capacity and relies on standard 
 * algorithms for calculations.
 */
class Span
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        unsigned int     _N;
        std::vector<int> _numbers;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Span(void);
        Span(unsigned int N);
        Span(Span const & other);
        ~Span(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        Span& operator=(Span const & other);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void addNumber(int const num);
        unsigned int shortestSpan(void) const;
        unsigned int longestSpan(void) const ;

        /**
         * @fn void addNumbers(Iterator begin, Iterator end)
         * @brief Adds a sequence of numbers using a range of iterators.
         * @details Avoids thousands of individual addNumber() calls by 
         * bulk-inserting elements.
         * @tparam Iterator The type of the iterators provided.
         * @param  begin    The starting iterator of the sequence.
         * @param  end      The ending iterator of the sequence.
         * @throws          std::out_of_range if adding the range exceeds max 
         * capacity.
         */
        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end)
        {
            unsigned int distance = std::distance(begin, end);
            if (_numbers.size() + distance > _N)
                throw std::out_of_range("Adding this range exceeds Span max capacity.");
            _numbers.insert(_numbers.end(), begin, end);
        }

    /* ====================================================================== */
    /* EXCEPTIONS                                                             */
    /* ====================================================================== */

    /**
     * @class Exception
     * @brief Generic exception for the Span class.
     * @details Inherits from std::exception. Serves as the base class for all 
     * specific Span exceptions, allowing polymorphic catching.
     */
    class Exception : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class NoSpanFoundException
     * @brief Exception thrown when a span cannot be calculated.
     * @details Inherits from Exception to provide custom error handling when 
     * the Span container is empty or contains only one element. This enables 
     * polymorphic catching through the generic Span::Exception.
     */
    class NoSpanFoundException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif
