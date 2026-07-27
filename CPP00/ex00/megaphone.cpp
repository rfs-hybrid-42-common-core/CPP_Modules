/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:38:49 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/28 15:03:49 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(int argc, char **argv)
 * @brief The main execution point of the megaphone program.
 * @details Iterates through the provided command-line arguments, converting 
 * each character to uppercase, and prints the concatenated result to the 
 * standard output. If no arguments are provided, it outputs a predefined 
 * feedback noise message.
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of C-style strings representing the command-line 
 * arguments.
 * @return     EXIT_SUCCESS upon successful execution.
 */
int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            std::string str = argv[i];
            size_t len = str.length();
            for (size_t j = 0; j < len; ++j)
                std::cout << static_cast<char>(std::toupper(str[j]));
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
