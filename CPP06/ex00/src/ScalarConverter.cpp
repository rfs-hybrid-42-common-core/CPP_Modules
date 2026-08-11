/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:40:09 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/17 15:23:59 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "ScalarConverter.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>

/* ========================================================================== */
/* HELPER FUNCTIONS                                                           */
/* ========================================================================== */

/**
 * @fn static std::string trimWhitespaces(std::string const & str)
 * @brief Trims leading and trailing whitespaces from a string.
 * @details Scans the input string to find the first and last non-whitespace 
 * characters and returns the substring containing the actual content.
 * @param str The standard string to be trimmed.
 * @return    A newly constructed trimmed string or an empty string if the 
 * input contains only whitespaces.
 */
static std::string trimWhitespaces(std::string const & str)
{
    size_t start = str.find_first_not_of(" \t\n\v\f\r");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t\n\v\f\r");

    return str.substr(start, end - start + 1);
}

/**
 * @fn static void convertChar(std::string const & str)
 * @brief Parses, casts, and prints a character literal.
 * @details Extracts the target character (handling both bare and quoted 
 * forms), explicitly casts it to integer, float, and double formats, and 
 * outputs them.
 * @param str The string evaluated as a character literal.
 */
static void convertChar(std::string const & str)
{
    char c = str.length() == 1 ? str[0] : str[1];

    std::cout.precision(1);
    std::cout << std::fixed;
    if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c)
              << "\nfloat: " << static_cast<float>(c) << "f"
              << "\ndouble: " << static_cast<double>(c) << std::endl;

    std::cout.unsetf(std::ios_base::fixed);
    std::cout.precision(6);
}

/**
 * @fn static void convertPseudoLiteral(std::string const & str)
 * @brief Processes and prints edge-case pseudo-literals.
 * @details Directly outputs "impossible" for invalid character and integer 
 * conversions while appropriately formatting the pseudo-literal for 
 * floating-point and double outputs (e.g., "-inff", "nan", and unsigned "inf").
 * @param str The string representing a matched pseudo-literal.
 */
static void convertPseudoLiteral(std::string const & str)
{
    std::cout << "char: impossible"
              << "\nint: impossible";
    if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
    {
        std::cout << "\nfloat: " << str
                  << "\ndouble: " << str.substr(0, str.length() - 1) << std::endl;
    }
    else
    {
        std::cout << "\nfloat: " << str << "f"
                  << "\ndouble: " << str << std::endl;
    }
}

/**
 * @fn static void convertNumber(std::string const & str)
 * @brief Parses, validates, and explicitly casts standard numeric literals.
 * @details Utilizes std::strtod to parse the numeric value and verifies input 
 * integrity using endptr and errno. Converts the parsed double value to char, 
 * int, and float while strictly adhering to std::numeric_limits boundaries.
 * @param str The clean, trimmed string representation of the numeric literal.
 */
static void convertNumber(std::string const & str)
{
    errno = 0;

    char *endptr;
    double val = std::strtod(str.c_str(), &endptr);

    if (*endptr != '\0' && (*endptr != 'f' || *(endptr + 1) != '\0'))
    {
        std::cerr << "Impossible conversion: invalid input detected." << std::endl;
        return;
    }

    if (errno == ERANGE)
    {
        std::cerr << "Impossible conversion: number out of range." << std::endl;
        return;
    }

    if (val <= -1 || val >= static_cast<double>(std::numeric_limits<char>::max()) + 1.0)
        std::cout << "char: impossible";
    else if (!std::isprint(static_cast<unsigned char>(static_cast<char>(val))))
        std::cout << "char: Non displayable";
    else
        std::cout << "char: '" << static_cast<char>(val) << "'";

    if (val <= static_cast<double>(std::numeric_limits<int>::min()) - 1.0 
        || val >= static_cast<double>(std::numeric_limits<int>::max()) + 1.0)
        std::cout << "\nint: impossible";
    else
        std::cout << "\nint: " << static_cast<int>(val);

    if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max())
        std::cout << "\nfloat: impossible";
    else
    {
        if (val == std::floor(val))
        {
            std::cout.precision(1);
            std::cout << std::fixed;
        }
        std::cout << "\nfloat: " << static_cast<float>(val) << "f";
    }        

    std::cout << "\ndouble: " << val << std::endl;

    std::cout.unsetf(std::ios_base::fixed);
    std::cout.precision(6);
}

