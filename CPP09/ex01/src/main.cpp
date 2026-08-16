/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:46:48 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/24 03:50:44 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "RPN.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(int argc, char **argv)
 * @brief The main execution point for testing the RPN class.
 * @details Validates the command-line argument count before passing the string 
 * to the RPN parser. Wraps the execution in a try-catch block to gracefully 
 * intercept and print all custom parsing and arithmetic exceptions.
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the arguments.
 * @return     EXIT_SUCCESS upon successful evaluation, EXIT_FAILURE upon 
 * errors.
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./RPN <mathematical expression>" << std::endl;
        std::cerr << "Example: ./RPN \"8 9 * 9 - 9 - 9 - 4 1 + *\"" << std::endl;
        std::cerr << "Note: The expression must be enclosed in quotes." << std::endl;
        return EXIT_FAILURE;
    }

    try 
    {
        RPN rpn;
        std::string str = argv[1];
        rpn.processInput(str);
    }
    catch (RPN::Exception const & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
