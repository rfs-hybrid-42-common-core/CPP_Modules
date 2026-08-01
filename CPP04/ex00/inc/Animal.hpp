/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:42:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/01 05:24:01 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/**
 * @class Animal
 * @brief Represents a generic animal.
 * @details Serves as a polymorphic base class for specific animal types, 
 * demonstrating dynamic binding through virtual functions.
 */
class Animal
{
    protected:
        /* ------------------------------------------------------------------ */
        /* PROTECTED ATTRIBUTES                                               */
        /* ------------------------------------------------------------------ */
        std::string _type;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Animal(void);
        Animal(std::string const & type);
        Animal(Animal const & other);
        virtual ~Animal(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        Animal& operator=(Animal const & other);

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        std::string const & getType(void) const;

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        virtual void makeSound(void) const;
};

#endif
