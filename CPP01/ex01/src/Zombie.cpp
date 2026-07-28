/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:18:46 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:06:04 by maaugust         ###   ########.fr       */
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
 * @fn Zombie::Zombie(void)
 * @brief Default constructor for the Zombie class.
 * @details Required for instantiating an array of Zombies. The name is left 
 * empty initially and will be populated via a setter function.
 */
Zombie::Zombie(void) {}

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
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & Zombie::getName(void) const
 * @brief Retrieves the zombie's name.
 * @details Provides read-only access to the private _name attribute. 
 * Returning the string by constant reference ensures that no unnecessary 
 * memory copying occurs during the retrieval process.
 * @return A constant reference to the zombie's name string.
 */
std::string const & Zombie::getName(void) const
{
    return _name;
}

/* ========================================================================== */
/* SETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn void Zombie::setName(std::string const & name)
 * @brief Sets or updates the zombie's name.
 * @details Updates the private _name attribute. This is particularly 
 * necessary when allocating an array of zombies via new[], as only the 
 * default constructor is called, requiring the name to be set post-creation.
 * @param name The new name to assign to the zombie.
 */
void Zombie::setName(std::string const & name)
{
    _name = name;
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
