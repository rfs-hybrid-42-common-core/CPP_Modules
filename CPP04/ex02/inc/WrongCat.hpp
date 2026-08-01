/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 22:30:28 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/01 05:37:52 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "WrongAnimal.hpp"

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class WrongCat
 * @brief Represents a cat, derived from WrongAnimal.
 * @details Implements a WrongCat class in Orthodox Canonical Form to 
 * demonstrate static binding behavior when overriding non-virtual base methods.
 */
class WrongCat : public WrongAnimal
{
    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        WrongCat(void);
        WrongCat(WrongCat const & other);
        ~WrongCat(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        WrongCat& operator=(WrongCat const & other);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void makeSound(void) const;
};

#endif
