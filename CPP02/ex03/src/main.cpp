/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 01:30:01 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 02:59:08 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Point.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <string>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn static void printTestResult(std::string const & testName, bool result, 
 * bool expected)
 * @brief Evaluates and prints the result of a BSP test.
 * @details Compares the actual bsp() output with the expected outcome and 
 * formats it into a readable console message.
 * @param testName A descriptive name for the test.
 * @param result   The actual boolean result returned by bsp().
 * @param expected The expected boolean result.
 */
static void printTestResult(std::string const & testName, bool result, bool expected)
{
    std::cout << testName << ": ";
    std::cout << (result == expected ? "[PASS]" : "[FAIL]");   
    std::cout << " (Got: " << (result ? "true" : "false") 
              << " | Expected: " << (expected ? "true" : "false") << ")" << std::endl;
}

/**
 * @fn int main(void)
 * @brief The main execution point for testing the BSP function.
 * @details Performs a suite of tests including integer coordinates, floating 
 * point coordinates, and strict edge-case evaluations (vertices and edges).
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    std::cout << std::boolalpha;

    /* ---------------------------------------------------------------------- */
    /* 1. BASIC INTEGER TRIANGLE TESTS                                        */
    /* ---------------------------------------------------------------------- */
    std::cout << "============= INTEGER TRIANGLE TESTS ============" << std::endl;
    Point const a1;
    Point const b1(10, 0);
    Point const c1(0, 10);

    Point const p1_inside(2, 2);
    Point const p1_outside(10, 10);

    printTestResult("Point strictly inside", bsp(a1, b1, c1, p1_inside), true);
    printTestResult("Point strictly outside", bsp(a1, b1, c1, p1_outside), false);

    /* ---------------------------------------------------------------------- */
    /* 2. FLOATING-POINT TRIANGLE TESTS                                       */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n========== FLOATING-POINT TRIANGLE TESTS ========" << std::endl;
    Point const a2(0.5f, 0.5f);
    Point const b2(5.5f, 0.5f);
    Point const c2(3.0f, 5.5f);

    Point const p2_inside(3.0f, 2.5f);
    Point const p2_outside(3.0f, 6.0f);
    Point const p2_close_in(3.0f, 0.6f);
    Point const p2_close_out(3.0f, 0.4f);

    printTestResult("Float point inside", bsp(a2, b2, c2, p2_inside), true);
    printTestResult("Float point outside", bsp(a2, b2, c2, p2_outside), false);
    printTestResult("Float point just inside (epsilon)", bsp(a2, b2, c2, p2_close_in), true);
    printTestResult("Float point just outside (epsilon)", bsp(a2, b2, c2, p2_close_out), false);

    /* ---------------------------------------------------------------------- */
    /* 3. EDGE CASES (Must return FALSE if on edge or vertex)                 */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================= STRICT EDGE TESTS ================" << std::endl;
    // Reusing the first triangle: A(0,0), B(10,0), C(0,10)
    
    Point const edge_bottom(5.0f, 0.0f);
    Point const edge_left(0.0f, 5.0f);
    Point const edge_hypotenuse(5.0f, 5.0f);

    printTestResult("Point exactly on Vertex A", bsp(a1, b1, c1, a1), false);
    printTestResult("Point exactly on Vertex B", bsp(a1, b1, c1, b1), false);
    printTestResult("Point exactly on Vertex C", bsp(a1, b1, c1, c1), false);
    printTestResult("Point exactly on bottom edge", bsp(a1, b1, c1, edge_bottom), false);
    printTestResult("Point exactly on left edge", bsp(a1, b1, c1, edge_left), false);
    printTestResult("Point exactly on hypotenuse", bsp(a1, b1, c1, edge_hypotenuse), false);

    std::cout << "=================================================" << std::endl;

    return EXIT_SUCCESS;
}
