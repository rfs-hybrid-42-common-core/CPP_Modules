/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:54:48 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/31 15:02:17 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "DiamondTrap.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn DiamondTrap::DiamondTrap(void)
 * @brief Default constructor for DiamondTrap.
 * @details Initializes the virtual base ClapTrap with the "_clap_name" suffix, 
 * sets the local shadow _name, and manually applies the hybrid stats.
 */
DiamondTrap::DiamondTrap(void) :
    ClapTrap("Diamondtrap_clap_name"),
    ScavTrap("Diamondtrap"),
    FragTrap("Diamondtrap"),
    _name("Diamondtrap")
{
    _hp = 100;
    _energy = 50;
    _dps = 30;

    std::cout << _name << ": Who's a badass robot? This guy!" << std::endl;
}

/**
 * @fn DiamondTrap::DiamondTrap(std::string const & name)
 * @brief Parameterized constructor for DiamondTrap.
 * @details Initializes the virtual base ClapTrap with the "_clap_name" suffix, 
 * sets the local shadow _name to the parameter, and applies the hybrid stats.
 * @param name The base name for the DiamondTrap.
 */
DiamondTrap::DiamondTrap(std::string const & name) :
    ClapTrap(name + "_clap_name"),
    ScavTrap(name),
    FragTrap(name),
    _name(name)
{
    _hp = 100;
    _energy = 50;
    _dps = 30;

    std::cout << _name << ": Who's a badass robot? This guy!" << std::endl;
}

/**
 * @fn DiamondTrap::DiamondTrap(DiamondTrap const & other)
 * @brief Copy constructor for DiamondTrap.
 * @details Calls the copy constructors of all parent classes and copies the 
 * local shadow _name.
 * @param other The DiamondTrap to copy from.
 */
DiamondTrap::DiamondTrap(DiamondTrap const & other) :
    ClapTrap(other),
    ScavTrap(other),
    FragTrap(other),
    _name(other._name)
{
    std::cout << _name << ": Who's a badass robot? This guy!" << std::endl;
}

/**
 * @fn DiamondTrap::~DiamondTrap(void)
 * @brief Destructor for the DiamondTrap class.
 * @details Cleans up the DiamondTrap object and prints a specific destruction 
 * message. Due to virtual inheritance, the base ClapTrap destructor will 
 * only be called once at the very end of the destruction chain.
 */
DiamondTrap::~DiamondTrap(void)
{
    std::cout << _name << ": Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn DiamondTrap& DiamondTrap::operator=(DiamondTrap const & other)
 * @brief Copy assignment operator overload.
 * @details Calls the base ClapTrap assignment operator to handle shared 
 * attribute assignment, protecting against self-assignment, and then 
 * copies the localized shadow _name.
 * @param other The DiamondTrap object to assign from.
 * @return      A reference to the newly assigned DiamondTrap object.
 */
DiamondTrap& DiamondTrap::operator=(DiamondTrap const & other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void DiamondTrap::whoAmI(void)
 * @brief Displays the DiamondTrap's dual identity.
 * @details Prints a message revealing both the local shadow _name and the 
 * ClapTrap base name (which contains the "_clap_name" suffix).
 */
void DiamondTrap::whoAmI(void)
{
    std::cout << "Allow me to introduce myself - I am a " << _name
              << " steward bot but my friends call me " << getName()
              << "! Or they would, if any of them were still alive. Or had existed in the first place!" << std::endl;
}
