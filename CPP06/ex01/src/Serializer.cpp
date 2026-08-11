/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 01:40:32 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/12 02:19:44 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Serializer.hpp"

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Serializer::Serializer(void)
 * @brief Default constructor for the Serializer class.
 * @details Kept private to enforce a purely static utility class structure 
 * and prevent user instantiation.
 */
Serializer::Serializer(void) {}

/**
 * @fn Serializer::Serializer(Serializer const & other)
 * @brief Copy constructor for the Serializer class.
 * @details Kept private and unused to prevent instantiation.
 * @param other The Serializer object to copy (unused).
 */
Serializer::Serializer(Serializer const & other)
{
    (void)other;
}

/**
 * @fn Serializer::~Serializer(void)
 * @brief Destructor for the Serializer class.
 * @details Kept private to prevent instantiation.
 */
Serializer::~Serializer(void) {}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Serializer& Serializer::operator=(Serializer const & other)
 * @brief Copy assignment operator overload.
 * @details Kept private and unused to prevent instantiation.
 * @param other The Serializer object to assign from (unused).
 * @return      A reference to the current unmodified object.
 */
Serializer& Serializer::operator=(Serializer const & other)
{
    (void)other;
    return *this;
}

/* ========================================================================== */
/* STATIC PUBLIC METHODS                                                      */
/* ========================================================================== */

/**
 * @fn uintptr_t Serializer::serialize(Data* ptr)
 * @brief Serializes a Data pointer to an unsigned integer.
 * @details Uses reinterpret_cast to safely convert the memory address of the 
 * given Data pointer into a raw uintptr_t format without altering its bits.
 * @param ptr A pointer to the Data structure to be serialized.
 * @return    The memory address represented as an unsigned integer.
 */
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @fn Data* Serializer::deserialize(uintptr_t raw)
 * @brief Deserializes an unsigned integer back to a Data pointer.
 * @details Uses reinterpret_cast to convert a raw uintptr_t memory address 
 * back into a highly-typed pointer to a Data structure.
 * @param raw The unsigned integer representation of a memory address.
 * @return    A pointer to the Data structure located at the given address.
 */
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
