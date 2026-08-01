/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:44:45 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 15:59:43 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Dog.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Dog::Dog(void)
 * @brief Default constructor for the Dog class.
 * @details Initializes the Dog by calling the parameterized Animal base 
 * constructor with the string "Dog". Outputs a specific creation message.
 */
Dog::Dog(void) : Animal("Dog")
{
    std::cout << "A " << getType() << " is playing fetch."  << std::endl;
}

/**
 * @fn Dog::Dog(Dog const & other)
 * @brief Copy constructor for the Dog class.
 * @details Constructs a new Dog object as a copy of an existing one by passing 
 * the other instance to the Animal base copy constructor.
 * @param other The Dog object to copy from.
 */
Dog::Dog(Dog const & other) : Animal(other)
{
    std::cout << "Another " << getType() << " is playing fetch."  << std::endl;
}

/**
 * @fn Dog::~Dog(void)
 * @brief Destructor for the Dog class.
 * @details Cleans up the Dog object and outputs a specific destruction message. 
 * Automatically calls the base Animal destructor afterwards.
 */
Dog::~Dog(void)
{
    std::cout << "The " << getType() << " is sleeping on the floor." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Dog& Dog::operator=(Dog const & other)
 * @brief Copy assignment operator overload.
 * @details Assigns the state from one Dog object to another by explicitly 
 * calling the base Animal class assignment operator.
 * @param other The Dog object to assign from.
 * @return      A reference to the newly assigned Dog object.
 */
Dog& Dog::operator=(Dog const & other)
{
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Dog::makeSound(void) const
 * @brief Prints the sound the dog makes.
 * @details Overrides the virtual makeSound method of the Animal base class 
 * to output a specific dog bark.
 */
void Dog::makeSound(void) const
{
    std::cout << "Woof! Bark! Woof!" << std::endl;
}
