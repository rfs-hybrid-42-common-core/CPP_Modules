/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:43:10 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/02 19:07:29 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "AAnimal.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn AAnimal::AAnimal(void)
 * @brief Default constructor for the abstract AAnimal class.
 * @details Initializes the _type attribute to "Unknown" and outputs a specific 
 * creation message to the standard output.
 */
AAnimal::AAnimal(void) : _type("Unknown")
{
    std::cout << "A cute " << getType() << " has been adopted by a loving family." << std::endl;
}

/**
 * @fn AAnimal::AAnimal(std::string const & type)
 * @brief Parameterized constructor for the abstract AAnimal class.
 * @details Initializes the _type attribute with the provided string and 
 * outputs a specific creation message to the standard output.
 * @param type The type of the animal.
 */
AAnimal::AAnimal(std::string const & type) : _type(type)
{
    std::cout << "A cute " << getType() << " has been adopted by a loving family." << std::endl;
}

/**
 * @fn AAnimal::AAnimal(AAnimal const & other)
 * @brief Copy constructor for the abstract AAnimal class.
 * @details Constructs a new Animal object as a copy of an existing one by 
 * copying the _type attribute, and outputs a specific creation message.
 * @param other The AAnimal object to copy from.
 */
AAnimal::AAnimal(AAnimal const & other) : _type(other.getType())
{
    std::cout << "Another cute " << getType() << " has been adopted by a loving family." << std::endl;
}

/**
 * @fn AAnimal::~AAnimal(void)
 * @brief Destructor for the abstract AAnimal class.
 * @details Declared as virtual to ensure proper cleanup of derived objects 
 * when deleted through a base class pointer. Outputs a destruction message.
 */
AAnimal::~AAnimal(void)
{
    std::cout << getType() << " finished dinner and went to sleep." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn AAnimal& AAnimal::operator=(AAnimal const & other)
 * @brief Copy assignment operator overload.
 * @details Assigns the _type attribute from one AAnimal object to another, 
 * strictly protecting against self-assignment.
 * @param other The AAnimal object to assign from.
 * @return      A reference to the newly assigned Animal object.
 */
AAnimal& AAnimal::operator=(AAnimal const & other)
{
    if (this != &other)
        _type = other.getType();
    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & AAnimal::getType(void) const
 * @brief Retrieves the type of the animal.
 * @details Provides read-only access to the internal _type attribute.
 * @return A constant reference to the _type string.
 */
std::string const & AAnimal::getType(void) const
{
    return _type;
}
