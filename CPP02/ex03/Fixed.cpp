/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 01:32:55 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/29 17:50:03 by maaugust         ###   ########.fr       */
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
/*                         CONSTRUCTORS & DESTRUCTORS                         */
/* ========================================================================== */

/**
 * @fn Fixed::Fixed(void)
 * @brief Default constructor for the Fixed class.
 * @details Initializes the fixed-point number value to 0.
 */
Fixed::Fixed(void) : _n(0) {}

/**
 * @fn Fixed::Fixed(int const n)
 * @brief Integer constructor for the Fixed class.
 * @details Converts a constant integer to the corresponding fixed-point 
 * value by shifting the bits.
 * @param n The integer value to convert.
 */
Fixed::Fixed(int const n) : _n(n << _bits) {}

/**
 * @fn Fixed::Fixed(float const n)
 * @brief Float constructor for the Fixed class.
 * @details Converts a constant floating-point number to the corresponding 
 * fixed-point value using roundf().
 * @param n The floating-point value to convert.
 */
Fixed::Fixed(float const n) : _n(roundf(n * (1 << _bits))) {}

/**
 * @fn Fixed::Fixed(Fixed const & other)
 * @brief Copy constructor for the Fixed class.
 * @details Constructs a new Fixed object as a copy of an existing one. 
 * Delegates the actual copying to the copy assignment operator.
 * @param other The Fixed object to copy from.
 */
Fixed::Fixed(Fixed const & other)
{
    *this = other;
}

/**
 * @fn Fixed::~Fixed(void)
 * @brief Destructor for the Fixed class.
 * @details Cleans up the Fixed object.
 */
Fixed::~Fixed(void) {}

/* ========================================================================== */
/*                            OPERATOR OVERLOADS                              */
/* ========================================================================== */

/* -------------------------- Assignment operator --------------------------- */

/**
 * @fn Fixed& Fixed::operator=(Fixed const & other)
 * @brief Copy assignment operator overload.
 * @details Assigns the raw bit value from one Fixed object to another, 
 * protecting against self-assignment.
 * @param other The Fixed object to assign from.
 * @return      A reference to the newly assigned Fixed object.
 */
