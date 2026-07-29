/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 01:30:01 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/29 02:09:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Fixed.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point for testing the Fixed class.
 * @details Instantiates several Fixed objects using the default constructor, 
 * copy constructor, and copy assignment operator to verify the Orthodox 
 * Canonical Form implementation. Prints the raw bits to standard output.
 * @return 0 upon successful execution.
 */
int main(void)
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
