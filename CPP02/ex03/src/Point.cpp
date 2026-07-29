/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 00:57:09 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 01:46:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Point.hpp"

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Point::Point(void)
 * @brief Default constructor for the Point class.
 * @details Initializes the x and y coordinates to 0 using the Fixed class 
 * default behavior.
 */
Point::Point(void) : x(Fixed(0)), y(Fixed(0)) {}

/**
 * @fn Point::Point(float const n1, float const n2)
 * @brief Parameterized constructor for the Point class.
 * @details Initializes the x and y coordinates with the provided constant 
 * floating-point numbers.
 * @param n1 The floating-point value for the x coordinate.
 * @param n2 The floating-point value for the y coordinate.
 */
Point::Point(float const n1, float const n2) : x(Fixed(n1)), y(Fixed(n2)) {}

/**
 * @fn Point::Point(Point const & other)
 * @brief Copy constructor for the Point class.
 * @details Constructs a new Point object as a copy of an existing one. Since 
 * the attributes are const, they must be assigned via the initialization list.
 * @param other The Point object to copy from.
 */
Point::Point(Point const & other) : x(other.getX()), y(other.getY()) {}

/**
 * @fn Point::~Point(void)
 * @brief Destructor for the Point class.
 * @details Cleans up the Point object. Memory is managed automatically.
 */
Point::~Point(void) {}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Point& Point::operator=(Point const & other)
 * @brief Copy assignment operator overload.
 * @details Because the Point class contains const attributes, they cannot be 
 * reassigned after construction. This operator is provided to fulfill the 
 * Orthodox Canonical Form requirement, but it does not modify the object.
 * @param other The Point object to assign from (unused).
 * @return      A reference to the unmodified current Point object.
 */
Point& Point::operator=(Point const & other)
{
    (void)other;
    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn Fixed const & Point::getX(void) const
 * @brief Retrieves the x coordinate of the point.
 * @details Provides read-only access to the internal x attribute.
 * @return A constant reference to the Fixed object representing the 
 * x coordinate.
 */
Fixed const & Point::getX(void) const
{
    return x;
}

/**
 * @fn Fixed const & Point::getY(void) const
 * @brief Retrieves the y coordinate of the point.
 * @details Provides read-only access to the internal y attribute.
 * @return A constant reference to the Fixed object representing the 
 * y coordinate.
 */
Fixed const & Point::getY(void) const
{
    return y;
}
