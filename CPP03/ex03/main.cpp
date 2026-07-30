/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:55:56 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/03 18:11:51 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "DiamondTrap.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point for testing the DiamondTrap class.
 * @details Performs a suite of tests including virtual inheritance chaining,
 * inherited attacks (from ScavTrap), special abilities from all parent classes 
 * (guardGate, highFivesGuys), its own unique ability (whoAmI), and verifying 
 * Orthodox Canonical Form compliance.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. CONSTRUCTION CHAINING & VIRTUAL INHERITANCE                         */
    /* ---------------------------------------------------------------------- */
    std::cout << "======== 1. CONSTRUCTION & VIRTUAL INHERITANCE ========" << std::endl;

    std::cout << "--- Creating DiamondTrap ---" << std::endl;
    DiamondTrap buttStallion("ButtStallion");

    std::cout << "\n--- Testing Inherited Actions ---" << std::endl;
    buttStallion.attack("HandsomeJack");
    buttStallion.takeDamage(50); 
    buttStallion.beRepaired(25);

    /* ---------------------------------------------------------------------- */
    /* 2. SPECIAL ABILITIES (THE HYBRID TEST)                                 */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================ 2. SPECIAL ABILITIES =================" << std::endl;
    
    std::cout << "--- DiamondTrap Unique Ability ---" << std::endl;
    buttStallion.whoAmI();

    std::cout << "\n--- ScavTrap Inherited Ability ---" << std::endl;
    buttStallion.guardGate();

    std::cout << "\n--- FragTrap Inherited Ability ---" << std::endl;
    buttStallion.highFivesGuys();

    /* ---------------------------------------------------------------------- */
    /* 3. ORTHODOX CANONICAL FORM TESTS                                       */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============= 3. ORTHODOX CANONICAL FORM ==============" << std::endl;

    {
        std::cout << "--- Copy Constructor Test ---" << std::endl;
        DiamondTrap diamondStallion(buttStallion); 
        diamondStallion.whoAmI();

        std::cout << "\n--- Copy Assignment Operator Test ---" << std::endl;
        DiamondTrap diamondy("Diamondy");
        diamondy = buttStallion; 
        diamondy.whoAmI();
        
        std::cout << "\n--- Destructor Chaining (Derived -> Base) ---" << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 4. HEALTH DEPLETION (DEATH) TEST                                       */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================= 4. DEATH (HP) TEST ==================" << std::endl;

    buttStallion.takeDamage(100); 
    
    std::cout << "\n--- Attempting actions with 0 HP ---" << std::endl;
    buttStallion.attack("VaultHunter");
    buttStallion.whoAmI();
    buttStallion.guardGate();
    buttStallion.highFivesGuys();

    /* ---------------------------------------------------------------------- */
    /* 5. FINAL DESTRUCTORS                                                   */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================ 5. FINAL DESTRUCTORS =================" << std::endl;
    
    return EXIT_SUCCESS;
}
