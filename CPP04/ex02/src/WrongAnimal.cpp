/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 22:05:25 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 16:00:17 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "WrongAnimal.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn WrongAnimal::WrongAnimal(void)
 * @brief Default constructor for the WrongAnimal class.
 * @details Initializes the _type attribute to "Unknown" and outputs a highly 
 * suspicious creation message.
 */
WrongAnimal::WrongAnimal(void) : _type("Unknown")
{
    std::cout << "A highly suspicious " << getType() << " has infiltrated the family." << std::endl;
}

/**
 * @fn WrongAnimal::WrongAnimal(std::string const & type)
 * @brief Parameterized constructor for the WrongAnimal class.
 * @details Initializes the _type attribute with the provided string and 
 * outputs a highly suspicious creation message.
 * @param type The type of the wrong animal.
 */
WrongAnimal::WrongAnimal(std::string const & type) : _type(type)
{
    std::cout << "A highly suspicious " << getType() << " has infiltrated the family." << std::endl;
}

/**
 * @fn WrongAnimal::WrongAnimal(WrongAnimal const & other)
 * @brief Copy constructor for the WrongAnimal class.
 * @details Constructs a new WrongAnimal object as a copy of an existing one 
 * by copying the _type attribute.
 * @param other The WrongAnimal object to copy from.
 */
WrongAnimal::WrongAnimal(WrongAnimal const & other) : _type(other.getType())
{
    std::cout << "Another highly suspicious " << getType() << " has infiltrated the family." << std::endl;
}

/**
 * @fn WrongAnimal::~WrongAnimal(void)
 * @brief Destructor for the WrongAnimal class.
 * @details Cleans up the WrongAnimal object and outputs an eviction message.
 */
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "The " << getType() << " has been caught and evicted." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn WrongAnimal& WrongAnimal::operator=(WrongAnimal const & other)
 * @brief Copy assignment operator overload.
 * @details Assigns the _type attribute from one WrongAnimal object to another, 
 * strictly protecting against self-assignment.
 * @param other The WrongAnimal object to assign from.
 * @return      A reference to the newly assigned WrongAnimal object.
 */
WrongAnimal& WrongAnimal::operator=(WrongAnimal const & other)
{
    if (this != &other)
        _type = other.getType();
    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & WrongAnimal::getType(void) const
 * @brief Retrieves the type of the wrong animal.
 * @details Provides read-only access to the internal _type attribute.
 * @return A constant reference to the _type string.
 */
std::string const & WrongAnimal::getType(void) const
{
    return _type;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void WrongAnimal::makeSound(void) const
 * @brief Prints the sound the wrong animal makes.
 * @details Crucially, this method is NOT declared as virtual. This means it 
 * will be bound statically at compile-time when called through a base pointer, 
 * preventing derived classes from properly overriding it dynamically.
 */
void WrongAnimal::makeSound(void) const
{
    std::cout << "* Bizarre, otherworldly screeching *" << std::endl;
}
