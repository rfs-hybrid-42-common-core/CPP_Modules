/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:36:12 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/28 22:54:49 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Harl.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @brief Main entry point of the harlFilter program.
 * @details Evaluates the provided command-line argument to filter Harl's 
 * complaints, displaying all messages from the specified level and above.
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return     EXIT_SUCCESS upon successful execution, or EXIT_FAILURE if the 
 * wrong number of arguments is provided.
 */
int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return EXIT_FAILURE;
	}

	harl.complain(argv[1]);
	return EXIT_SUCCESS;
}
