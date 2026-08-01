/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 05:38:23 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 02:30:04 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <new>
#include <cstdlib>

/**
 * @fn int main(void)
 * @brief The main execution point for testing Subtype Polymorphism.
 * @details Instantiates Animal, Dog, Cat, WrongAnimal, and WrongCat objects 
 * through dynamic and stack allocation to comprehensively test and compare 
 * dynamic binding against static binding. Also verifies Orthodox Canonical 
 * Form compliance.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. SUBJECT MANDATORY TESTS (DYNAMIC BINDING)                           */
    /* ---------------------------------------------------------------------- */
    try
    {
        std::cout << "============= 1. SUBJECT MANDATORY TESTS ==============" << std::endl;

        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        std::cout << "\n--- Types ---" << std::endl;
        std::cout << "j is a: " << j->getType() << " " << std::endl;
        std::cout << "i is a: " << i->getType() << " " << std::endl;
        std::cout << "meta is a: " << meta->getType() << " " << std::endl;
        
        std::cout << "\n--- Sounds (Should be specific) ---" << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        
        std::cout << "\n--- Destruction ---" << std::endl;
        delete i;
        delete j;
        delete meta;
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        return EXIT_FAILURE;
    }

    /* ---------------------------------------------------------------------- */
    /* 2. WRONG CLASSES TESTS (STATIC BINDING)                                */
    /* ---------------------------------------------------------------------- */
    try
    {
        std::cout << "\n=============== 2. WRONG CLASSES TESTS ================" << std::endl;
        
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal* wrongI = new WrongCat();
        
        std::cout << "\n--- Types ---" << std::endl;
        std::cout << "wrongI is a: " << wrongI->getType() << " " << std::endl;
        
        std::cout << "\n--- Sounds (Should be WRONG/Generic) ---" << std::endl;
        wrongI->makeSound();
        wrongMeta->makeSound();
        
        std::cout << "\n--- Destruction ---" << std::endl;
        delete wrongI;
        delete wrongMeta;
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        return EXIT_FAILURE;
    }

    /* ---------------------------------------------------------------------- */
    /* 3. STACK ALLOCATION & DIRECT CALLS                                     */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n========= 3. STACK ALLOCATION & DIRECT CALLS ==========" << std::endl;
 
    {
        Cat stackCat;
        Dog stackDog;
        WrongCat stackWrongCat;

        std::cout << "\n--- Sounds (Should all be correct, even WrongCat) ---" << std::endl;
        stackCat.makeSound();
        stackDog.makeSound();
        stackWrongCat.makeSound();

        std::cout << "\n--- Destruction ---" << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 4. COPY CONSTRUCTOR AND ASSIGNMENT TESTS                               */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n====== 4. COPY CONSTRUCTOR AND ASSIGNMENT TESTS =======" << std::endl;

    {
        std::cout << "--- Dog Copying ---" << std::endl;
        Dog originalDog;
        Dog copyDog(originalDog);
        Dog assignedDog;
        assignedDog = originalDog;

        std::cout << "Original Dog Type: " << originalDog.getType() << std::endl;
        std::cout << "Copied Dog Type: " << copyDog.getType() << std::endl;
        std::cout << "Assigned Dog Type: " << assignedDog.getType() << std::endl;
        
        std::cout << "\n--- Cat Copying ---" << std::endl;
        Cat originalCat;
        Cat copyCat(originalCat);
        
        std::cout << "Original Cat Type: " << originalCat.getType() << std::endl;
        std::cout << "Copied Cat Type: " << copyCat.getType() << std::endl;

        std::cout << "\n--- Destruction ---" << std::endl;
    }

    return EXIT_SUCCESS;
}
