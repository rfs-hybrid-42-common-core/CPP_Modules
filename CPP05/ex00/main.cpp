/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 02:39:07 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/08 17:07:33 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Bureaucrat.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief Thoroughly tests the Bureaucrat class limits, exceptions, and OCF.
 * @details Instantiates bureaucrats with valid and invalid bounds, tests 
 * the increment and decrement functions, catches expected exceptions, and 
 * meticulously verifies Orthodox Canonical Form compliance.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. STANDARD INSTANTIATION & METHODS                                    */
    /* ---------------------------------------------------------------------- */
    std::cout << "========= 1. STANDARD INSTANTIATION & METHODS =========" << std::endl;
    try
    {
        Bureaucrat normal("Chaos", 75);
        std::cout << normal << std::endl;
        
        std::cout << "\n--- Testing Increment ---" << std::endl;
        normal.incrementGrade();
        std::cout << normal << std::endl;
        
        std::cout << "\n--- Testing Decrement ---" << std::endl;
        normal.decrementGrade();
        std::cout << normal << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 2. EXCEPTION HANDLING: CONSTRUCTORS                                    */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n========== 2. EXCEPTION TESTS: CONSTRUCTORS ===========" << std::endl;

    std::cout << "--- Constructor Too High Test ---" << std::endl;
    try
    {
        Bureaucrat tooHigh("Icarus", 0);
        std::cout << tooHigh << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Constructor Too Low Test ---" << std::endl;
    try
    {
        Bureaucrat tooLow("Slacker", 151);
        std::cout << tooLow << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 3. EXCEPTION HANDLING: MODIFIERS                                       */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============ 3. EXCEPTION TESTS: MODIFIERS ============" << std::endl;
    
    std::cout << "--- Increment Out of Bounds Test ---" << std::endl;
    try
    {
        Bureaucrat top("CEO", 1);
        std::cout << top << std::endl;
        top.incrementGrade();
        std::cout << "This line should not print." << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Decrement Out of Bounds Test ---" << std::endl;
    try
    {
        Bureaucrat bottom("Intern", 150);
        std::cout << bottom << std::endl;
        bottom.decrementGrade();
        std::cout << "This line should not print." << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 4. ORTHODOX CANONICAL FORM TESTS                                       */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============= 4. ORTHODOX CANONICAL FORM ==============" << std::endl;
    try
    {
        std::cout << "--- Default Constructor Test ---" << std::endl;
        Bureaucrat john;
        std::cout << "Status: " << john << std::endl;

        std::cout << "\n--- Parameterized Constructor Test ---" << std::endl;
        Bureaucrat bob("Bob", 42);
        std::cout << "Status: " << bob << std::endl;

        std::cout << "\n--- Copy Constructor Test ---" << std::endl;
        Bureaucrat bobClone(bob);
        std::cout << "Original: " << bob << std::endl;
        std::cout << "Clone:    " << bobClone << std::endl;

        std::cout << "\n--- Copy Assignment Operator Test ---" << std::endl;
        std::cout << "Before assignment: " << john << std::endl;
        john = bob;
        std::cout << "After assignment:  " << john << std::endl;

        std::cout << "\n--- Self-Assignment Safety Test ---" << std::endl;
        bob = bob;
    }
    catch (std::exception & e)
    {
        std::cerr << "Unexpected exception caught: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
