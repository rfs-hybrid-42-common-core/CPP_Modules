/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:29:06 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/02 18:24:54 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Brain.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Brain::Brain(void)
 * @brief Default constructor for the Brain class.
 * @details Initializes the brain with 100 default ideas and prints a message.
 */
Brain::Brain(void)
{
    for (int i = 0; i < _maxIdeas; ++i)
        setIdea(i, "Thinking of something to do");
    std::cout << "A new Brain has been formed with " << _maxIdeas << " default ideas." << std::endl;
}

/**
 * @fn Brain::Brain(Brain const & other)
 * @brief Copy constructor for the Brain class.
 * @details Constructs a new Brain by copying all ideas from another Brain.
 * @param other The Brain object to copy from.
 */
Brain::Brain(Brain const & other)
{
    for (int i = 0; i < _maxIdeas; ++i)
        setIdea(i, other.getIdea(i));
    std::cout << "A Brain has been cloned, copying all " << _maxIdeas << " ideas." << std::endl;
}

/**
 * @fn Brain::~Brain(void)
 * @brief Destructor for the Brain class.
 * @details Cleans up the Brain object and prints a destruction message.
 */
Brain::~Brain(void)
{
    std::cout << "Brain activity has ceased." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Brain& Brain::operator=(Brain const & other)
 * @brief Copy assignment operator overload.
 * @details Assigns all 100 ideas from one Brain to another.
 * @param other The Brain object to assign from.
 * @return      A reference to the newly assigned Brain object.
 */
Brain& Brain::operator=(Brain const & other)
{
    if (this != &other)
    {
        for (int i = 0; i < _maxIdeas; ++i)
            setIdea(i, other.getIdea(i));
    }
    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & Brain::getIdea(int index) const
 * @brief Retrieves a specific idea from the brain's array.
 * @details Safely accesses the _ideas array using the provided index. If the 
 * index is out of bounds, it returns a static empty string to prevent 
 * undefined behavior.
 * @param index The array index of the idea to retrieve.
 * @return      A constant reference to the idea string at the given index, or 
 * an empty string if the index is invalid.
 */
std::string const & Brain::getIdea(int index) const
{
    static std::string const empty = "";
    if (index >= 0 && index < _maxIdeas)
        return _ideas[index];
    return empty;
}

/* ========================================================================== */
/* SETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn void Brain::setIdea(int index, std::string const & idea)
 * @brief Sets a specific idea in the brain's array.
 * @details Safely modifies the _ideas array at the provided index with the 
 * new string. If the index is out of bounds, the request is ignored to 
 * maintain safety.
 * @param index The array index where the idea should be stored.
 * @param idea  The string containing the new idea.
 */
void Brain::setIdea(int index, std::string const & idea)
{
    if (index >= 0 && index < _maxIdeas)
        _ideas[index] = idea;
}
