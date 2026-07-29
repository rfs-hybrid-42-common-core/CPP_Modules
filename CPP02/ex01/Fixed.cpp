/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 01:32:55 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:01:39 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Fixed.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cmath>

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
 * @fn Fixed::Fixed(int const n)
 * @brief Integer constructor for the Fixed class.
 * @details Converts a constant integer to the corresponding fixed-point 
 * value by shifting the bits and prints a trace message to standard output.
 * @param n The integer value to convert.
 */
Fixed::Fixed(int const n) : _n(n << _bits)
{
    std::cout << "Int constructor called" << std::endl;
}

/**
 * @fn Fixed::Fixed(float const n)
 * @brief Float constructor for the Fixed class.
 * @details Converts a constant floating-point number to the corresponding 
 * fixed-point value using roundf() and prints a trace message.
 * @param n The floating-point value to convert.
 */
Fixed::Fixed(float const n) : _n(roundf(n * (1 << _bits)))
{
    std::cout << "Float constructor called" << std::endl;
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
 * @details Provides read-only access to the internal _n attribute.
 * @return The raw integer value representing the fixed-point number.
 */
int Fixed::getRawBits(void) const
{
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

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn float Fixed::toFloat(void) const
 * @brief Converts the fixed-point value to a floating-point value.
 * @details Divides the raw integer value by the scaling factor representation 
 * of the fractional bits.
 * @return The converted floating-point value.
 */
float Fixed::toFloat(void) const
{
    return _n / static_cast<float>(1 << _bits);
}

/**
 * @fn int Fixed::toInt(void) const
 * @brief Converts the fixed-point value to an integer value.
 * @details Shifts the raw bit value right by the number of fractional bits 
 * to truncate the decimal portion.
 * @return The converted integer value.
 */
int Fixed::toInt(void) const
{
    return _n >> _bits;
}

/* ========================================================================== */
/* NON-MEMBER OPERATOR OVERLOADS                                              */
/* ========================================================================== */

/**
 * @fn std::ostream& operator<<(std::ostream& o, Fixed const & fixed)
 * @brief Overloads the insertion operator for the Fixed class.
 * @details Inserts a floating-point representation of the fixed-point number 
 * into the given output stream object.
 * @param o     The output stream object.
 * @param fixed The Fixed object to insert into the stream.
 * @return      A reference to the modified output stream object.
 */
std::ostream& operator<<(std::ostream& o, Fixed const & fixed)
{
    o << fixed.toFloat();
    return o;
}
