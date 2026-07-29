/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 01:32:55 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:00:57 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Fixed.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Fixed::Fixed(void)
 * @brief Default constructor for the Fixed class.
 * @details Initializes the fixed-point number value to 0 and prints a 
 * trace message to standard output.
 */
Fixed::Fixed(void) : _n(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/**
 * @fn Fixed::Fixed(Fixed const & other)
 * @brief Copy constructor for the Fixed class.
 * @details Constructs a new Fixed object as a copy of an existing one. 
 * Delegates the actual copying to the copy assignment operator and prints 
 * a trace message to standard output.
 * @param other The Fixed object to copy from.
 */
Fixed::Fixed(Fixed const & other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/**
 * @fn Fixed::~Fixed(void)
 * @brief Destructor for the Fixed class.
 * @details Cleans up the Fixed object and prints a trace message to 
 * standard output.
 */
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Fixed& Fixed::operator=(Fixed const & other)
 * @brief Copy assignment operator overload.
 * @details Assigns the raw bit value from one Fixed object to another, 
 * protecting against self-assignment. Prints a trace message to standard 
 * output.
 * @param other The Fixed object to assign from.
 * @return      A reference to the newly assigned Fixed object.
 */
Fixed& Fixed::operator=(Fixed const & other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn int Fixed::getRawBits(void) const
 * @brief Retrieves the raw value of the fixed-point number.
 * @details Provides read-only access to the internal _n attribute and prints 
 * a trace message to standard output.
 * @return The raw integer value representing the fixed-point number.
 */
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _n;
}

/* ========================================================================== */
/* SETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn void Fixed::setRawBits(int const raw)
 * @brief Sets the raw value of the fixed-point number.
 * @details Directly modifies the internal _n attribute with the provided 
 * raw integer value.
 * @param raw The new raw integer value to set.
 */
void Fixed::setRawBits(int const raw)
{
    _n = raw;
}
