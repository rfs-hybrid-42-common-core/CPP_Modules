/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 01:30:01 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 02:44:21 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Fixed.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point for testing the Fixed class (Exercise 02).
 * @details Performs a comprehensive suite of tests to verify all arithmetic,
 * comparison, increment/decrement operators, and min/max functions.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. SUBJECT DEFAULT TESTS                                               */
    /* ---------------------------------------------------------------------- */
    std::cout << "================= SUBJECT TESTS =================" << std::endl;
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 2. ARITHMETIC OPERATORS                                                */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n=============== ARITHMETIC TESTS ================" << std::endl;
    Fixed const c(10.5f);
    Fixed const d(2.0f);

    std::cout << "c: " << c << " | d: " << d << std::endl;
    std::cout << "Addition (c + d): " << (c + d) << std::endl;
    std::cout << "Subtraction (c - d): " << (c - d) << std::endl;
    std::cout << "Multiplication (c * d): " << (c * d) << std::endl;
    std::cout << "Division (c / d): " << (c / d) << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 3. COMPARISON OPERATORS                                                */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n=============== COMPARISON TESTS ================" << std::endl;
    Fixed const e(42.42f);
    Fixed const f(42.42f);
    Fixed const g(10.0f);

    std::cout << std::boolalpha;
    std::cout << "e: " << e << " | f: " << f << " | g: " << g << std::endl;
    std::cout << "Greater than (e > g): " << (e > g) << std::endl;
    std::cout << "Less than (g < e): " << (g < e) << std::endl;
    std::cout << "Greater or equal (e >= f): " << (e >= f) << std::endl;
    std::cout << "Less or equal (f <= e): " << (f <= e) << std::endl;
    std::cout << "Equal (e == f): " << (e == f) << std::endl;
    std::cout << "Not equal (e != g): " << (e != g) << std::endl;
    std::cout << std::noboolalpha;

    /* ---------------------------------------------------------------------- */
    /* 4. DECREMENT OPERATORS                                                 */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================ DECREMENT TESTS ================" << std::endl;
    Fixed h(5.0f);

    std::cout << "Initial h: " << h << std::endl;
    std::cout << "Pre-decrement (--h): " << --h << std::endl;
    std::cout << "After pre-decrement: " << h << std::endl;
    std::cout << "Post-decrement (h--): " << h-- << std::endl;
    std::cout << "After post-decrement: " << h << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 5. MIN / MAX FUNCTIONS                                                 */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================= MIN/MAX TESTS =================" << std::endl;
    Fixed i(100.5f);
    Fixed j(200.5f);
    Fixed const k(300.5f);
    Fixed const l(400.5f);

    std::cout << "Non-const i: " << i << " | j: " << j << std::endl;
    std::cout << "Min of i, j: " << Fixed::min(i, j) << std::endl;
    std::cout << "Max of i, j: " << Fixed::max(i, j) << std::endl;

    std::cout << "\nConst k: " << k << " | l: " << l << std::endl;
    std::cout << "Min of k, l: " << Fixed::min(k, l) << std::endl;
    std::cout << "Max of k, l: " << Fixed::max(k, l) << std::endl;

    return EXIT_SUCCESS;
}
