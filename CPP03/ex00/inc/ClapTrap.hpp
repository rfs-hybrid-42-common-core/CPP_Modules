/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:55:54 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/31 00:38:34 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class ClapTrap
 * @brief Represents a basic robot fighter.
 * @details Implements the ClapTrap class in Orthodox Canonical Form with 
 * basic attributes for health, energy, and attack damage, alongside actions 
 * for attacking, taking damage, and repairing.
 */
class ClapTrap
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        std::string _name;
        int         _hp;
        int         _energy;
        int         _dps;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        ClapTrap(void);
        ClapTrap(std::string const & name);
        ClapTrap(ClapTrap const & other);
        ~ClapTrap(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        ClapTrap& operator=(ClapTrap const & other);

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        std::string const & getName(void) const;
        int                 getHp(void) const;
        int                 getEnergy(void) const;
        int                 getDps(void) const;

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
