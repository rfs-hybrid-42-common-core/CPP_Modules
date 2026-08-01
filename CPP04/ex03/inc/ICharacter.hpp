/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 20:43:24 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/04 04:30:58 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* --------------------------- Forward Declarations ------------------------- */
class AMateria;

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class ICharacter
 * @brief Interface for Character objects.
 * @details Pure abstract class serving as a contract for character 
 * implementations. Exempt from Orthodox Canonical Form as it contains no state.
 */
class ICharacter
{
    public:
        /* ------------------------------------------------------------------ */
        /* DESTRUCTORS                                                        */
        /* ------------------------------------------------------------------ */
        virtual ~ICharacter(void) {}

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        virtual std::string const & getName(void) const = 0;

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif
