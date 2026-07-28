/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:55:27 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/27 21:10:02 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <string>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief Entry point of the program.
 * @details Demystifies C++ references by comparing them directly to pointers. 
 * Initializes a string, a pointer to the string (stringPTR), and a reference 
 * to the string (stringREF). It then prints the memory addresses and values 
 * of all three to demonstrate that references act as aliases sharing the 
 * exact same memory address as the original variable.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    std::string  stringVAR = "HI THIS IS BRAIN";
    std::string  *stringPTR = &stringVAR;
    std::string& stringREF = stringVAR;

    std::cout << "Memory address of stringVAR: " << &stringVAR
              << "\nMemory address of stringPTR: " << stringPTR
              << "\nMemory address of stringREF: " << &stringREF
              << "\n\nValue of stringVAR: " << stringVAR
              << "\nValue of stringPTR: " << *stringPTR
              << "\nValue of stringREF: " << stringREF << std::endl;

    return EXIT_SUCCESS;
}
