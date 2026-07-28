/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:36:12 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/28 23:05:56 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Harl.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief Entry point of the program.
 * @details Instantiates a Harl object and tests the complain method by 
 * passing it all available log levels (DEBUG, INFO, WARNING, ERROR), as well 
 * as an unknown level to verify the fallback logic.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("  DEBUG  ");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("UNKNOWN");

	return EXIT_SUCCESS;
}
