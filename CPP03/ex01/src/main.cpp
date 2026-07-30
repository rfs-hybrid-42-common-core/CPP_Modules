/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:55:56 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/03 18:08:56 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "ScavTrap.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point for testing the ScavTrap class.
 * @details Performs a suite of tests including construction/destruction chaining,
 * overridden attacks, special abilities (guardGate), and verifying Orthodox 
 * Canonical Form compliance for inherited classes.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. CONSTRUCTION CHAINING & BASIC ACTIONS                               */
    /* ---------------------------------------------------------------------- */
    std::cout << "=========== 1. CONSTRUCTORS & BASIC ACTIONS ===========" << std::endl;

    std::cout << "--- Creating ScavTrap (Notice the Base -> Derived chaining) ---" << std::endl;
    ScavTrap serena("Serena");
    ClapTrap handsomeJack("HandsomeJack");

    std::cout << "\n--- Testing Overridden Actions ---" << std::endl;
    serena.attack("HandsomeJack");
    serena.takeDamage(30); 
    serena.beRepaired(15);

    /* ---------------------------------------------------------------------- */
    /* 2. SPECIAL ABILITY TEST                                                */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================= 2. SPECIAL ABILITY ==================" << std::endl;
    
    serena.guardGate();

    /* ---------------------------------------------------------------------- */
    /* 3. ORTHODOX CANONICAL FORM TESTS (WITH SCOPE DEMONSTRATION)            */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============= 3. ORTHODOX CANONICAL FORM ==============" << std::endl;

    {
        std::cout << "--- Copy Constructor Test ---" << std::endl;
        ScavTrap scraptrap(serena); 
        scraptrap.attack("Psycho");

        std::cout << "\n--- Copy Assignment Operator Test ---" << std::endl;
        ScavTrap scavvy("Scavvy");
        scavvy = serena; 
        scavvy.attack("Skag");
        
        std::cout << "\n--- Destructor Chaining (Derived -> Base) ---" << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 4. HEALTH DEPLETION (DEATH) TEST                                       */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================= 4. DEATH (HP) TEST ==================" << std::endl;
    
    serena.takeDamage(100); 
    
    std::cout << "\n--- Attempting actions with 0 HP ---" << std::endl;
    serena.attack("VaultHunter");
    serena.beRepaired(5);
    serena.guardGate();

    /* ---------------------------------------------------------------------- */
    /* 5. FINAL DESTRUCTORS                                                   */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================ 5. FINAL DESTRUCTORS =================" << std::endl;
    
    return EXIT_SUCCESS;
}
