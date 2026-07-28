/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:18:52 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/27 17:10:28 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Zombie.hpp"

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn Zombie* newZombie(std::string name)
 * @brief Creates a new Zombie on the heap.
 * @details Allocates a new Zombie object dynamically so it can be used outside 
 * of the function scope. The caller is responsible for deleting the object 
 * to avoid memory leaks.
 * @param name The name to give to the newly created zombie.
 * @return     A pointer to the allocated Zombie object.
 */
Zombie* newZombie(std::string name)
{
    Zombie *zombie = new Zombie(name);
    return zombie;
}
