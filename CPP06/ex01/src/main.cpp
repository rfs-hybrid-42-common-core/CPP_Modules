/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 01:45:22 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/12 03:30:41 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Serializer.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn static void printTestResult(std::string const & testName, bool result)
 * @brief Evaluates and prints the result of a serialization test.
 * @details Formats the output into a readable console message, indicating 
 * whether the specific data validation passed or failed.
 * @param testName A descriptive name for the test.
 * @param result   The boolean result of the test comparison.
 */
static void printTestResult(std::string const & testName, bool result)
{
    std::cout << testName << ": ";
    std::cout << (result ? "[PASS]" : "[FAIL]") << std::endl;
}

/**
 * @fn int main(void)
 * @brief The main execution point for testing the Serializer class.
 * @details Initializes a Data structure, serializes its address to a uintptr_t,
 * and deserializes it back to a Data pointer. Verifies that the pointers 
 * match exactly and that the data payload remains completely uncorrupted.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. INITIALIZATION                                                      */
    /* ---------------------------------------------------------------------- */
    Data data = {'*', 42, 42.42f, "forty-two"};
    
    std::cout << "================= ORIGINAL DATA STATE =================" << std::endl;
    std::cout << "Data address == " << &data
              << "\nData char    == '" << data.c << "'"
              << "\nData integer == " << data.i
              << "\nData float   == " << data.f
              << "\nData string  == " << data.str << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 2. SERIALIZATION & DESERIALIZATION                                     */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================ SERIALIZATION PROCESS ================" << std::endl;
    
    uintptr_t ptr = Serializer::serialize(&data);
    std::cout << "Raw uintptr_t (HEX) == 0x" << std::hex << ptr << std::dec << std::endl;
    std::cout << "Raw uintptr_t (DEC) == " << ptr << std::endl;
    
    Data *pData = Serializer::deserialize(ptr);
    std::cout << "Deserialized ptr    == " << pData << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 3. INTEGRITY TESTS                                                     */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n=================== INTEGRITY TESTS ===================" << std::endl;
    
    printTestResult("Pointers match strictly (pData == &data) ", pData == &data);
    printTestResult("Char   value survived   (pData->c == '*')", pData->c == '*');
    printTestResult("Int    value survived   (pData->i == 42) ", pData->i == 42);
    printTestResult("Float  value survived   (pData->f == 42.42f)", pData->f == 42.42f);
    printTestResult("String value survived   (pData->str == \"forty-two\")", pData->str == "forty-two");

    return EXIT_SUCCESS;
}
