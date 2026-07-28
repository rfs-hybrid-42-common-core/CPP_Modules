/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:18:16 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/27 19:00:22 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Zombie.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <new>
#include <cstddef>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief Entry point of the program.
 * @details Tests the zombieHorde function under various conditions: 
 * creating a horde with an empty base name, attempting to create a horde 
 * with a negative size (which should fail gracefully and return NULL), and 
 * successfully creating a standard horde. Wraps allocations in try-catch 
 * blocks to handle potential std::bad_alloc exceptions and uses 
 * delete [] to ensure no memory leaks occur.
 * @return EXIT_SUCCESS upon successful execution, or EXIT_FAILURE if a 
 * memory allocation error occurs.
 */
int main(void)
{
    int n;

    try 
    {
        n = 5;
        Zombie *horde = zombieHorde(n, "");
        if (horde == NULL)
            std::cout << "Failed to create zombie horde." << std::endl;
        else
        {
            for (int i = 0; i < n; ++i)
                horde[i].announce();
            delete [] horde;
        }
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        return EXIT_FAILURE;
    }

    try 
    {
        n = -10;
        Zombie *horde = zombieHorde(n, "Heap");
        if (horde == NULL)
            std::cout << "Failed to create zombie horde." << std::endl;
        else
        {
            for (int i = 0; i < n; ++i)
                horde[i].announce();
            delete [] horde;
        }
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        return EXIT_FAILURE;
    }

    try 
    {
        n = 10;
        Zombie *horde = zombieHorde(n, "Heap");
        if (horde == NULL)
            std::cout << "Failed to create zombie horde." << std::endl;
        else
        {
            for (int i = 0; i < n; ++i)
                horde[i].announce();
            delete [] horde;
        }
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
