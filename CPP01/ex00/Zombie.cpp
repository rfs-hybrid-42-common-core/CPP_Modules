/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:18:46 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:04:33 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Zombie.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Zombie::Zombie(std::string const & name)
 * @brief Constructor for the Zombie class.
 * @details Initializes the zombie's name using a member initializer list. If 
 * the provided string is empty, the name defaults to "Zombie". It also prints 
 * a creation message for debugging purposes.
 * @param name The constant reference string to set as the zombie's name.
 */
Zombie::Zombie(std::string const & name) : _name(name.empty() ? "Zombie" :name)
{
    std::cout << _name << " has risen from his grave and is hungry for human brains." << std::endl;
}

/**
 * @fn Zombie::~Zombie(void)
 * @brief Destructor for the Zombie class.
 * @details Destroys the zombie and prints a debugging message containing the 
 * zombie's name to track when it goes out of scope or is deleted.
 */
Zombie::~Zombie(void)
{
    std::cout << _name << "'s belly is full of human brains and went back to sleep." << std::endl;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Zombie::announce(void)
 * @brief Makes the zombie announce itself.
 * @details Prints the zombie's name followed by a specific string format: 
 * "<name>: BraiiiiiiinnnzzzZ...".
 */
void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