/**
 * @fn static bool isChar(std::string const & str)
 * @brief Determines if the input qualifies as a character literal.
 * @details Checks whether the string is either a single, non-digit bare 
 * character or a single character properly enclosed in single quotes.
 * @param str The raw, untrimmed input string.
 * @return    True if the format matches a character literal, false otherwise.
 */
static bool isChar(std::string const & str)
{
    return ((str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
        || (str.length() == 3 && str[0] == '\'' && str[2] == '\''));
}

/**
 * @fn static bool isPseudoLiteral(std::string const & str)
 * @brief Determines if the input matches any recognized pseudo-literals.
 * @details Compares the input against a static array of signed and unsigned 
 * NaN and Infinity representations to prevent standard library parsing 
 * collisions.
 * @param str The trimmed input string.
 * @return    True if a match is found, false otherwise.
 */
static bool isPseudoLiteral(std::string const & str)
{
    static std::string const pseudoLiterals[8] = {
        "-inff", "+inff", "inff", "nanf",
        "-inf" , "+inf" , "inf", "nan"
    };
    for (int i = 0; i < 8; ++i)
    {
        if (str == pseudoLiterals[i])
            return true;
    }
    return false;
}

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn ScalarConverter::ScalarConverter(void)
 * @brief Default constructor for the ScalarConverter class.
 * @details Kept private to enforce a purely static utility class structure.
 */
ScalarConverter::ScalarConverter(void) {}

/**
 * @fn ScalarConverter::ScalarConverter(ScalarConverter const & other)
 * @brief Copy constructor for the ScalarConverter class.
 * @details Kept private and unused to prevent instantiation.
 * @param other The ScalarConverter object to copy (unused).
 */
ScalarConverter::ScalarConverter(ScalarConverter const & other)
{
    (void)other;
}

/**
 * @fn ScalarConverter::~ScalarConverter(void)
 * @brief Destructor for the ScalarConverter class.
 * @details Kept private to prevent instantiation.
 */
ScalarConverter::~ScalarConverter(void) {}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn ScalarConverter& ScalarConverter::operator=(ScalarConverter const & other)
 * @brief Copy assignment operator overload.
 * @details Kept private and unused to prevent instantiation.
 * @param other The ScalarConverter object to assign from (unused).
 * @return      A reference to the current object.
 */
ScalarConverter& ScalarConverter::operator=(ScalarConverter const & other)
{
    (void)other;
    return *this;
}

/* ========================================================================== */
/* STATIC PUBLIC METHODS                                                      */
/* ========================================================================== */

/**
 * @fn void ScalarConverter::convert(std::string const & str)
 * @brief Core execution funnel for literal parsing and conversion.
 * @details Evaluates characters prior to trimming to preserve raw whitespace, 
 * scrubs formatting, performs a secondary check for padded character literals, 
 * intercepts pseudo-literals, and evaluates numeric boundaries.
 * @param str The string representation of the C++ literal to be converted.
 */
void ScalarConverter::convert(std::string const & str)
{
    if (isChar(str))
    {
        convertChar(str);
        return;
    }

    std::string const trimmedStr = trimWhitespaces(str);
    if (trimmedStr.empty())
        std::cerr << "Impossible conversion: empty string detected." << std::endl;
    else if (isChar(trimmedStr))
        convertChar(trimmedStr);
    else if (isPseudoLiteral(trimmedStr))
        convertPseudoLiteral(trimmedStr);
    else
        convertNumber(trimmedStr);
}
