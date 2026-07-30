/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 01:36:04 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/31 02:50:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

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
 * @class FragTrap
 * @brief Represents a heavy-duty robot fighter, derived from ClapTrap.
 * @details Inherits from ClapTrap but features maximum stats (100 HP, 
 * 100 Energy, 30 DPS), unique combat/status messages, and a special 
 * positive high-five request ability.
 */
class FragTrap : public ClapTrap
{
    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        FragTrap(void);
        FragTrap(std::string const & name);
        FragTrap(FragTrap const & other);
		~FragTrap(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        FragTrap& operator=(FragTrap const & other);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
