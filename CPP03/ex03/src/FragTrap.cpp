/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 01:40:34 by maaugust          #+#    #+#             */
/*   Updated: 2026/09/17 18:49:29 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "FragTrap.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn FragTrap::FragTrap(void)
 * @brief Default constructor for the FragTrap class.
 * @details Calls the ClapTrap base constructor, then overrides the stats to 
 * 100 HP, 100 Energy, and 30 DPS. Prints a specific creation message.
 */
FragTrap::FragTrap(void) : ClapTrap("Fragtrap")
{
    _hp = 100;
    _energy = 100;
    _dps = 30;

    std::cout << getName() << ": I'm a tornado of death and adorable charm!" << std::endl;
}

/**
 * @fn FragTrap::FragTrap(std::string const & name)
 * @brief Parameterized constructor for the FragTrap class.
 * @details Calls the ClapTrap base constructor, then overrides the stats to 
 * 100 HP, 100 Energy, and 30 DPS. Prints a specific creation message.
 * @param name The name of the FragTrap.
 */
FragTrap::FragTrap(std::string const & name) : ClapTrap(name)
{
    _hp = 100;
    _energy = 100;
    _dps = 30;

    std::cout << getName() << ": I'm a tornado of death and adorable charm!" << std::endl;
}

/**
 * @fn FragTrap::FragTrap(FragTrap const & other)
 * @brief Copy constructor for the FragTrap class.
 * @details Constructs a new FragTrap object by invoking the ClapTrap copy 
 * constructor. Prints a specific creation message.
 * @param other The FragTrap object to copy from.
 */
FragTrap::FragTrap(FragTrap const & other) : ClapTrap(other)
{
    std::cout << getName() << ": I'm a tornado of death and adorable charm!" << std::endl;
}

/**
 * @fn FragTrap::~FragTrap(void)
 * @brief Destructor for the FragTrap class.
 * @details Cleans up the FragTrap object and prints a specific destruction 
 * message.
 */
FragTrap::~FragTrap(void)
{
    std::cout << getName() << ": My robotic flesh! AAHH!" << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn FragTrap& FragTrap::operator=(FragTrap const & other)
 * @brief Copy assignment operator overload.
 * @details Calls the ClapTrap assignment operator to handle shared attribute 
 * assignment, protecting against self-assignment.
 * @param other The FragTrap object to assign from.
 * @return      A reference to the newly assigned FragTrap object.
 */
FragTrap& FragTrap::operator=(FragTrap const & other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void FragTrap::highFivesGuys(void)
 * @brief Requests a high-five.
 * @details Prints a positive high-five request to the standard output. 
 * Checks HP to ensure a dead FragTrap cannot request high-fives.
 */
void FragTrap::highFivesGuys(void)
{
    if (getHp() > 0)
        std::cout << getName() << ": High five!... Anybody?... No?" << std::endl;
    else
        std::cout << getName() << ": I can't feel my fingers! Gah! I don't have any fingers!" << std::endl;
}
