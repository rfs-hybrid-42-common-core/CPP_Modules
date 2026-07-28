/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:27:35 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/29 02:06:38 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Zombie.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <string>
#include <sstream>
#include <cstddef>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn static std::string const intToString(int number)
 * @brief Helper function to convert an integer to a string.
 * @details Uses std::stringstream to format the integer, providing a C++98 
 * compliant alternative to std::to_string.
 * @param number The integer to convert.
 * @return       The formatted string representation of the integer.
 */
static std::string const intToString(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

/**
 * @fn Zombie* zombieHorde(int N, std::string name)
 * @brief Creates a horde of N zombies in a single allocation.
 * @details Allocates an array of N Zombie objects dynamically. Iterates 
 * through the array to assign a sequenced name to each zombie and prints a 
 * creation message.
 * @param N    The number of zombies to create.
 * @param name The base name to give to each zombie in the horde.
 * @return     A pointer to the first zombie in the dynamically allocated 
 * array, or NULL if N is 0 or negative.
 */
Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0) return NULL;
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
    {
        horde[i].setName(name.empty() ? "Zombie " + intToString(i + 1) : name + " " + intToString(i + 1));
        std::cout << horde[i].getName() << " has risen from his grave and is hungry for human brains." << std::endl;
    }
    return horde;
}
