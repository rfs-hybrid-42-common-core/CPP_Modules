/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 02:19:32 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/04 03:53:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Ice.hpp"
#include "ICharacter.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Ice::Ice(void)
 * @brief Default constructor for the Ice class.
 * @details Initializes the base AMateria class with the type "ice" and 
 * outputs a specific creation message.
 */
Ice::Ice(void) : AMateria("ice")
{
    std::cout << "An " << getType() << " materia has been manifested." << std::endl;
}

/**
 * @fn Ice::Ice(Ice const & other)
 * @brief Copy constructor for the Ice class.
 * @details Constructs a new Ice object by calling the base AMateria copy 
 * constructor and outputs a specific creation message.
 * @param other The Ice object to copy from.
 */
Ice::Ice(Ice const & other) : AMateria(other)
{
    std::cout << "An " << getType() << " materia has been perfectly duplicated." << std::endl;
}

/**
 * @fn Ice::~Ice(void)
 * @brief Destructor for the Ice class.
 * @details Outputs a destruction message before the base AMateria destructor 
 * is called.
 */
Ice::~Ice(void) 
{
    std::cout << "An " << getType() << " materia has melted away." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Ice& Ice::operator=(Ice const & other)
 * @brief Copy assignment operator overload.
 * @details Follows the rule that assigning a Materia does not copy the type. 
 * Outputs a trace message.
 * @param other The Ice object to assign from (unused).
 * @return      A reference to the unmodified Ice object.
 */
Ice& Ice::operator=(Ice const & other)
{
    (void)other;
    std::cout << "The " << getType() << " materia remains unchanged." << std::endl;
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn AMateria* Ice::clone(void) const
 * @brief Clones the Ice materia.
 * @details Dynamically allocates a new instance of Ice to be used in the 
 * Prototype pattern.
 * @return A pointer to the newly allocated Ice object.
 */
AMateria* Ice::clone(void) const
{
    return new Ice();
}

/**
 * @fn void Ice::use(ICharacter& target)
 * @brief Uses the Ice materia on a target.
 * @details Outputs the specific ice attack message against the target's name.
 * @param target The Character object being targeted.
 */
void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
