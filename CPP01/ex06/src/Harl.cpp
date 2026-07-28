/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:36:36 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 04:06:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Harl.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Harl::Harl(void)
 * @brief Constructor for the Harl class.
 * @details Initializes a new Harl object. No specific setup required.
 */
Harl::Harl(void) {}

/**
 * @fn Harl::~Harl(void)
 * @brief Destructor for the Harl class.
 * @details Cleans up the Harl object. No dynamic memory to manage.
 */
Harl::~Harl(void) {}

/* ========================================================================== */
/* PRIVATE METHODS                                                            */
/* ========================================================================== */

/**
 * @fn void Harl::debug(void)
 * @brief Prints a debug level message.
 * @details Displays a message containing contextual information meant for 
 * problem diagnosis.
 */
void Harl::debug(void)
{
    std::cout << "[ DEBUG ]\nGoodbye norminette, it was not nice meeting you.\nFinally absolute chaos... I mean freedom.\n" << std::endl;
}

/**
 * @fn void Harl::info(void)
 * @brief Prints an info level message.
 * @details Displays a message containing extensive information helpful for 
 * tracing program execution.
 */
void Harl::info(void)
{
    std::cout << "[ INFO ]\nThere's no need to evalutate this project anymore.\nJust drop the 100 and lets get this over with.\n" << std::endl;
}

/**
 * @fn void Harl::warning(void)
 * @brief Prints a warning level message.
 * @details Displays a message indicating a potential issue in the system 
 * that can still be handled or ignored.
 */
void Harl::warning(void)
{
    std::cout << "[ WARNING ]\nThe decibel tracker is at it again.\nPlease smash it with a hammer.\n" << std::endl;
}

/**
 * @fn void Harl::error(void)
 * @brief Prints an error level message.
 * @details Displays a message indicating an unrecoverable error has occurred.
 */
void Harl::error(void)
{
    std::cout << "[ ERROR ]\nWater bottle detected on the table.\nYou've just earned yourself 2 hours of TIG. Boo...\n" << std::endl;
}

/**
 * @fn std::string Harl::trimWhitespaces(std::string const & str)
 * @brief Trims leading and trailing whitespaces from a string.
 * @details Scans the input string to find the first and last non-whitespace 
 * characters and returns the substring containing the actual content.
 * @param str The standard string to be trimmed.
 * @return    A newly constructed trimmed string or an empty string if the 
 * input contains only whitespaces.
 */
std::string Harl::trimWhitespaces(std::string const & str)
{
    size_t start = str.find_first_not_of(" \t\n\v\f\r");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t\n\v\f\r");

    return str.substr(start, end - start + 1);
}

/**
 * @fn int Harl::getLevelIndex(std::string const & level)
 * @brief Converts a string log level into an integer index.
 * @details Iterates through an array of valid log levels to find a match 
 * for the provided string, facilitating the use of a switch statement.
 * @param level The log level as a string (e.g., "DEBUG", "INFO").
 * @return      The integer index corresponding to the level (0 to 3), or -1 
 * if no match is found.
 */
int  Harl::getLevelIndex(std::string const & level)
{
    static std::string const levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; ++i)
    {
        if (level == levels[i])
            return i;
    }
    return -1;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Harl::complain(std::string level)
 * @brief Outputs Harl's complaints based on the provided level.
 * @details Leverages a switch statement with fall-through logic to display 
 * all messages from the specified severity level upwards.
 * @param level The minimum severity level to trigger complaints.
 */
void Harl::complain(std::string level)
{
    level = trimWhitespaces(level);

    switch(getLevelIndex(level))
    {
        case 0:
            debug();
            /* fallthrough */
        case 1:
            info();
            /* fallthrough */
        case 2:
            warning();
            /* fallthrough */
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about the Black Hole countdown again... ]" << std::endl;
            break;
    }
}
