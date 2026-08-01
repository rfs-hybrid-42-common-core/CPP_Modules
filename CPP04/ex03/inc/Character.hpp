/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 21:08:51 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 03:42:50 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "ICharacter.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* --------------------------- Forward Declarations ------------------------- */
class AMateria;

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Character
 * @brief Concrete implementation of the ICharacter interface.
 * @details Represents a character in the game that can hold up to 4 Materias 
 * in its inventory, equip them, unequip them, and use them on targets.
 */
class Character : public ICharacter
{
    private:
        /* ------------------------------------------------------------------ */
        /* CONSTANTS & SETTINGS                                               */
        /* ------------------------------------------------------------------ */
        static int const _maxSlots = 4;
    
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        AMateria*   _inventory[_maxSlots];
        std::string _name;
    
    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Character(void);
        Character(std::string const & name);
        Character(Character const & other);
        virtual ~Character(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        Character& operator=(Character const & other);

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        std::string const & getName(void) const;

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);    
};

#endif
