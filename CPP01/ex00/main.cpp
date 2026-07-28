/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:18:16 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/27 17:50:15 by maaugust         ###   ########.fr       */
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
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief Entry point of the program.
 * @details Tests the creation of a Zombie on the stack via randomChump, 
 * followed by the creation of a Zombie on the heap via newZombie. The heap 
 * allocation is protected by a try-catch block to gracefully handle potential 
 * std::bad_alloc exceptions. The heap zombie is then manually deleted to 
 * ensure no memory leaks occur.
 * @return EXIT_SUCCESS upon successful execution, or EXIT_FAILURE if a 
 * memory allocation error occurs.
 */
int main(void)
{
    randomChump("");
    randomChump("Stack");

    try 
    {
        Zombie *heap = newZombie("Heap");
        heap->announce();
        delete heap;
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
