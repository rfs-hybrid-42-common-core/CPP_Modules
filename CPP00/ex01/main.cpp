/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:21:46 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:53:38 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "PhoneBook.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point of the application.
 * @details Instantiates the PhoneBook class and launches the main application 
 * loop. Returns an exit status based on how the application terminates.
 * @return EXIT_SUCCESS upon normal exit, EXIT_FAILURE if a critical error 
 * occurs.
 */
int main(void)
{
    PhoneBook phoneBook;
    return phoneBook.executePhoneBook() ? EXIT_SUCCESS : EXIT_FAILURE;
}
