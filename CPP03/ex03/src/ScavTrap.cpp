/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:59:17 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/31 14:18:36 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "ScavTrap.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn ScavTrap::ScavTrap(void)
 * @brief Default constructor for the ScavTrap class.
 * @details Calls the ClapTrap base constructor, then overrides the stats to 
 * 100 HP, 50 Energy, and 20 DPS. Prints a specific creation message.
 */
ScavTrap::ScavTrap(void) : ClapTrap("Scavtrap")
{
    _hp = 100;
    _energy = 50;
    _dps = 20;

    std::cout << getName() << ": Bow before your robot overlord!" << std::endl;
}

/**
 * @fn ScavTrap::ScavTrap(std::string const & name)
 * @brief Parameterized constructor for the ScavTrap class.
 * @details Calls the ClapTrap base constructor, then overrides the stats to 
 * 100 HP, 50 Energy, and 20 DPS. Prints a specific creation message.
 * @param name The name of the ScavTrap.
 */
ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name)
{
    _hp = 100;
    _energy = 50;
    _dps = 20;

    std::cout << getName() << ": Bow before your robot overlord!" << std::endl;
}

/**
 * @fn ScavTrap::ScavTrap(ScavTrap const & other)
 * @brief Copy constructor for the ScavTrap class.
 * @details Constructs a new ScavTrap object by invoking the ClapTrap copy 
 * constructor. Prints a specific creation message.
 * @param other The ScavTrap object to copy from.
 */
ScavTrap::ScavTrap(ScavTrap const & other) : ClapTrap(other)
{
    std::cout << getName() << ": Bow before your robot overlord!" << std::endl;
}

/**
 * @fn ScavTrap::~ScavTrap(void)
 * @brief Destructor for the ScavTrap class.
 * @details Cleans up the ScavTrap object and prints a specific destruction 
 * message.
 */
ScavTrap::~ScavTrap(void)
{
    std::cout << getName() << ": I'm too pretty to die!" << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn ScavTrap& ScavTrap::operator=(ScavTrap const & other)
 * @brief Copy assignment operator overload.
 * @details Calls the ClapTrap assignment operator to handle shared attribute 
 * assignment, protecting against self-assignment.
 * @param other The ScavTrap object to assign from.
 * @return      A reference to the newly assigned ScavTrap object.
 */
ScavTrap& ScavTrap::operator=(ScavTrap const & other)
{
	if (this != &other)
        ClapTrap::operator=(other);
	return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void ScavTrap::attack(const std::string& target)
 * @brief Attacks a specified target.
 * @details Consumes 1 energy point to attack. Overrides the ClapTrap attack 
 * message to clearly indicate that a ScavTrap is attacking.
 * @param target The name of the target being attacked.
 */
void ScavTrap::attack(const std::string& target)
{
    if (getHp() > 0 && getEnergy() > 0)
    {
        --_energy;
        std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getDps() << " points of damage!" << std::endl;
    }
    else if (getHp() <= 0)
        std::cout << "ScavTrap " << getName() << ": If only my chassis weren't made of recycled human body parts!" << std::endl;
    else
        std::cout << "ScavTrap " << getName() << ": Uh-oh... I think something's broken." << std::endl;
}

/**
 * @fn void ScavTrap::guardGate(void)
 * @brief Activates Gate keeper mode.
 * @details Prints a message confirming the ScavTrap is guarding the gate. 
 * Checks HP to ensure a dead ScavTrap cannot guard.
 */
void ScavTrap::guardGate(void)
{
    if (getHp() > 0)
        std::cout << getName() << " entered gate keeper mode!" << std::endl;
    else
        std::cout << getName() << ": PROTECT ME, SQUIRE!" << std::endl;
}
