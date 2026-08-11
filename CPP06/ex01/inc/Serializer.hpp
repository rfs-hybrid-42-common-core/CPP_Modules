/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 01:25:03 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/12 02:18:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Data.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <stdint.h>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Serializer
 * @brief A utility class for memory address serialization.
 * @details Provides static methods to convert a Data pointer to an unsigned 
 * integer type and vice versa. Designed as a purely static class that 
 * cannot be instantiated by the user.
 */
class Serializer
{
    private:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Serializer(void);
        Serializer(Serializer const & other);
        ~Serializer(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        Serializer& operator=(Serializer const & other);

    public:
        /* ------------------------------------------------------------------ */
        /* STATIC PUBLIC METHODS                                              */
        /* ------------------------------------------------------------------ */
        static uintptr_t serialize(Data* ptr);
        static Data*     deserialize(uintptr_t raw);
};

#endif
