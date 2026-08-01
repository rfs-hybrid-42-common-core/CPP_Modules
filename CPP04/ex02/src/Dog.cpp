/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:44:45 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 16:02:39 by maaugust         ###   ########.fr       */
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
 * @details Initializes the Dog by calling the parameterized AAnimal base 
 * constructor with the string "Dog". Dynamically allocates a new Brain 
 * and outputs a specific creation message.
 */
Dog::Dog(void) : AAnimal("Dog")
{
    brain = new Brain();
    std::cout << "A " << getType() << " is playing fetch."  << std::endl;
}

/**
 * @fn Dog::Dog(Dog const & other)
 * @brief Copy constructor for the Dog class.
 * @details Constructs a new Dog object as a deep copy of an existing one. 
 * Passes the other instance to the AAnimal base copy constructor and safely 
 * allocates a completely new Brain by copying the other Dog's brain, provided 
 * it exists. Otherwise, the brain pointer is set to NULL.
 * @param other The Dog object to copy from.
 */
Dog::Dog(Dog const & other) : AAnimal(other)
{
    other.brain ? brain = new Brain(*other.brain) : brain = NULL;
    std::cout << "Another " << getType() << " is playing fetch."  << std::endl;
}

/**
 * @fn Dog::~Dog(void)
 * @brief Destructor for the Dog class.
 * @details Cleans up the Dog object by safely deleting the dynamically 
 * allocated Brain to prevent memory leaks. Outputs a destruction message.
 */
Dog::~Dog(void)
{
    delete brain;
    std::cout << "The " << getType() << " is sleeping on the floor." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Dog& Dog::operator=(Dog const & other)
 * @brief Copy assignment operator overload.
 * @details Performs a deep copy assignment. Safeguards against self-assignment 
 * by explicitly allocating a new Brain first based on the other Dog's brain, 
 * destroying the current Brain, assigning the newly allocated memory, and 
 * calling the base AAnimal assignment. This sequence ensures the object remains 
 * entirely intact and valid throughout the operation.
 * @param other The Dog object to assign from.
 * @return      A reference to the newly assigned Dog object.
 */
Dog& Dog::operator=(Dog const & other)
{
    if (this != &other)
    {
        Brain *temp = NULL;
        if (other.brain)
            temp = new Brain(*other.brain);
        delete brain;
        brain = temp;
        AAnimal::operator=(other);
    }
    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & Dog::getIdea(int index) const
 * @brief Retrieves a specific idea from the Dog's brain.
 * @details Acts as a wrapper method to safely access the ideas array 
 * stored within the Dog's dynamically allocated Brain attribute.
 * @param index The array index of the idea to retrieve.
 * @return      A constant reference to the idea string at the given index.
 */
std::string const & Dog::getIdea(int index) const
{
    return brain->getIdea(index);
}

/* ========================================================================== */
/* SETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn void Dog::setIdea(int index, std::string const & idea)
 * @brief Sets a specific idea in the Dog's brain.
 * @details Acts as a wrapper method to safely modify a specific idea 
 * within the Dog's dynamically allocated Brain attribute.
 * @param index The array index where the idea should be stored.
 * @param idea  The string containing the new idea.
 */
void Dog::setIdea(int index, std::string const & idea)
{
    brain->setIdea(index, idea);
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Dog::makeSound(void) const
 * @brief Prints the sound the dog makes.
 * @details Overrides the virtual makeSound method of the abstract AAnimal base 
 * class to output a specific dog bark.
 */
void Dog::makeSound(void) const
{
    std::cout << "Woof! Bark! Woof!" << std::endl;
}
