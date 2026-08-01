/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:43:58 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 16:01:32 by maaugust         ###   ########.fr       */
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
 * constructor with the string "Cat". Dynamically allocates a new Brain 
 * and outputs a specific creation message.
 */
Cat::Cat(void) : Animal("Cat")
{
    brain = new Brain();
    std::cout << "A " << getType() << " is grooming its fur."  << std::endl;
}

/**
 * @fn Cat::Cat(Cat const & other)
 * @brief Copy constructor for the Cat class.
 * @details Constructs a new Cat object as a deep copy of an existing one. 
 * Passes the other instance to the Animal base copy constructor and safely 
 * allocates a completely new Brain by copying the other Cat's brain, provided 
 * it exists. Otherwise, the brain pointer is set to NULL.
 * @param other The Cat object to copy from.
 */
Cat::Cat(Cat const & other) : Animal(other)
{
    other.brain ? brain = new Brain(*other.brain) : brain = NULL;
    std::cout << "Another " << getType() << " is grooming its fur."  << std::endl;
}

/**
 * @fn Cat::~Cat(void)
 * @brief Destructor for the Cat class.
 * @details Cleans up the Cat object by safely deleting the dynamically 
 * allocated Brain to prevent memory leaks. Outputs a destruction message.
 */
Cat::~Cat(void)
{
    delete brain;
    std::cout << "The " << getType() << " is sleeping on the bed."  << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Cat& Cat::operator=(Cat const & other)
 * @brief Copy assignment operator overload.
 * @details Performs a deep copy assignment. Safeguards against self-assignment 
 * by explicitly allocating a new Brain first based on the other Cat's brain, 
 * destroying the current Brain, assigning the newly allocated memory, and 
 * calling the base Animal assignment. This sequence ensures the object remains 
 * entirely intact and valid throughout the operation.
 * @param other The Cat object to assign from.
 * @return      A reference to the newly assigned Cat object.
 */
Cat& Cat::operator=(Cat const & other)
{
    if (this != &other)
    {
        Brain *temp = NULL;
        if (other.brain)
            temp = new Brain(*other.brain);
        delete brain;
        brain = temp;
        Animal::operator=(other);
    }
    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & Cat::getIdea(int index) const
 * @brief Retrieves a specific idea from the Cat's brain.
 * @details Acts as a wrapper method to safely access the ideas array 
 * stored within the Cat's dynamically allocated Brain attribute.
 * @param index The array index of the idea to retrieve.
 * @return      A constant reference to the idea string at the given index.
 */
std::string const & Cat::getIdea(int index) const
{
    return brain->getIdea(index);
}

/* ========================================================================== */
/* SETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn void Cat::setIdea(int index, std::string const & idea)
 * @brief Sets a specific idea in the Cat's brain.
 * @details Acts as a wrapper method to safely modify a specific idea 
 * within the Cat's dynamically allocated Brain attribute.
 * @param index The array index where the idea should be stored.
 * @param idea  The string containing the new idea.
 */
void Cat::setIdea(int index, std::string const & idea)
{
    brain->setIdea(index, idea);
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
