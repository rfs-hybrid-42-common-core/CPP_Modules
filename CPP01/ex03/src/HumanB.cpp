/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:12:53 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:08:49 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "HumanB.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <string>
#include <cstddef>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn HumanB::HumanB(std::string const & name)
 * @brief Constructor for the HumanB class.
 * @details Initializes the name and sets the weapon pointer to NULL, as 
 * HumanB is not guaranteed to be armed upon creation. Prints a spawn message.
 * @param name The constant reference string for the human's name.
 */
HumanB::HumanB(std::string const & name) : _name(name), _weapon(NULL)
{
    std::cout << _name << " is equipped with their fists to fight off the zombie horde" << std::endl;
}

/**
 * @fn HumanB::~HumanB(void)
 * @brief Destructor for the HumanB class.
 * @details Prints a thematic debugging message when the object is destroyed.
 */
HumanB::~HumanB(void)
{
    std::cout << _name << " fought bravely until they were bitten and got turned into a zombie" << std::endl;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & HumanB::getName(void) const
 * @brief Retrieves HumanB's name.
 * @return A constant reference to the name string.
 */
std::string const & HumanB::getName(void) const
{
    return _name;
}

/**
 * @fn Weapon const * HumanB::getWeapon(void) const
 * @brief Retrieves the pointer to the weapon currently held by HumanB.
 * @return A constant pointer to the Weapon object, or NULL if unarmed.
 */
Weapon const * HumanB::getWeapon(void) const
{
    return _weapon;
}

/* ========================================================================== */
/* SETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn void HumanB::setWeapon(Weapon& weapon)
 * @brief Equips HumanB with a weapon.
 * @details Takes a reference to a Weapon and assigns its memory address to 
 * the internal _weapon pointer.
 * @param weapon The reference to the Weapon object to be equipped.
 */
void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void HumanB::attack(void)
 * @brief Makes HumanB perform an attack.
 * @details Checks if the human is armed (pointer is not NULL). If armed, 
 * prints an attack message with the weapon type. If unarmed, prints a default 
 * fist attack message.
 */
void HumanB::attack(void)
{
    if (_weapon == NULL)
        std::cout << getName() << " attacks with their fists" << std::endl;
    else
        std::cout << getName() << " attacks with their " << getWeapon()->getType() << std::endl;
}
