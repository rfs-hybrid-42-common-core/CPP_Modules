/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:11:02 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 15:32:56 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "MateriaSource.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstddef>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn MateriaSource::MateriaSource(void)
 * @brief Default constructor for the MateriaSource class.
 * @details Initializes the MateriaSource by setting all internal blueprint 
 * slots to NULL to ensure clean memory.
 */
MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < _maxMaterias; ++i)
        _materias[i] = NULL;

    std::cout << "A new Materia source was generated." << std::endl;
}

/**
 * @fn MateriaSource::MateriaSource(MateriaSource const & other)
 * @brief Copy constructor for the MateriaSource class.
 * @details Constructs a new MateriaSource as a deep copy of an existing one. 
 * Ensures strong exception safety by safely destroying any partially cloned 
 * blueprints and re-throwing the exception if a memory allocation fails during 
 * the cloning process.
 * @param other The MateriaSource object to copy from.
 */
MateriaSource::MateriaSource(MateriaSource const & other)
{
    for (int i = 0; i < _maxMaterias; ++i)
        _materias[i] = NULL;

    try
    {
        for (int i = 0; i < _maxMaterias; ++i)
        {
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
        }
    }
    catch(...)
    {
        for (int i = 0; i < _maxMaterias; ++i)
        {
            if (_materias[i])
                delete _materias[i];
        }
        throw;
    }

    std::cout << "A copy of an existing Materia source was generated." << std::endl;
}

/**
 * @fn MateriaSource::~MateriaSource(void)
 * @brief Destructor for the MateriaSource class.
 * @details Safely deletes all learned AMateria blueprints from memory to 
 * prevent memory leaks.
 */
MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < _maxMaterias; ++i)
    {
        if (_materias[i])
            delete _materias[i];
    }

    std::cout << "A Materia source was removed." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn MateriaSource& MateriaSource::operator=(MateriaSource const & other)
 * @brief Copy assignment operator overload.
 * @details Performs a deep copy assignment. Prevents self-assignment and 
 * guarantees strong exception safety by cloning incoming blueprints into a 
 * temporary array. If a memory allocation fails during this phase, the 
 * temporary items are destroyed and the error is re-thrown, perfectly 
 * preserving the original state of the MateriaSource.
 * @param other The MateriaSource object to assign from.
 * @return      A reference to the newly assigned MateriaSource object.
 */
MateriaSource& MateriaSource::operator=(MateriaSource const & other)
{
    if (this != &other)
    {
        AMateria* temp[_maxMaterias];
        for (int i = 0; i < _maxMaterias; ++i)
            temp[i] = NULL;

        try
        {
            for (int i = 0; i < _maxMaterias; ++i)
            {
                if (other._materias[i])
                    temp[i] = other._materias[i]->clone();
            }
        }
        catch(...)
        {
            for (int i = 0; i < _maxMaterias; ++i)
            {
                if (temp[i])
                    delete temp[i];
            }
            throw;
        }

        for (int i = 0; i < _maxMaterias; ++i)
        {
            if (_materias[i])
                delete _materias[i];
            _materias[i] = temp[i];
        }
    }

    std::cout << "A Materia source was replaced with another source." << std::endl;
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void MateriaSource::learnMateria(AMateria* m)
 * @brief Learns a new materia blueprint.
 * @details Stores the provided AMateria pointer in the first available slot so 
 * it can be cloned later. Rejects NULL pointers. If the source is full, it 
 * automatically deletes the passed pointer to prevent memory leaks.
 * @param m A pointer to the AMateria to learn.
 */
void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
    {
        std::cout << "Cannot learn a non-existent materia." << std::endl;
        return;
    }

    for (int i = 0; i < _maxMaterias; ++i)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = m;
            std::cout << "A new " << m->getType() << " materia has been learned." << std::endl;
            return;
        }
    }
    delete m;

    std::cout << "No slots available to learn new materias." << std::endl;
}

/**
 * @fn AMateria* MateriaSource::createMateria(std::string const & type)
 * @brief Creates a new materia based on a learned blueprint.
 * @details Searches the learned blueprints for one matching the requested type 
 * string. If found, returns a dynamically allocated clone of that blueprint.
 * @param type The string representation of the materia type to create.
 * @return     A pointer to a new AMateria object, or NULL if the type 
 * is unknown.
 */
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < _maxMaterias; ++i)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            std::cout << "A " << type << " materia was successfully created." << std::endl;
            return _materias[i]->clone();
        }
    }

    std::cout << type << " materia creation failed." << std::endl;
    return 0;
}
