/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 22:30:20 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 16:01:09 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "WrongCat.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn WrongCat::WrongCat(void)
 * @brief Default constructor for the WrongCat class.
 * @details Initializes the WrongCat by calling the parameterized WrongAnimal 
 * base constructor with the string "Cat". Outputs a specific creation message.
 */
WrongCat::WrongCat(void) : WrongAnimal("Cat")
{
    std::cout << "A black " << getType() << " is lurking in the shadows."  << std::endl;
}

/**
 * @fn WrongCat::WrongCat(WrongCat const & other)
 * @brief Copy constructor for the WrongCat class.
 * @details Constructs a new WrongCat object as a copy of an existing one by 
 * passing the other instance to the WrongAnimal base copy constructor.
 * @param other The WrongCat object to copy from.
 */
WrongCat::WrongCat(WrongCat const & other) : WrongAnimal(other)
{
    std::cout << "Another black " << getType() << " is lurking in the shadows."  << std::endl;
}

/**
 * @fn WrongCat::~WrongCat(void)
 * @brief Destructor for the WrongCat class.
 * @details Cleans up the WrongCat object and outputs a specific destruction 
 * message. Automatically calls the base WrongAnimal destructor afterwards.
 */
WrongCat::~WrongCat(void)
{
    std::cout << "The " << getType() << " stole a fish and ran off with it."  << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn WrongCat& WrongCat::operator=(WrongCat const & other)
 * @brief Copy assignment operator overload.
 * @details Assigns the state from one WrongCat object to another by explicitly 
 * calling the base WrongAnimal class assignment operator.
 * @param other The WrongCat object to assign from.
 * @return      A reference to the newly assigned WrongCat object.
 */
WrongCat& WrongCat::operator=(WrongCat const & other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void WrongCat::makeSound(void) const
 * @brief Prints the sound the wrong cat makes.
 * @details Because the base class makeSound is not virtual, this method hides 
 * the base implementation rather than overriding it. It will only be called 
 * if the object is accessed directly or through a WrongCat pointer.
 */
void WrongCat::makeSound(void) const
{
    std::cout << "Hiss! I say HISS!" << std::endl;
}
