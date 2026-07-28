/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:19:02 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/27 17:10:45 by maaugust         ###   ########.fr       */
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
 * @fn void randomChump(std::string name)
 * @brief Creates a Zombie on the stack and makes it announce itself.
 * @details Instantiates a Zombie object locally. Because it is allocated on 
 * the stack, it is automatically destroyed when the function scope ends.
 * @param name The name to give to the newly created zombie.
 */
void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}
