/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 22:05:33 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/04 22:38:51 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class WrongAnimal
 * @brief Represents a generic animal with flawed polymorphism.
 * @details Serves as a base class designed to demonstrate the pitfalls of 
 * missing virtual keywords (static binding) in C++ inheritance.
 */
class WrongAnimal
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
        WrongAnimal(void);
        WrongAnimal(std::string const & type);
        WrongAnimal(WrongAnimal const & other);
        ~WrongAnimal(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        WrongAnimal& operator=(WrongAnimal const & other);

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        std::string const & getType(void) const;

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void makeSound(void) const;
};

#endif
