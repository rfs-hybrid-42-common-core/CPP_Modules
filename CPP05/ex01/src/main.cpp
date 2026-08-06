/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:39:51 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 02:37:36 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Bureaucrat.hpp"
#include "Form.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief Thoroughly tests the Bureaucrat and Form classes, limits, and OCF.
 * @details Instantiates bureaucrats and forms with valid and invalid bounds, 
 * tests grade modifications, signing procedures, catches expected exceptions, 
 * and meticulously verifies Orthodox Canonical Form compliance for both classes 
 * as required by the subject.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. STANDARD INSTANTIATION & METHODS (BUREAUCRAT)                       */
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
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 2. EXCEPTION HANDLING: CONSTRUCTORS (BUREAUCRAT)                       */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n========== 2. EXCEPTION TESTS: CONSTRUCTORS ===========" << std::endl;

    std::cout << "--- Constructor Too High Test ---" << std::endl;
    try
    {
        Bureaucrat tooHigh("Icarus", 0);
        std::cout << tooHigh << std::endl;
    }
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Constructor Too Low Test ---" << std::endl;
    try
    {
        Bureaucrat tooLow("Slacker", 151);
        std::cout << tooLow << std::endl;
    }
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 3. EXCEPTION HANDLING: MODIFIERS (BUREAUCRAT)                          */
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
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Decrement Out of Bounds Test ---" << std::endl;
    try
    {
        Bureaucrat bottom("Intern", 150);
        std::cout << bottom << std::endl;
        bottom.decrementGrade();
        std::cout << "This line should not print." << std::endl;
    }
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 4. ORTHODOX CANONICAL FORM TESTS (BUREAUCRAT)                          */
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
        Bureaucrat& bobRef = bob;
        bob = bobRef;
    }
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 5. FORM INSTANTIATION & OCF                                            */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============= 5. FORM INSTANTIATION & OCF =============" << std::endl;
    try
    {
        Bureaucrat manager("Manager", 10);
        Form       taxForm("Tax Form", 50, 25);
        
        std::cout << "\n--- Signing Form before Copying ---" << std::endl;
        manager.signForm(taxForm);
        std::cout << taxForm << std::endl;

        std::cout << "\n--- Form Copy Constructor ---" << std::endl;
        Form taxFormClone(taxForm);
        std::cout << taxFormClone << std::endl;

        std::cout << "\n--- Form Copy Assignment ---" << std::endl;
        Form blankForm;
        std::cout << "Before Assignment:\n" << blankForm << std::endl;
        blankForm = taxForm;
        std::cout << "After Assignment (Only _isSigned changes due to const attributes):\n" << blankForm << std::endl;
    }
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (Form::Exception const & e)
    {
        std::cerr << "Form specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 6. EXCEPTION HANDLING: FORM CONSTRUCTORS                               */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n========== 6. FORM EXCEPTIONS: CONSTRUCTORS ===========" << std::endl;

    std::cout << "--- Form Grade to Sign Too High ---" << std::endl;
    try
    {
        Form impossibleForm("Impossible", 0, 50);
    }
    catch (Form::Exception const & e)
    {
        std::cerr << "Form specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Form Grade to Execute Too Low ---" << std::endl;
    try
    {
        Form lazyForm("Lazy", 50, 151);
    }
    catch (Form::Exception const & e)
    {
        std::cerr << "Form specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 7. FORM SIGNING PROCESS                                                */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n=============== 7. FORM SIGNING PROCESS ===============" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Form       contract("Important Contract", 20, 10);

        std::cout << "\n--- Attempt: Grade Too Low ---" << std::endl;
        intern.signForm(contract);
        std::cout << "\nForm Status after failed attempt:\n" << contract << std::endl;

        std::cout << "\n--- Attempt: Sufficient Grade ---" << std::endl;
        boss.signForm(contract);
        std::cout << "\nForm Status after successful attempt:\n" << contract << std::endl;

        std::cout << "\n--- Attempt: Already Signed Form ---" << std::endl;
        boss.signForm(contract);
    }
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (Form::Exception const & e)
    {
        std::cerr << "Form specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
