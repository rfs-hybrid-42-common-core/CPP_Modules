/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:45:48 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/20 03:24:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <exception>
#include <list>
#include <stack>
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class RPN
 * @brief Evaluates mathematical expressions in Reverse Polish Notation.
 * @details Utilizes a stack based on a doubly-linked list (std::list) to 
 * process single-digit integer operands and arithmetic operators. It enforces 
 * strict formatting rules, validates arithmetic limits to prevent overflows, 
 * and handles all edge cases associated with postfix notation.
 */
class RPN
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        std::stack<long, std::list<long> > _stack;

        /* ------------------------------------------------------------------ */
        /* PRIVATE METHODS                                                    */
        /* ------------------------------------------------------------------ */
        void _calculate(const char op);
        
    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        RPN(void);
        RPN(RPN const & other);
        ~RPN(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        RPN& operator=(RPN const & other);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void processInput(std::string const & str);

    /* ====================================================================== */
    /* EXCEPTIONS                                                             */
    /* ====================================================================== */

    /**
     * @class Exception
     * @brief Generic exception for the RPN class.
     * @details Inherits from std::exception. Serves as the polymorphic base 
     * class for all specific parsing and arithmetic exceptions.
     */
    class Exception : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class EmptyStringException
     * @brief Exception thrown when the input string is empty or just 
     * whitespaces.
     * @details Prevents the parser from evaluating strings that contain no 
     * valid tokens to process.
     */
    class EmptyStringException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };   

    /**
     * @class InvalidInputException
     * @brief Exception thrown when encountering forbidden characters or 
     * formats.
     * @details Triggered if the string contains non-math characters, 
     * multi-digit numbers, or if numbers and operators are not separated by 
     * whitespaces.
     */
    class InvalidInputException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class LackOfNumbersException
     * @brief Exception thrown when there are insufficient operands.
     * @details Triggered if an operator is called when the stack has fewer 
     * than two numbers, or if the stack is completely empty at the end of 
     * processing.
     */
    class LackOfNumbersException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class LackOfOperatorsException
     * @brief Exception thrown when an expression leaves residual operands.
     * @details Triggered if, after fully evaluating the string, the stack 
     * contains more than one number, indicating a mathematically incomplete 
     * expression.
     */
    class LackOfOperatorsException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class DivisionByZeroException
     * @brief Exception thrown to prevent undefined mathematical behavior.
     * @details Triggered when the division operator ('/') is processed and the 
     * right-hand operand (the top of the stack) is identically 0.
     */
    class DivisionByZeroException : public Exception
    {
        public:
            virtual const char* what() const throw();        
    };

    /**
     * @class NumericLimitsException
     * @brief Exception thrown to prevent hardware arithmetic overflows.
     * @details Triggered during pre-computation bounds checking if an 
     * addition, subtraction, multiplication, or division would exceed standard 
     * long limits.
     */
    class NumericLimitsException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif
