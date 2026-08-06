/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:39:51 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 03:26:09 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>
#include <ctime>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief Thoroughly tests the Bureaucrat and Concrete Form classes.
 * @details Initializes the random number generator, then tests Bureaucrat 
 * limits, abstract form polymorphism, signature requirements, and execution 
 * requirements (including the Template Method Pattern execution checks).
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* Initialize random seed for the RobotomyRequestForm */
    std::srand(static_cast<unsigned int>(std::time(NULL)));

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
    /* 3. CONCRETE FORMS INSTANTIATION & OCF                                  */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n=============== 3. CONCRETE FORMS & OCF ===============" << std::endl;
    try
    {
        Bureaucrat topDog("Top Dog", 1);

        std::cout << "--- Shrubbery Parameterized Constructor ---" << std::endl;
        ShrubberyCreationForm shrub("Garden");
        std::cout << shrub << std::endl;

        std::cout << "\n--- Robotomy Copy Constructor ---" << std::endl;
        RobotomyRequestForm robo("Bender");
        topDog.signForm(robo);
        
        RobotomyRequestForm roboClone(robo);
        std::cout << "Original:\n" << robo << std::endl;
        std::cout << "Clone:\n" << roboClone << std::endl;

        std::cout << "\n--- Presidential Copy Assignment ---" << std::endl;
        PresidentialPardonForm prez1("Arthur Dent");
        PresidentialPardonForm prez2("Ford Prefect");
        
        topDog.signForm(prez1);
        
        std::cout << "Before Assignment (prez2 is NOT signed):\n" << prez2 << std::endl;
        prez2 = prez1;
        std::cout << "After Assignment (prez2 should now be signed):\n" << prez2 << std::endl;
    }
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (AForm::Exception const & e)
    {
        std::cerr << "Form specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 4. SHRUBBERY CREATION FORM TESTS (Sign: 145, Exec: 137)                */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================ 4. SHRUBBERY TESTS ===================" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 150);
        Bureaucrat mid("Mid-level", 140);
        Bureaucrat senior("Senior", 130);
        ShrubberyCreationForm shrub("Home");

        std::cout << "\n--- Attempt: Execute Unsigned Form ---" << std::endl;
        senior.executeForm(shrub);

        std::cout << "\n--- Attempt: Sign with Low Grade ---" << std::endl;
        intern.signForm(shrub);

        std::cout << "\n--- Attempt: Sign Successfully ---" << std::endl;
        mid.signForm(shrub);

        std::cout << "\n--- Attempt: Execute with Low Grade ---" << std::endl;
        mid.executeForm(shrub);

        std::cout << "\n--- Attempt: Execute Successfully ---" << std::endl;
        senior.executeForm(shrub);
    }
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (AForm::Exception const & e)
    {
        std::cerr << "Form specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 5. ROBOTOMY REQUEST FORM TESTS (Sign: 72, Exec: 45)                    */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================= 5. ROBOTOMY TESTS ===================" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robo("Claptrap");

        std::cout << "\n--- Signing Robotomy Form ---" << std::endl;
        boss.signForm(robo);

        std::cout << "\n--- Executing Multiple Times (50% Chance) ---" << std::endl;
        boss.executeForm(robo);
        boss.executeForm(robo);
        boss.executeForm(robo);
        boss.executeForm(robo);
    }
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (AForm::Exception const & e)
    {
        std::cerr << "Form specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 6. PRESIDENTIAL PARDON FORM TESTS (Sign: 25, Exec: 5)                  */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n=============== 6. PRESIDENTIAL TESTS =================" << std::endl;
    try
    {
        Bureaucrat president("Zaphod", 1);
        Bureaucrat manager("Manager", 20);
        PresidentialPardonForm pardon("Trillian");

        std::cout << "\n--- Sign Successfully ---" << std::endl;
        manager.signForm(pardon);

        std::cout << "\n--- Execute with Low Grade ---" << std::endl;
        manager.executeForm(pardon);

        std::cout << "\n--- Execute Successfully ---" << std::endl;
        president.executeForm(pardon);
    }
    catch (Bureaucrat::Exception const & e)
    {
        std::cerr << "Bureaucrat specific error caught: " << e.what() << std::endl;
    }
    catch (AForm::Exception const & e)
    {
        std::cerr << "Form specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
