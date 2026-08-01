/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 21:39:32 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 03:42:25 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "AMateria.hpp"
#include "ICharacter.hpp"

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Ice
 * @brief Concrete Materia class representing an ice attack spell.
 * @details Inherits from AMateria. Implements the specific clone behavior 
 * and outputs an attacking message when used.
 */
class Ice : public AMateria
{
    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Ice(void);
        Ice(Ice const & other);
        virtual ~Ice(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        Ice& operator=(Ice const & other);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        AMateria* clone(void) const;
        void      use(ICharacter& target);
};

#endif
