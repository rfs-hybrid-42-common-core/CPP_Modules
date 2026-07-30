/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:22:52 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/31 14:52:12 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class DiamondTrap
 * @brief Represents a hybrid robot fighter, inheriting from ScavTrap and FragTrap.
 * @details Solves the diamond problem using virtual inheritance. It takes 
 * its HP and DPS from FragTrap, but its Energy and attack() from ScavTrap.
 * It features a unique whoAmI() ability and intentionally shadows the base 
 * ClapTrap name attribute.
 */
class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        std::string _name;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        DiamondTrap(void);
        DiamondTrap(std::string const & name);
        DiamondTrap(DiamondTrap const & other);
        ~DiamondTrap(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        DiamondTrap& operator=(DiamondTrap const & other);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        using ScavTrap::attack;
        void whoAmI(void);
};

#endif
