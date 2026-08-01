/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 20:39:36 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/04 04:32:33 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* --------------------------- Forward Declarations ------------------------- */
class ICharacter;

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class AMateria
 * @brief Abstract base class for all Materia objects.
 * @details Defines the core attributes and behaviors of a Materia, including 
 * the Prototype pattern requirement (clone) and the default use behavior.
 */
class AMateria
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
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(AMateria const & other);
        virtual ~AMateria(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        AMateria& operator=(AMateria const & other);

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        std::string const & getType() const;

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        virtual AMateria* clone(void) const = 0;
        virtual void      use(ICharacter& target);
};

#endif
