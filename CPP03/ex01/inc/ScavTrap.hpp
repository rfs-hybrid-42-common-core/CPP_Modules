/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:58:53 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/31 01:04:33 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "ClapTrap.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class ScavTrap
 * @brief Represents an upgraded robot fighter, derived from ClapTrap.
 * @details Inherits from ClapTrap but features higher stats (100 HP, 
 * 50 Energy, 20 DPS), unique combat/status messages, and a special 
 * gate-keeper mode.
 */
class ScavTrap : public ClapTrap
{
    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        ScavTrap(void);
        ScavTrap(std::string const & name);
        ScavTrap(ScavTrap const & other);
		~ScavTrap(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        ScavTrap& operator=(ScavTrap const & other);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void attack(const std::string& target);
        void guardGate(void);
};

#endif
