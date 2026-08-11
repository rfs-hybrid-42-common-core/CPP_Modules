/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 03:19:47 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 15:07:04 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <new>
#include <cstdlib>
#include <ctime>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief Execution entry point for the type identification tests.
 * @details Seeds the random number generator, then repeatedly generates random 
 * derived objects. Passes them to both identify() overloads to verify that 
 * dynamic_cast correctly deduces the runtime type without using <typeinfo>.
 * Wraps the execution scopes in try-catch blocks to safely intercept any 
 * std::bad_alloc exceptions thrown by the 'new' operator during instantiation.
 * @return EXIT_SUCCESS upon successful completion, or EXIT_FAILURE if a 
 * critical memory allocation error occurs.
 */
int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "================= DYNAMIC CAST TESTS ==================" << std::endl;

    try
    {
        for (int i = 0; i < 5; ++i)
        {
            std::cout << "\n--- Test " << (i + 1) << " ---" << std::endl;

            Base* randomBase = generate();
            if (!randomBase)
                continue;

            identify(randomBase);
            identify(*randomBase);

            delete randomBase;
        }
    }
    catch (std::bad_alloc const & e)
    {
        std::cerr << "CRITICAL ERROR: Memory allocation failed (" << e.what() << ")." << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "\n================== UNKNOWN TYPE TEST ==================" << std::endl;

    try
    {
        std::cout << "\n--- Test 6 (Raw Base Object) ---" << std::endl;

        Base* baseObj = new Base();
        if (baseObj)
        {
            identify(baseObj);
            identify(*baseObj);

            delete baseObj;
        }
    }
    catch (std::bad_alloc const & e)
    {
        std::cerr << "CRITICAL ERROR: Memory allocation failed (" << e.what() << ")." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
