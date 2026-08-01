/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 02:19:21 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 15:32:15 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Character.hpp"
#include "AMateria.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstddef>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Character::Character(void)
 * @brief Default constructor for the Character class.
 * @details Initializes the character's name and sets all inventory slots 
 * to NULL.
 */
Character::Character(void) : _name("Mysterious Traveler")
{
    for (int i = 0; i < _maxSlots; ++i)
        _inventory[i] = NULL;

    std::cout << "The legendary hero " << getName() << " has begun their quest inside the Lands of Chaos." << std::endl;
}

/**
 * @fn Character::Character(std::string const & name)
 * @brief Parameterized constructor for the Character class.
 * @details Initializes the character with a specific name and sets all 
 * inventory slots to NULL.
 * @param name The name of the character.
 */
Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < _maxSlots; ++i)
        _inventory[i] = NULL;

    std::cout << "The legendary hero " << getName() << " has begun their quest inside the Lands of Chaos." << std::endl;
}

/**
 * @fn Character::Character(Character const & other)
 * @brief Copy constructor for the Character class.
 * @details Constructs a new Character object as a deep copy of an existing 
 * one. Ensures strong exception safety by monitoring the cloning process; if a 
 * memory allocation fails, it safely cleans up any partially cloned materias 
 * before re-throwing the exception to prevent memory leaks.
 * @param other The Character object to copy from.
 */
Character::Character(Character const & other) : _name(other.getName())
{
    for (int i = 0; i < _maxSlots; ++i)
        _inventory[i] = NULL;

    try
    {
        for (int i = 0; i < _maxSlots; ++i)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
        }       
    }
    catch(...)
    {
        for (int i = 0; i < _maxSlots; ++i)
        {
            if (_inventory[i])
                delete _inventory[i];
        }
        throw;
    }
        
    std::cout << "Another legendary hero called " << getName() << " just set foot inside the Lands of Chaos." << std::endl;
}

/**
 * @fn Character::~Character(void)
 * @brief Destructor for the Character class.
 * @details Safely deletes all equipped materias in the character's inventory 
 * to prevent memory leaks.
 */
Character::~Character(void)
{
    for (int i = 0; i < _maxSlots; ++i)
    {
        if (_inventory[i])
            delete _inventory[i];
    }

    std::cout << "The legendary hero " << getName() << " successfully saved the world from imminent destruction." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Character& Character::operator=(Character const & other)
 * @brief Copy assignment operator overload.
 * @details Performs a deep copy assignment. Safeguards against self-assignment 
 * and ensures strong exception safety. Incoming materias are cloned into a 
 * temporary, NULL-initialized array. If any allocation fails, the temporary 
 * array is cleaned up and the exception is re-thrown, leaving the original 
 * Character entirely untouched. On success, the old inventory is deleted and 
 * successfully replaced.
 * @param other The Character object to assign from.
 * @return      A reference to the newly assigned Character object.
 */
Character& Character::operator=(Character const & other)
{
    if (this != &other)
    {
        AMateria* temp[_maxSlots];
        for (int i = 0; i < _maxSlots; ++i)
            temp[i] = NULL;
        
        try
        {
            for (int i = 0; i < _maxSlots; ++i)
            {
                if (other._inventory[i])
                    temp[i] = other._inventory[i]->clone();
            }
        }
        catch(...)
        {
            for (int i = 0; i < _maxSlots; ++i)
            {
                if (temp[i])
                    delete temp[i];
            }
            throw;
        }

        for (int i = 0; i < _maxSlots; ++i)
        {
            if (_inventory[i])
                delete _inventory[i];
            _inventory[i] = temp[i];
        }
        _name = other.getName();
    }
    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & Character::getName(void) const
 * @brief Retrieves the name of the character.
 * @details Provides read-only access to the character's internal _name 
 * attribute.
 * @return A constant reference to the _name string.
 */
std::string const & Character::getName(void) const
{
    return _name;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Character::equip(AMateria* m)
 * @brief Equips a materia in the first available empty slot.
 * @details Rejects NULL pointers, already-equipped materias, or equips if the 
 * inventory is full.
 * @param m A pointer to the AMateria to equip.
 */
void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << "Cannot equip a non-existent materia." << std::endl;
        return;
    }

    for (int i = 0; i < _maxSlots; ++i)
    {
        if (_inventory[i] == m)
        {
            std::cout << _inventory[i]->getType() << " materia is already equipped." << std::endl;
            return;
        }
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            std::cout << "Successfully equipped " << _inventory[i]->getType() << " materia in slot " << i << "." << std::endl;
            return;
        }

    }

    std::cout << "Materia inventory is full." << std::endl;
}

/**
 * @fn void Character::unequip(int idx)
 * @brief Unequips a materia from a specific inventory slot.
 * @details Removes the pointer from the inventory without deleting the actual 
 * materia object in memory. Prints error messages for invalid indices.
 * @param idx The inventory slot index to unequip.
 */
void Character::unequip(int idx)
{
    if (idx < 0 || idx >= _maxSlots)
        std::cout << "Inventory slot " << idx << " does not exist, hence cannot unequip a materia." << std::endl;
    else if (_inventory[idx] == NULL)
        std::cout << "No materia was found equipped in slot " << idx << "." << std::endl;
    else
    {
        std::cout << _inventory[idx]->getType() << " materia was successfully unequipped from slot " << idx << "." << std::endl;
        _inventory[idx] = NULL;
    }
}

/**
 * @fn void Character::use(int idx, ICharacter& target)
 * @brief Uses the materia in the specified slot on a target.
 * @details Defers the actual effect to the equipped AMateria object. Handles 
 * invalid index or empty slot checks gracefully.
 * @param idx    The inventory slot index to use.
 * @param target The target Character to use the materia on.
 */
void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= _maxSlots)
        std::cout << "Inventory slot " << idx << " does not exist, hence cannot use a materia." << std::endl;
    else if (_inventory[idx] == NULL)
        std::cout << "No materia available to use in slot " << idx << "." << std::endl;
    else
        _inventory[idx]->use(target);
}
