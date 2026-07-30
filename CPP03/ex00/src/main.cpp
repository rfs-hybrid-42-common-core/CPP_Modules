/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:55:56 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/03 18:10:10 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "ClapTrap.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point for testing the ClapTrap class.
 * @details Performs a suite of tests including standard actions, energy 
 * depletion, health depletion (death), and verifying Orthodox Canonical Form 
 * compliance (copy constructors and assignment operators).
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. CONSTRUCTORS & BASIC ACTIONS                                        */
    /* ---------------------------------------------------------------------- */
    std::cout << "=========== 1. CONSTRUCTORS & BASIC ACTIONS ===========" << std::endl;

    ClapTrap vaultHunter("VaultHunter");
    ClapTrap handsomeJack("HandsomeJack");

    vaultHunter.attack("HandsomeJack");
    handsomeJack.takeDamage(0); 
    handsomeJack.beRepaired(5);

    /* ---------------------------------------------------------------------- */
    /* 2. ENERGY DEPLETION TEST                                               */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============== 2. ENERGY DEPLETION TEST ===============" << std::endl;

    for (int i = 0; i < 9; ++i)
        vaultHunter.attack("HandsomeJack");
    
    std::cout << "\n--- Attempting actions with 0 energy ---" << std::endl;
    vaultHunter.attack("HandsomeJack");
    vaultHunter.beRepaired(5);

    /* ---------------------------------------------------------------------- */
    /* 3. ORTHODOX CANONICAL FORM TESTS                                       */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============= 3. ORTHODOX CANONICAL FORM ==============" << std::endl;

    ClapTrap tyreen("Tyreen");
    tyreen.takeDamage(5);

    std::cout << "\n--- Copy Constructor Test ---" << std::endl;
    ClapTrap troy(tyreen); 
    troy.attack("Fl4k");

    std::cout << "\n--- Copy Assignment Operator Test ---" << std::endl;
    ClapTrap calypso("Calypso");
    calypso = tyreen; 
    calypso.attack("Moze");

    /* ---------------------------------------------------------------------- */
    /* 4. HEALTH DEPLETION (DEATH) TEST                                       */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================= 5. DEATH (HP) TEST ==================" << std::endl;

    ClapTrap maliwan("Maliwan");
    
    maliwan.takeDamage(15); 
    
    std::cout << "\n--- Attempting actions with 0 HP ---" << std::endl;
    maliwan.attack("VaultHunter");
    maliwan.beRepaired(5);
    maliwan.takeDamage(10);

    /* ---------------------------------------------------------------------- */
    /* 5. DESTRUCTORS                                                         */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n=================== 5. DESTRUCTORS ====================" << std::endl;
    
    return EXIT_SUCCESS;
}
