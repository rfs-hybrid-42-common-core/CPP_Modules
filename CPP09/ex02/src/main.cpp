/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:48:33 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/24 03:28:30 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "PmergeMe.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(int argc, char **argv)
 * @brief The main execution point for testing the PmergeMe sorting algorithm.
 * @details Validates the minimum argument count before passing raw inputs into 
 * the PmergeMe processor pipeline. Uses a standard try-catch architecture to 
 * catch and format deep validation exceptions gracefully without crashing.
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the input sequence.
 * @return     EXIT_SUCCESS upon successful benchmark completion, EXIT_FAILURE 
 * otherwise.
 */
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No numerical sequence provided." << std::endl;
        std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
        std::cerr << "Example: ./PmergeMe 3 5 9 7 4" << std::endl;
        return EXIT_FAILURE;
    }

    try 
    {
        PmergeMe pmergeMe;
        pmergeMe.processInput(argv + 1);
    }
    catch (PmergeMe::Exception const & e)
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
