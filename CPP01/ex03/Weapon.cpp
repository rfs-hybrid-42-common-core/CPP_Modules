/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:12:18 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:10:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Weapon.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Weapon::Weapon(std::string const & type)
 * @brief Constructor for the Weapon class.
 * @details Initializes the weapon's type. If an empty string is provided, 
 * it defaults the weapon type to "fists" to ensure valid combat behavior.
 * @param type The constant reference string defining the weapon's type.
 */
Weapon::Weapon(std::string const & type) : _type(type)
{
    if (_type.empty()) _type = "fists";
}

/**
 * @fn Weapon::~Weapon(void)
 * @brief Destructor for the Weapon class.
 * @details Cleans up the Weapon object.
 */
Weapon::~Weapon(void) {}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & Weapon::getType(void) const
 * @brief Retrieves the weapon's current type.
 * @details Returns a constant reference to the internal type string to prevent 
 * unintended modification while avoiding unnecessary memory copying.
 * @return A constant reference to the weapon's type string.
 */
std::string const & Weapon::getType(void) const
{
    return _type;
}

/* ========================================================================== */
/* SETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn void Weapon::setType(std::string const & type)
 * @brief Changes the weapon's type.
 * @details Replaces the current weapon type with a new one and prints a 
 * debugging message confirming the change.
 * @param type The new string type to assign to the weapon.
 */
void Weapon::setType(std::string const & type)
{
    std::cout << getType() << " replaced by " << type << std::endl;
    _type = type;
}
