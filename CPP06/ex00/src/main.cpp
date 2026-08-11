/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 00:53:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/12 01:22:06 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "ScalarConverter.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(int argc, char **argv)
 * @brief The main execution point for the ScalarConverter program.
 * @details Verifies the argument count and passes the provided literal string 
 * argument to the ScalarConverter::convert() static utility.
 * @param argc The total count of command-line arguments.
 * @param argv An array containing the command-line argument strings.
 * @return     EXIT_SUCCESS on standard execution, or EXIT_FAILURE if argument 
 * constraints are not met.
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Invalid number of arguments.\n"
                  << "Usage: ./scalarConverter <string>" << std::endl;
        return EXIT_FAILURE;
    }

    ScalarConverter::convert(argv[1]);
    return EXIT_SUCCESS;
}
