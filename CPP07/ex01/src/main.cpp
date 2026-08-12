/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 01:31:35 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/24 04:21:03 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "iter.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <string>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn void printElement(T const & element)
 * @brief A generic print function to test iter with read-only operations.
 * @details Takes its argument by const reference to ensure it can be used 
 * with both mutable and strictly const arrays.
 * @tparam T       The data type of the element.
 * @param  element The array element to print.
 */
template <typename T>
void printElement(T const & element)
{
    std::cout << element << " ";
}

/**
 * @fn void incrementElement(T & element)
 * @brief A generic mutation function to test iter with modifying operations.
 * @details Takes its argument by non-const reference. If this is passed to 
 * iter alongside a const array, the compiler will rightfully throw an error.
 * @tparam T       The data type of the element.
 * @param  element The array element to increment.
 */
template <typename T>
void incrementElement(T & element)
{
    ++element;
}

/**
 * @fn int main(void)
 * @brief The main execution point for testing the iter template.
 * @details Performs a suite of tests including non-const arrays, const arrays, 
 * and complex string arrays to validate genericity and const-correctness.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. NON-CONST INTEGER ARRAY TESTS (MUTATION & READING)                  */
    /* ---------------------------------------------------------------------- */
    std::cout << "================ NON-CONST ARRAY TESTS ================" << std::endl;
    
    int intArray[] = {1, 2, 3, 4, 5};
    size_t const intArrayLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original array: ";
    ::iter(intArray, intArrayLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incrementing elements..." << std::endl;
    ::iter(intArray, intArrayLen, incrementElement<int>);

    std::cout << "Modified array: ";
    ::iter(intArray, intArrayLen, printElement<int>);
    std::cout << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 2. CONST INTEGER ARRAY TESTS (STRICTLY READING)                        */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================== CONST ARRAY TESTS ==================" << std::endl;
    
    int const constIntArray[] = {42, 21, 84, 10, 0};
    size_t const constIntArrayLen = sizeof(constIntArray) / sizeof(constIntArray[0]);

    std::cout << "Const array contents: ";
    ::iter(constIntArray, constIntArrayLen, printElement<int>);
    std::cout << std::endl;

    // Uncommenting the line below will correctly cause a compilation error, 
    // proving the implementation properly enforces const-correctness:
    // ::iter(constIntArray, constIntArrayLen, incrementElement<const int>);

    /* ---------------------------------------------------------------------- */
    /* 3. COMPLEX TYPE ARRAY TESTS (STD::STRING)                              */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================= STRING ARRAY TESTS ==================" << std::endl;

    std::string strArray[] = {"Hello", "42", "Common", "Core", "!"};
    size_t const strArrayLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    ::iter(strArray, strArrayLen, printElement<std::string>);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