Fixed& Fixed::operator=(Fixed const & other)
{
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

/* -------------------------- Comparison operators -------------------------- */

/**
 * @fn bool Fixed::operator>(Fixed const & other) const
 * @brief Greater-than comparison operator.
 * @param other The Fixed object to compare against.
 * @return True if this object is greater than the other, false otherwise.
 */
bool Fixed::operator>(Fixed const & other) const
{
    return (this->getRawBits() > other.getRawBits());
}

/**
 * @fn bool Fixed::operator>(Fixed const & other) const
 * @brief Greater-than comparison operator.
 * @param other The Fixed object to compare against.
 * @return True if this object is lesser than the other, false otherwise.
 */
bool Fixed::operator<(Fixed const & other) const
{
    return (this->getRawBits() < other.getRawBits());
}

/**
 * @fn bool Fixed::operator>(Fixed const & other) const
 * @brief Greater-than comparison operator.
 * @param other The Fixed object to compare against.
 * @return True if this object is greater than or equal to the other, 
 * false otherwise.
 */
bool Fixed::operator>=(Fixed const & other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

/**
 * @fn bool Fixed::operator>(Fixed const & other) const
 * @brief Greater-than comparison operator.
 * @param other The Fixed object to compare against.
 * @return True if this object is lower than or equal to the other, 
 * false otherwise.
 */
bool Fixed::operator<=(Fixed const & other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

/**
 * @fn bool Fixed::operator>(Fixed const & other) const
 * @brief Greater-than comparison operator.
 * @param other The Fixed object to compare against.
 * @return True if this object is equal to the other, false otherwise.
 */
bool Fixed::operator==(Fixed const & other) const
{
    return (this->getRawBits() == other.getRawBits());
}

/**
 * @fn bool Fixed::operator>(Fixed const & other) const
 * @brief Greater-than comparison operator.
 * @param other The Fixed object to compare against.
 * @return True if this object is not equal to the other, false otherwise.
 */
bool Fixed::operator!=(Fixed const & other) const
{
    return (this->getRawBits() != other.getRawBits());
}

/* -------------------------- Arithmetic operators -------------------------- */

/**
 * @fn Fixed Fixed::operator+(Fixed const & other) const
 * @brief Addition operator.
 * @details Converts both objects to floats, adds them, and returns a new Fixed 
 * object.
 * @param other The Fixed object to add.
 * @return A new Fixed object containing the sum.
 */
Fixed Fixed::operator+(Fixed const & other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

/**
 * @fn Fixed Fixed::operator+(Fixed const & other) const
 * @brief Addition operator.
 * @details Converts both objects to floats, subtracts them, and returns a new 
 * Fixed object.
 * @param other The Fixed object to subtract.
 * @return A new Fixed object containing the difference.
 */
Fixed Fixed::operator-(Fixed const & other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

/**
 * @fn Fixed Fixed::operator+(Fixed const & other) const
 * @brief Addition operator.
 * @details Converts both objects to floats, multiplies them, and returns a new 
 * Fixed object.
 * @param other The Fixed object to multiply.
 * @return A new Fixed object containing the product.
 */
Fixed Fixed::operator*(Fixed const & other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

/**
 * @fn Fixed Fixed::operator+(Fixed const & other) const
 * @brief Addition operator.
 * @details Converts both objects to floats, divides them, and returns a new 
 * Fixed object.
 * @param other The Fixed object to divide.
 * @return A new Fixed object containing the quotient.
 */
Fixed Fixed::operator/(Fixed const & other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

/* --------------------- Increment/Decrement operators ---------------------- */

/**
 * @fn Fixed& Fixed::operator++(void)
 * @brief Pre-increment operator.
 * @details Increases the fixed-point value by the smallest representable epsilon.
 * @return A reference to the incremented Fixed object.
 */

Fixed& Fixed::operator++(void)
{
    ++_n;
    return *this;
}

/**
 * @fn Fixed Fixed::operator++(int)
 * @brief Post-increment operator.
 * @details Increases the fixed-point value by the smallest representable 
 * epsilon, but returns a copy of the object before the increment.
 * @return A copy of the Fixed object before incrementing.
 */
Fixed  Fixed::operator++(int)
{
    Fixed temp = *this;
    ++_n;
    return temp;
}

Fixed& Fixed::operator--(void)
{
    --_n;
    return *this;
}

Fixed  Fixed::operator--(int)
{
    Fixed temp = *this;
    --_n;
    return temp;
}

/* ========================================================================== */
/*                                  GETTERS                                   */
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
/*                                  SETTERS                                   */
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
/*                               PUBLIC METHODS                               */
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
/*                           STATIC PUBLIC METHODS                            */
/* ========================================================================== */

/**
 * @fn Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
 * @brief Finds the minimum of two Fixed objects.
 * @param fixed1 The first Fixed object.
 * @param fixed2 The second Fixed object.
 * @return       A reference to the Fixed object with the smaller value.
 */
Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    return fixed1 < fixed2 ? fixed1 : fixed2;
}

/**
 * @fn Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
 * @brief Finds the maximum of two Fixed objects.
 * @param fixed1 The first Fixed object.
 * @param fixed2 The second Fixed object.
 * @return       A reference to the Fixed object with the larger value.
 */
Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    return fixed1 > fixed2 ? fixed1 : fixed2;
}

/**
 * @fn Fixed const & Fixed::min(Fixed const & fixed1, Fixed const & fixed2)
 * @brief Finds the minimum of two constant Fixed objects.
 * @param fixed1 The first constant Fixed object.
 * @param fixed2 The second constant Fixed object.
 * @return       A constant reference to the Fixed object with the smaller 
 * value.
 */
Fixed const & Fixed::min(Fixed const & fixed1, Fixed const & fixed2)
{
    return fixed1 < fixed2 ? fixed1 : fixed2;
}

/**
 * @fn Fixed const & Fixed::max(Fixed const & fixed1, Fixed const & fixed2)
 * @brief Finds the maximum of two constant Fixed objects.
 * @param fixed1 The first constant Fixed object.
 * @param fixed2 The second constant Fixed object.
 * @return       A constant reference to the Fixed object with the larger value.
 */
Fixed const & Fixed::max(Fixed const & fixed1, Fixed const & fixed2)
{
    return fixed1 > fixed2 ? fixed1 : fixed2;
}

/* ========================================================================== */
/*                       NON-MEMBER OPERATOR OVERLOADS                        */
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
