/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:43:10 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 15:59:58 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Animal.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Animal::Animal(void)
 * @brief Default constructor for the Animal class.
 * @details Initializes the _type attribute to "Unknown" and outputs a specific 
 * creation message to the standard output.
 */
Animal::Animal(void) : _type("Unknown")
{
    std::cout << "A cute " << getType() << " has been adopted by a loving family." << std::endl;
}

/**
 * @fn Animal::Animal(std::string const & type)
 * @brief Parameterized constructor for the Animal class.
 * @details Initializes the _type attribute with the provided string and 
 * outputs a specific creation message to the standard output.
 * @param type The type of the animal.
 */
Animal::Animal(std::string const & type) : _type(type)
{
    std::cout << "A cute " << getType() << " has been adopted by a loving family." << std::endl;
}

/**
 * @fn Animal::Animal(Animal const & other)
 * @brief Copy constructor for the Animal class.
 * @details Constructs a new Animal object as a copy of an existing one by 
 * copying the _type attribute, and outputs a specific creation message.
 * @param other The Animal object to copy from.
 */
Animal::Animal(Animal const & other) : _type(other.getType())
{
    std::cout << "Another cute " << getType() << " has been adopted by a loving family." << std::endl;
}

/**
 * @fn Animal::~Animal(void)
 * @brief Destructor for the Animal class.
 * @details Declared as virtual to ensure proper cleanup of derived objects 
 * when deleted through a base class pointer. Outputs a destruction message.
 */
Animal::~Animal(void)
{
    std::cout << getType() << " finished dinner and went to sleep." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Animal& Animal::operator=(Animal const & other)
 * @brief Copy assignment operator overload.
 * @details Assigns the _type attribute from one Animal object to another, 
 * strictly protecting against self-assignment.
 * @param other The Animal object to assign from.
 * @return      A reference to the newly assigned Animal object.
 */
Animal& Animal::operator=(Animal const & other)
{
    if (this != &other)
        _type = other.getType();
    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & Animal::getType(void) const
 * @brief Retrieves the type of the animal.
 * @details Provides read-only access to the internal _type attribute.
 * @return A constant reference to the _type string.
 */
std::string const & Animal::getType(void) const
{
    return _type;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Animal::makeSound(void) const
 * @brief Prints the sound the animal makes.
 * @details Declared as virtual to allow overriding by derived classes, 
 * enabling dynamic binding at runtime. Outputs a generic animal sound.
 */
void Animal::makeSound(void) const
{
    std::cout << "* Generic ambiguous animal noises *" << std::endl;
}
