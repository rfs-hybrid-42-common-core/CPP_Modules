/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 02:19:12 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/04 03:53:52 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "AMateria.hpp"
#include "ICharacter.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn AMateria::AMateria(void)
 * @brief Default constructor for the AMateria class.
 * @details Initializes the _type attribute to "unknown" and outputs a 
 * specific creation message.
 */
AMateria::AMateria(void) : _type("unknown")
{
    std::cout << "A materia of " << getType() << " effect was created." << std::endl;
}

/**
 * @fn AMateria::AMateria(std::string const & type)
 * @brief Parameterized constructor for the AMateria class.
 * @details Initializes the _type attribute with the provided string and 
 * outputs a specific creation message.
 * @param type The string identifying the materia's type.
 */
AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "A materia of " << getType() << " effect was created." << std::endl;
}

/**
 * @fn AMateria::AMateria(AMateria const & other)
 * @brief Copy constructor for the AMateria class.
 * @details Constructs a new AMateria object as a copy of an existing one by 
 * copying the _type attribute.
 * @param other The AMateria object to copy from.
 */
AMateria::AMateria(AMateria const & other) : _type(other.getType())
{
    std::cout << "Another materia of " << getType() << " effect was created." << std::endl;
}

/**
 * @fn AMateria::~AMateria(void)
 * @brief Destructor for the AMateria class.
 * @details Declared as virtual to ensure proper cleanup of derived concrete 
 * classes (like Ice and Cure). Outputs a destruction message.
 */
AMateria::~AMateria(void)
{
    std::cout << "Materia of " << getType() << " effect was permanently discarded." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn AMateria& AMateria::operator=(AMateria const & other)
 * @brief Copy assignment operator overload.
 * @details Per the subject requirements, assigning one Materia to another 
 * does not copy the type. Therefore, this operator does nothing to the state 
 * but outputs a message to trace the assignment.
 * @param other The AMateria object to assign from (unused).
 * @return      A reference to the unmodified AMateria object.
 */
AMateria& AMateria::operator=(AMateria const & other)
{
    (void)other;
    std::cout << "The " << getType() << " materia remains unchanged." << std::endl;
    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & AMateria::getType(void) const
 * @brief Retrieves the type of the materia.
 * @details Provides read-only access to the internal _type attribute.
 * @return A constant reference to the _type string.
 */
std::string const & AMateria::getType() const
{
    return _type;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void AMateria::use(ICharacter& target)
 * @brief Uses the materia on a target character.
 * @details Provides a base implementation for the virtual use method. Derived 
 * classes will override this to output their specific effects.
 * @param target The Character object being targeted by the materia.
 */
void AMateria::use(ICharacter& target)
{
    std::cout << "* Random materia applied to " << target.getName() << " *" << std::endl;
}
