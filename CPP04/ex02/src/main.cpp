/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 05:38:23 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 15:15:41 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <new>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point for testing abstract classes, deep copies, 
 * and memory management.
 * @details Demonstrates that the AAnimal class is purely abstract and cannot 
 * be instantiated. Tests the allocation and deletion of an array of AAnimal 
 * pointers to verify virtual destruction. Also performs deep copy tests using 
 * the Orthodox Canonical Form to ensure Brain objects are properly cloned and 
 * not shared.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 0. ABSTRACT CLASS TEST (UN-INSTANTIABLE PROOF)                         */
    /* ---------------------------------------------------------------------- */
    std::cout << "=============== 0. ABSTRACT CLASS TEST ================" << std::endl;
    std::cout << "Uncommenting the abstract animal instantiation will cause a compilation error!" << std::endl;
    
    // AAnimal testObject; 
    // const AAnimal* testPointer = new AAnimal();
    
    std::cout << "[Proof successful: Code compiles because instantiation is commented out.]" << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 1. SUBJECT BASIC TEST SCRIPT                                           */
    /* ---------------------------------------------------------------------- */
    try
    {
        std::cout << "\n================ 1. SUBJECT BASIC TEST ================" << std::endl;
        
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();
        
        std::cout << "\n--- Destruction ---" << std::endl;
        delete j;
        delete i;
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        return EXIT_FAILURE;
    }

    /* ---------------------------------------------------------------------- */
    /* 2. SUBJECT MANDATORY TEST (ARRAY OF ANIMALS)                           */
    /* ---------------------------------------------------------------------- */
    try
    {
        std::cout << "\n============= 2. SUBJECT MANDATORY TEST  ==============" << std::endl;
        
        int const arraySize = 10;
        AAnimal* animals[arraySize];

        std::cout << "\n--- Allocating " << arraySize << " Animals (Half Dogs, Half Cats) ---" << std::endl;
        for (int i = 0; i < arraySize; ++i)
        {
            if (i < arraySize / 2)
            {
                std::cout << "\n[Allocating Dog " << i << "]" << std::endl;
                animals[i] = new Dog();
            }
            else
            {
                std::cout << "\n[Allocating Cat " << i << "]" << std::endl;
                animals[i] = new Cat();
            }
        }

        std::cout << "\n--- Testing Polymorphic Sounds ---" << std::endl;
        for (int i = 0; i < arraySize; ++i)
            animals[i]->makeSound();

        std::cout << "\n--- Deleting Animals (Checking virtual destructors) ---" << std::endl;
        for (int i = 0; i < arraySize; ++i)
        {
            std::cout << "\n[Deleting Animal " << i << "]" << std::endl;
            delete animals[i];
        }
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        return EXIT_FAILURE;
    }

    /* ---------------------------------------------------------------------- */
    /* 3. DEEP COPY VERIFICATION TESTS                                        */
    /* ---------------------------------------------------------------------- */
    try 
    {
        std::cout << "\n============== 3. DEEP COPY VERIFICATION ==============" << std::endl;
        
        std::cout << "\n--- Creating Original Dog ---" << std::endl;
        Dog originalDog;
        originalDog.setIdea(0, "I want to chase the postman.");
        originalDog.setIdea(1, "I should dig a hole.");
        
        std::cout << "Original Dog Idea 0: " << originalDog.getIdea(0) << std::endl;
        std::cout << "Original Dog Idea 1: " << originalDog.getIdea(1) << std::endl;

        std::cout << "\n--- Creating Copied Dog (Using Copy Constructor) ---" << std::endl;
        Dog copyDog(originalDog);
        std::cout << "Copied Dog Idea 0 (Before Change): " << copyDog.getIdea(0) << std::endl;
        
        std::cout << "\n--- Modifying Copied Dog's Brain ---" << std::endl;
        copyDog.setIdea(0, "I want to sleep on the sofa instead.");
        std::cout << "Copied Dog Idea 0 (After Change): " << copyDog.getIdea(0) << std::endl;
        
        std::cout << "\n--- Verifying Original Dog is UNCHANGED ---" << std::endl;
        std::cout << "Original Dog Idea 0: " << originalDog.getIdea(0) << " <- (PROVES DEEP COPY)" << std::endl;

        std::cout << "\n--- Testing Assignment Operator with Cat ---" << std::endl;
        Cat originalCat;
        originalCat.setIdea(0, "Push glass off table.");
        
        Cat assignedCat;
        assignedCat = originalCat;
        assignedCat.setIdea(0, "Ignore the human.");
        
        std::cout << "Original Cat Idea 0: " << originalCat.getIdea(0) << std::endl;
        std::cout << "Assigned Cat Idea 0: " << assignedCat.getIdea(0) << " <- (PROVES DEEP COPY)" << std::endl;
        
        std::cout << "\n--- Destruction ---" << std::endl;
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
