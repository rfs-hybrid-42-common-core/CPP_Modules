/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:11:50 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/28 02:35:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief Entry point of the program.
 * @details Executes the specific test code provided by the subject. It tests 
 * HumanA, which takes a weapon reference in its constructor and is always 
 * armed. It then tests HumanB, which starts unarmed and takes a weapon pointer 
 * via a setter function. Both test cases demonstrate that modifying the 
 * original Weapon object correctly updates the output of the attack() method 
 * because both humans hold references/pointers to the original memory address, 
 * not independent copies.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    return EXIT_SUCCESS;
}
