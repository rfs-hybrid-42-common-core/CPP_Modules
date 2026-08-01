/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:43:58 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 15:59:27 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Cat.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Cat::Cat(void)
 * @brief Default constructor for the Cat class.
 * @details Initializes the Cat by calling the parameterized Animal base 
 * constructor with the string "Cat". Outputs a specific creation message.
 */
Cat::Cat(void) : Animal("Cat")
{
    std::cout << "A " << getType() << " is grooming its fur."  << std::endl;
}

/**
 * @fn Cat::Cat(Cat const & other)
 * @brief Copy constructor for the Cat class.
 * @details Constructs a new Cat object as a copy of an existing one by passing 
 * the other instance to the Animal base copy constructor.
 * @param other The Cat object to copy from.
 */
Cat::Cat(Cat const & other) : Animal(other)
{
    std::cout << "Another " << getType() << " is grooming its fur."  << std::endl;
}

/**
 * @fn Cat::~Cat(void)
 * @brief Destructor for the Cat class.
 * @details Cleans up the Cat object and outputs a specific destruction 
 * message. Automatically calls the base Animal destructor afterwards.
 */
Cat::~Cat(void)
{
    std::cout << "The " << getType() << " is sleeping on the bed."  << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Cat& Cat::operator=(Cat const & other)
 * @brief Copy assignment operator overload.
 * @details Assigns the state from one Cat object to another by explicitly 
 * calling the base Animal class assignment operator.
 * @param other The Cat object to assign from.
 * @return      A reference to the newly assigned Cat object.
 */
Cat& Cat::operator=(Cat const & other)
{
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Cat::makeSound(void) const
 * @brief Prints the sound the cat makes.
 * @details Overrides the virtual makeSound method of the Animal base class 
 * to output a specific cat meow.
 */
void Cat::makeSound(void) const
{
    std::cout << "Meow! Meeeooow!" << std::endl;
}
