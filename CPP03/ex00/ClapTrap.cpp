/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:55:50 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/31 03:06:12 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "ClapTrap.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn ClapTrap::ClapTrap(void)
 * @brief Default constructor for the ClapTrap class.
 * @details Initializes a ClapTrap with a default name, 10 HP, 10 Energy, 
 * and 0 Attack Damage. Prints a creation message.
 */
ClapTrap::ClapTrap(void) : _name("Claptrap"), _hp(10), _energy(10), _dps(0)
{
    std::cout << getName() << ": Ha ha ha! I LIVE!" << std::endl;
}

/**
 * @fn ClapTrap::ClapTrap(std::string const & name)
 * @brief Parameterized constructor for the ClapTrap class.
 * @details Initializes a ClapTrap with the provided name, 10 HP, 10 Energy, 
 * and 0 Attack Damage. Prints a creation message.
 * @param name The name of the ClapTrap.
 */
ClapTrap::ClapTrap(std::string const & name) : _name(name), _hp(10), _energy(10), _dps(0)
{
    std::cout << getName() << ": Ha ha ha! I LIVE!" << std::endl;
}

/**
 * @fn ClapTrap::ClapTrap(ClapTrap const & other)
 * @brief Copy constructor for the ClapTrap class.
 * @details Constructs a new ClapTrap object as a copy of an existing one by 
 * copying its name, HP, energy, and attack damage.
 * @param other The ClapTrap object to copy from.
 */
ClapTrap::ClapTrap(ClapTrap const & other) : _name(other.getName()), _hp(other.getHp()), _energy(other.getEnergy()), _dps(other.getDps())
{
    std::cout << getName() << ": Ha ha ha! I LIVE!" << std::endl;
}

/**
 * @fn ClapTrap::~ClapTrap(void)
 * @brief Destructor for the ClapTrap class.
 * @details Cleans up the ClapTrap object and prints a destruction message.
 */
ClapTrap::~ClapTrap(void)
{
    std::cout << getName() << ": I'll die the way I lived: annoying!" << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn ClapTrap& ClapTrap::operator=(ClapTrap const & other)
 * @brief Copy assignment operator overload.
 * @details Assigns the attributes from one ClapTrap object to another, 
 * protecting against self-assignment.
 * @param other The ClapTrap object to assign from.
 * @return      A reference to the newly assigned ClapTrap object.
 */
ClapTrap& ClapTrap::operator=(ClapTrap const & other)
{
    if (this != &other)
    {
        _name = other.getName();
        _hp = other.getHp();
        _energy = other.getEnergy();
        _dps = other.getDps();
    }
    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & ClapTrap::getName(void) const
 * @brief Retrieves the name of the ClapTrap.
 * @details Provides read-only access to the internal _name attribute.
 * @return A constant reference to the string representing the name.
 */
std::string const & ClapTrap::getName(void) const
{
    return _name;
}

/**
 * @fn int ClapTrap::getHp(void) const
 * @brief Retrieves the current hit points (HP) of the ClapTrap.
 * @details Provides read-only access to the internal _hp attribute.
 * @return The integer value representing current health.
 */
int ClapTrap::getHp(void) const
{
    return _hp;
}

/**
 * @fn int ClapTrap::getEnergy(void) const
 * @brief Retrieves the current energy points of the ClapTrap.
 * @details Provides read-only access to the internal _energy attribute.
 * @return The integer value representing current energy.
 */
int ClapTrap::getEnergy(void) const
{
    return _energy;
}

/**
 * @fn int ClapTrap::getDps(void) const
 * @brief Retrieves the attack damage (DPS) of the ClapTrap.
 * @details Provides read-only access to the internal _dps attribute.
 * @return The integer value representing attack damage.
 */
int ClapTrap::getDps(void) const
{
    return _dps;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void ClapTrap::attack(const std::string& target)
 * @brief Attacks a specified target.
 * @details Consumes 1 energy point to attack. If the ClapTrap is out of HP 
 * or energy, it prints a specific failure message instead of attacking.
 * @param target The name of the target being attacked.
 */
void ClapTrap::attack(const std::string& target)
{
    if (getHp() > 0 && getEnergy() > 0)
    {
        --_energy;
        std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getDps() << " points of damage!" << std::endl;
    }
    else if (getHp() <= 0)
        std::cout << "ClapTrap " << getName() << ": If only my chassis weren't made of recycled human body parts!" << std::endl;
    else
        std::cout << "ClapTrap " << getName() << ": Uh-oh... I think something's broken." << std::endl;
}

/**
 * @fn void ClapTrap::takeDamage(unsigned int amount)
 * @brief Causes the ClapTrap to take damage.
 * @details Reduces the ClapTrap's HP by the specified amount. Prints a 
 * standard message, and a special message if HP drops to or below 0. 
 * If already dead, it complains about being hit while down.
 * @param amount The amount of damage to take.
 */
void ClapTrap::takeDamage(unsigned int amount)
{
    if (getHp() > 0)
    {
        _hp -= amount;
        std::cout << getName() << " was hit and lost " << amount << " health points!" << std::endl;
        if (getHp() <= 0)
            std::cout << getName() << ": No, nononono NO!" << std::endl;
    }
    else
        std::cout << getName() << ": This is REALLY bad for my warranty!" << std::endl;
}

/**
 * @fn void ClapTrap::beRepaired(unsigned int amount)
 * @brief Repairs the ClapTrap.
 * @details Consumes 1 energy point to restore the specified amount of HP. 
 * If the ClapTrap has 0 HP or 0 Energy, it prints a relevant failure message.
 * @param amount The amount of HP to restore.
 */
void ClapTrap::beRepaired(unsigned int amount)
{
    if (getHp() > 0 && getEnergy() > 0)
    {
        --_energy;
        _hp += amount;
        std::cout << getName() << " has begun repairs and restored " << amount << " health points!" << std::endl;
        if (getEnergy() <= 0)
            std::cout << getName() << ": My systems are... probably fine." << std::endl;
    }
    else if (getHp() <= 0)
        std::cout << getName() << ": My diagnostic program is diagnosing... more problems!" << std::endl;
    else
        std::cout << getName() << ": System failure! This is not ideal!" << std::endl;
}
