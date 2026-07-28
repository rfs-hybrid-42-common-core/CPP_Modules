/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:12:40 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:08:27 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "HumanA.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <string>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn HumanA::HumanA(std::string const & name, Weapon& weapon)
 * @brief Constructor for the HumanA class.
 * @details Initializes the name and the weapon reference using a member 
 * initializer list, as references must be assigned upon creation. Prints a 
 * spawn message for debugging.
 * @param name   The constant reference string for the human's name.
 * @param weapon The reference to a valid Weapon object.
 */
HumanA::HumanA(std::string const & name, Weapon& weapon) : _name(name), _weapon(weapon)
{
    std::cout << _name << " is equipped with their " << _weapon.getType() << " to fight off the zombie horde" << std::endl;
}

/**
 * @fn HumanA::~HumanA(void)
 * @brief Destructor for the HumanA class.
 * @details Prints a thematic debugging message when the object is destroyed.
 */
HumanA::~HumanA(void)
{
    std::cout << _name << " fought bravely until they were bitten and got turned into a zombie" << std::endl;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & HumanA::getName(void) const
 * @brief Retrieves HumanA's name.
 * @return A constant reference to the name string.
 */
std::string const & HumanA::getName(void) const
{
    return _name;
}

/**
 * @fn Weapon const & HumanA::getWeapon(void) const
 * @brief Retrieves the weapon currently held by HumanA.
 * @return A constant reference to the Weapon object.
 */
Weapon const & HumanA::getWeapon(void) const
{
    return _weapon;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void HumanA::attack(void)
 * @brief Makes HumanA perform an attack.
 * @details Prints an attack message indicating the human's name and the 
 * specific weapon type they are currently using.
 */
void HumanA::attack(void)
{
    std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}
