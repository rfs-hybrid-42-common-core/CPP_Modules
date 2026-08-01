/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:42:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/02 18:56:53 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/**
 * @class AAnimal
 * @brief Represents an abstract generic animal.
 * @details Serves as a pure abstract base class (interface) for specific 
 * animal types. Cannot be instantiated directly. Demonstrates dynamic binding 
 * through pure virtual functions.
 */
class AAnimal
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
        AAnimal(void);
        AAnimal(std::string const & type);
        AAnimal(AAnimal const & other);
        virtual ~AAnimal(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        AAnimal& operator=(AAnimal const & other);

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        std::string const & getType(void) const;

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        virtual void makeSound(void) const = 0;
};

#endif
