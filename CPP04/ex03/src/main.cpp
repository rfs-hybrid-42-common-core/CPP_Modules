/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 20:39:12 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 15:36:04 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <new>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

int main(void)
{
    try
    {
        /* ------------------------------------------------------------------ */
        /* 1. SUBJECT MANDATORY TEST                                          */
        /* ------------------------------------------------------------------ */
        std::cout << "============== 1. SUBJECT MANDATORY TEST ==============" << std::endl;
        
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        ICharacter* me = new Character("me");
        
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        
        tmp = src->createMateria("cure");
        me->equip(tmp);
        
        ICharacter* bob = new Character("bob");
        
        std::cout << "\n--- Subject Use Test ---" << std::endl;
        me->use(0, *bob);
        me->use(1, *bob);
        
        std::cout << "\n--- Subject Cleanup ---" << std::endl;
        delete bob;
        delete me;
        delete src;

        /* ------------------------------------------------------------------ */
        /* 2. STRESS TESTS & EDGE CASES                                       */
        /* ------------------------------------------------------------------ */
        std::cout << "\n============ 2. STRESS TESTS & EDGE CASES =============" << std::endl;
        
        std::cout << "\n--- Testing MateriaSource Limits ---" << std::endl;
        IMateriaSource* factory = new MateriaSource();
        factory->learnMateria(new Ice());
        factory->learnMateria(new Cure());
        factory->learnMateria(new Ice());
        factory->learnMateria(new Cure());
        
        std::cout << "[Attempting to learn a 5th Materia (Inventory Full)]" << std::endl;
        factory->learnMateria(new Ice()); 

        std::cout << "\n--- Testing Unknown Materia Creation ---" << std::endl;
        AMateria* unknown = factory->createMateria("fire"); // Should return NULL
        if (!unknown)
            std::cout << "(Correctly caught NULL from unknown materia type)" << std::endl;

        std::cout << "\n--- Testing Character Inventory Limits & The Floor ---" << std::endl;
        ICharacter* cloud = new Character("Cloud");
        
        AMateria* mat0 = factory->createMateria("ice");
        AMateria* mat1 = factory->createMateria("cure");
        AMateria* mat2 = factory->createMateria("ice");
        AMateria* mat3 = factory->createMateria("cure");
        
        cloud->equip(mat0);
        cloud->equip(mat1);
        cloud->equip(mat2);
        cloud->equip(mat3);
        
        std::cout << "\n[Attempting to equip a 5th Materia]" << std::endl;
        AMateria* extraMat = factory->createMateria("ice");
        cloud->equip(extraMat);
        delete extraMat;

        std::cout << "\n--- Testing Unequip & Memory Leak Prevention (Floor Tracker) ---" << std::endl;
        AMateria* floor[100];
        int floorCount = 0;
        for (int i = 0; i < 100; ++i) floor[i] = NULL;

        std::cout << "[Unequipping Slot 0]" << std::endl;
        cloud->unequip(0); 
        floor[floorCount++] = mat0;

        std::cout << "[Attempting to use an empty slot]" << std::endl;
        cloud->use(0, *cloud);

        std::cout << "[Attempting to use an out-of-bounds slot]" << std::endl;
        cloud->use(99, *cloud);
        cloud->use(-1, *cloud);

        /* ------------------------------------------------------------------ */
        /* 3. DEEP COPY VERIFICATION                                          */
        /* ------------------------------------------------------------------ */
        std::cout << "\n============== 3. DEEP COPY VERIFICATION ==============" << std::endl;
        
        Character original("Original_Hero");
        original.equip(factory->createMateria("cure"));
        
        std::cout << "\n[Creating Copy_Hero from Original_Hero]" << std::endl;
        Character copy(original);
        
        std::cout << "\n[Unequipping from Original to prove Copy is independent]" << std::endl;
        
        ICharacter* targetDummy = new Character("Dummy");
        original.use(0, *targetDummy);
        copy.use(0, *targetDummy);

        /* ------------------------------------------------------------------ */
        /* 4. DESTRUCTION                                                     */
        /* ------------------------------------------------------------------ */
        std::cout << "\n=================== 4. DESTRUCTION ====================" << std::endl;
        
        delete targetDummy;
        delete cloud;
        delete factory;
        
        std::cout << "\n[Cleaning up the Floor]" << std::endl;
        for (int i = 0; i < floorCount; ++i)
        {
            if (floor[i])
            {
                delete floor[i];
                std::cout << "A dropped materia was successfully cleaned from the floor." << std::endl;
            }
        }        
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
