/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 03:52:10 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/24 04:23:01 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Array.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <limits>
#include <new>
#include <string>
#include <cstdlib>
#include <ctime>

/* ========================================================================== */
/* MACROS                                                                     */
/* ========================================================================== */
#define MAX_VAL 750

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point for testing the Array class template.
 * @details Rigorously tests empty initialization, default parameterized 
 * initialization, deep copying, and out-of-bounds exception handling.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. EMPTY ARRAY TEST                                                    */
    /* ---------------------------------------------------------------------- */
    std::cout << "================= 1. EMPTY ARRAY TEST =================" << std::endl;

    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    try
    {
        std::cout << "Trying to access emptyArray[0]..." << std::endl;
        emptyArray[0] = 42;
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Caught array access exception: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 2. PARAMETERIZED ARRAY (DEFAULT INITIALIZATION TEST)                   */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================ 2. DEFAULT INIT TEST =================" << std::endl;

    unsigned int const n = 5;
    Array<int> intArray(n);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    
    std::cout << "Verifying default initialization: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << intArray[i] << (i < intArray.size() - 1 ? " " : "");
    std::cout << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 3. DEEP COPY TEST (COPY CONSTRUCTOR & ASSIGNMENT)                      */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================== 3. DEEP COPY TEST ==================" << std::endl;

    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = (i + 1) * 10;

    Array<int> copyArray(intArray);
    Array<int> assignedArray;
    assignedArray = intArray;

    intArray[0] = 999;

    std::cout << "Original [0] modified to: " << intArray[0] << std::endl;
    std::cout << "Copy Constructor [0]:     " << copyArray[0] << std::endl;
    std::cout << "Assigned Array [0]:       " << assignedArray[0] << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 4. EXCEPTION HANDLING (OUT OF BOUNDS)                                  */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================ 4. OUT OF BOUNDS TEST ================" << std::endl;

    try
    {
        std::cout << "Trying to access intArray[" << n << "]..." << std::endl;
        intArray[n] = 42;
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Caught array access exception: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 5. COMPLEX TYPES (STD::STRING)                                         */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================ 5. COMPLEX TYPE TEST =================" << std::endl;

    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "42";
    strArray[2] = "Common Core";

    for (unsigned int i = 0; i < strArray.size(); i++)
        std::cout << strArray[i] << (i < strArray.size() - 1 ? " " : "");
    std::cout << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 6. 42 INTRA PROVIDED TESTS                                             */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================== 6. 42 INTRA TESTS ==================" << std::endl;
    
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; ++i)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; ++i)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return EXIT_FAILURE;
        }
    }

    try
    {
        numbers[-2] = 0;
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Caught array access exception: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Caught array access exception: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; ++i)
        numbers[i] = rand();
    
    delete [] mirror;

    /* ---------------------------------------------------------------------- */
    /* 7. MEMORY ALLOCATION FAILURE TEST                                      */
    /* ---------------------------------------------------------------------- */
    // std::cout << "\n================== 7. BAD ALLOC TEST ==================" << std::endl;

    // try
    // {
    //     std::cout << "Attempting to allocate a massive array..." << std::endl;
    //     Array<int> massiveArray(std::numeric_limits<unsigned int>::max()); 
    //     std::cout << "Allocation succeeded! (You have a massive amount of RAM)" << std::endl;
    // }
    // catch (std::bad_alloc const & e)
    // {
    //     std::cerr << "Caught memory allocation exception: " << e.what() << std::endl;
    // }
    // catch (std::exception const & e)
    // {
    //     std::cerr << "Caught exception: " << e.what() << std::endl;
    // }

    return EXIT_SUCCESS;
}
