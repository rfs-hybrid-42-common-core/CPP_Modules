/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:46:34 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/24 03:31:10 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "RPN.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <limits>
#include <sstream>

/* ========================================================================== */
/* PRIVATE METHODS                                                            */
/* ========================================================================== */

/**
 * @fn void RPN::_calculate(const char op)
 * @brief Pops the top two operands and executes the specified arithmetic 
 * operation.
 * @details Implements rigorous pre-computation bounds checking to prevent 
 * integer overflow and underflow scenarios (including the notorious 
 * INT_MIN / -1 trap) before pushing the successful result back onto the stack.
 * @param op The arithmetic operator ('+', '-', '*', or '/').
 * @throws   NumericLimitsException if the calculation exceeds long boundaries.
 * @throws   DivisionByZeroException if dividing by 0.
 * @throws   Exception as a generic fallback for unknown operators.
 */
void RPN::_calculate(const char op)
{
    long right = _stack.top(); _stack.pop();
    long left = _stack.top(); _stack.pop();

    switch(op)
    {
        case '+':
            if ((right > 0 && left > std::numeric_limits<long>::max() - right)
                || (right < 0 && left < std::numeric_limits<long>::min() - right))
                throw NumericLimitsException();
            _stack.push(left + right);
            break;

        case '-':
            if ((right < 0 && left > std::numeric_limits<long>::max() + right)
                || (right > 0 && left < std::numeric_limits<long>::min() + right))
                throw NumericLimitsException();
            _stack.push(left - right);
            break;

        case '*':
            if (right > 0)
            {
                if (left > std::numeric_limits<long>::max() / right
                    || left < std::numeric_limits<long>::min() / right)
                    throw NumericLimitsException();
            }
            else if (right == -1)
            {
                if (left == std::numeric_limits<long>::min())
                    throw NumericLimitsException();
            }
            else if (right < -1)
            {
                if (left < std::numeric_limits<long>::max() / right
                    || left > std::numeric_limits<long>::min() / right)
                    throw NumericLimitsException();
            }
            _stack.push(left * right);
            break;

        case '/':
            if (right == 0)
                throw DivisionByZeroException();
            if (left == std::numeric_limits<long>::min() && right == -1)
                throw NumericLimitsException();
            _stack.push(left / right);
            break;

        default:
            throw Exception();
            break;
    }
}

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn RPN::RPN(void)
 * @brief Default constructor for RPN.
 * @details Initializes an empty RPN calculator instance.
 */
RPN::RPN(void) {}

/**
 * @fn RPN::RPN(RPN const & other)
 * @brief Copy constructor for RPN.
 * @details Performs a deep copy of the internal stack data structure.
 * @param other The RPN instance to copy.
 */
RPN::RPN(RPN const & other) : _stack(other._stack) {}

/**
 * @fn RPN::~RPN(void)
 * @brief Destructor for RPN.
 * @details Safely destroys the object. STL stack memory is auto-managed.
 */
RPN::~RPN(void) {}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn RPN& RPN::operator=(RPN const & other)
 * @brief Copy assignment operator overload.
 * @details Safely replaces the internal stack with the one from 'other', 
 * guarding against self-assignment.
 * @param other The RPN object to assign from.
 * @return      A reference to the active object.
 */
RPN& RPN::operator=(RPN const & other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void RPN::processInput(std::string const & str)
 * @brief Parses the input string and processes the postfix notation tokens.
 * @details Safely iterates over the string using std::istringstream to handle 
 * whitespace delimitation. Converts single character tokens into numerical 
 * operands for the stack or triggers calculations for operators. Ensures 
 * strict stack state validation upon completion.
 * @param str The raw command-line string containing the RPN expression.
 * @throws    EmptyStringException, InvalidInputException, 
 * LackOfNumbersException, or LackOfOperatorsException based on strict state 
 * checks.
 */
void RPN::processInput(std::string const & str)
{
    if (str.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
        throw EmptyStringException();

    if (str.find_first_not_of(" \t\n\v\f\r0123456789+-*/") != std::string::npos)
        throw InvalidInputException();

    std::istringstream iss(str);
    std::string token;
    
    while(iss >> token)
    {
        if (token.length() != 1)
            throw InvalidInputException();

        char c = token[0];

        if (std::isdigit(static_cast<unsigned char>(c)))
            _stack.push(static_cast<long>(c - '0'));
        else if (c == '+' || c == '-' || c == '*' || c == '/')       
        {
            if (_stack.size() < 2)
                throw LackOfNumbersException();

            _calculate(c);
        }
        else
            throw InvalidInputException();
    }

    if (_stack.empty())
        throw LackOfNumbersException();

    if (_stack.size() > 1)
        throw LackOfOperatorsException();

    std::cout << _stack.top() << std::endl;
}

/* ========================================================================== */
/* EXCEPTIONS                                                                 */
/* ========================================================================== */

/**
 * @fn const char* RPN::Exception::what() const throw()
 * @brief Returns the generic error message.
 * @details Overrides std::exception::what() to provide a statically allocated 
 * error message acting as a generic fallback for polymorphic exception 
 * handling.
 * @return A C-style character string describing the error.
 */
const char* RPN::Exception::what() const throw()
{
    return ("encountered a generic error.");
}

/**
 * @fn const char* RPN::EmptyStringException::what() const throw()
 * @brief Returns the specific error message for empty strings.
 * @details Inherits from Exception to indicate the parser was given no data.
 * @return A C-style character string describing the error.
 */
const char* RPN::EmptyStringException::what() const throw()
{
    return ("string is empty.");
}

/**
 * @fn const char* RPN::InvalidInputException::what() const throw()
 * @brief Returns the specific error message for formatting violations.
 * @details Inherits from Exception to indicate forbidden characters or 
 * multi-digit numbers.
 * @return A C-style character string describing the error.
 */
const char* RPN::InvalidInputException::what() const throw()
{
    return ("invalid input format.");
}

/**
 * @fn const char* RPN::LackOfNumbersException::what() const throw()
 * @brief Returns the specific error message for insufficient operands.
 * @details Inherits from Exception to indicate stack underflow situations.
 * @return A C-style character string describing the error.
 */
const char* RPN::LackOfNumbersException::what() const throw()
{
    return ("lack of numbers to complete calculation.");
}

/**
 * @fn const char* RPN::LackOfOperatorsException::what() const throw()
 * @brief Returns the specific error message for incomplete equations.
 * @details Inherits from Exception to indicate leftover numbers on the stack.
 * @return A C-style character string describing the error.
 */
const char* RPN::LackOfOperatorsException::what() const throw()
{
    return ("lack of operators to perform calculation.");
}

/**
 * @fn const char* RPN::DivisionByZeroException::what() const throw()
 * @brief Returns the specific error message for division by zero.
 * @details Inherits from Exception to indicate mathematical impossibilities.
 * @return A C-style character string describing the error.
 */
const char* RPN::DivisionByZeroException::what() const throw()
{
    return ("division by zero.");
}

/**
 * @fn const char* RPN::NumericLimitsException::what() const throw()
 * @brief Returns the specific error message for arithmetic limits.
 * @details Inherits from Exception to indicate a prevented hardware overflow.
 * @return A C-style character string describing the error.
 */
const char* RPN::NumericLimitsException::what() const throw()
{
    return ("numeric limits exceeded.");
}
