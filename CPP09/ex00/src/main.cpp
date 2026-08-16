/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:44:40 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/24 03:50:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "BitcoinExchange.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(int argc, char **argv)
 * @brief The main execution point for testing the BitcoinExchange class.
 * @details Validates the argument count before attempting to instantiate the 
 * exchange parser. Wraps execution in a try-catch block to gracefully handle 
 * fatal database initialization or file opening errors.
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the arguments.
 * @return     EXIT_SUCCESS upon successful completion, EXIT_FAILURE otherwise.
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        if (argc == 1)
            std::cerr << "Error: could not open file." << std::endl;
        else
        {
            std::cerr << "Error: Too many arguments provided." << std::endl;
            std::cerr << "Usage: ./btc <inputFile>" << std::endl;
            std::cerr << "Example: ./btc input.txt" << std::endl;
        }
        return EXIT_FAILURE;
    }

    try 
    {
        BitcoinExchange btc;
        std::string filename = argv[1];
        btc.processInput(filename);
    }
    catch (BitcoinExchange::Exception const & e)
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
