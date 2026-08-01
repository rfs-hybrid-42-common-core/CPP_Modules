/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 02:19:26 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/04 03:58:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Cure.hpp"
#include "ICharacter.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Cure::Cure(void)
 * @brief Default constructor for the Cure class.
 * @details Initializes the base AMateria class with the type "cure" and 
 * outputs a specific creation message.
 */
Cure::Cure(void) : AMateria("cure") 
{
    std::cout << "A " << getType() << " materia has been synthesized." << std::endl;
}

/**
 * @fn Cure::Cure(Cure const & other)
 * @brief Copy constructor for the Cure class.
 * @details Constructs a new Cure object by calling the base AMateria copy 
 * constructor and outputs a specific creation message.
 * @param other The Cure object to copy from.
 */
Cure::Cure(Cure const & other) : AMateria(other) 
{
    std::cout << "A " << getType() << " materia has been perfectly duplicated." << std::endl;
}

/**
 * @fn Cure::~Cure(void)
 * @brief Destructor for the Cure class.
 * @details Outputs a destruction message before the base AMateria destructor 
 * is called.
 */
Cure::~Cure(void) 
{
    std::cout << "A " << getType() << " materia has dissipated." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Cure& Cure::operator=(Cure const & other)
 * @brief Copy assignment operator overload.
 * @details Follows the rule that assigning a Materia does not copy the type. 
 * Outputs a trace message.
 * @param other The Cure object to assign from (unused).
 * @return      A reference to the unmodified Cure object.
 */
Cure& Cure::operator=(Cure const & other)
{
    (void)other;
    std::cout << "The " << getType() << " materia remains unchanged." << std::endl;
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn AMateria* Cure::clone(void) const
 * @brief Clones the Cure materia.
 * @details Dynamically allocates a new instance of Cure to be used in the 
 * Prototype pattern.
 * @return A pointer to the newly allocated Cure object.
 */
AMateria* Cure::clone(void) const
{
    return new Cure();
}

/**
 * @fn void Cure::use(ICharacter& target)
 * @brief Uses the Cure materia on a target.
 * @details Outputs the specific healing message for the target's name.
 * @param target The Character object being targeted.
 */
void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
