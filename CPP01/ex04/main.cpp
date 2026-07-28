/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 02:45:27 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/28 05:56:56 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Replacer.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn static bool validInputs(int argc, char **argv)
 * @brief Validates the command-line arguments.
 * @details Checks if exactly 3 arguments were provided (filename, s1, s2). 
 * Also verifies that the search string (s1) is not empty, preventing infinite 
 * loops or meaningless string parsing.
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return     True if arguments are valid, false otherwise.
 */
static bool validInputs(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return false;
    }
    if (!*argv[2])
    {
        std::cerr << "No string to be replaced was found" << std::endl;
        return false;
    }
    return true;
}

/**
 * @fn int main(int argc, char **argv)
 * @brief Entry point of the program.
 * @details Validates inputs and delegates the core string replacement logic 
 * to the Replacer class.
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return EXIT_SUCCESS upon successful execution, or EXIT_FAILURE if 
 * arguments are invalid or file operations fail.
 */
int main(int argc, char **argv)
{
    if (!validInputs(argc, argv)) return EXIT_FAILURE;

    Replacer replacer(argv[1]);
    if (!replacer.replace(argv[2], argv[3])) return EXIT_FAILURE;
        
    return EXIT_SUCCESS;
}
