/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 22:23:21 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 23:54:06 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Span.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
#include <limits>
#include <cstdlib> 
#include <ctime>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point for testing the Span class.
 * @details Rigorously tests the Span class by executing the mandatory subject 
 * test, verifying exception handling for edge cases (empty/full spans), 
 * testing the generic iterator template with different containers, proving 
 * OCF compliance, and performing large-scale stress tests.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    /* ---------------------------------------------------------------------- */
    /* 1. SUBJECT MANDATORY TEST                                              */
    /* ---------------------------------------------------------------------- */
    std::cout << "=============== 1. SUBJECT EXAMPLE TEST ===============" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
        std::cout << "Longest Span:  " << sp.longestSpan() << " (Expected: 14)" << std::endl;
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Container exception caught: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 2. EDGE CASES (0 NUMBERS, 1 NUMBER, OVERFLOW)                          */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============= 2. EDGE CASES & EXCEPTIONS ==============" << std::endl;

    Span emptySpan(5);
    std::cout << "--- Empty Span Test ---" << std::endl;
    try
    {
        emptySpan.shortestSpan();
    } 
    catch (std::out_of_range const & e)
    {
        std::cerr << "Container exception caught: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    try
    {
        emptySpan.longestSpan();
    } 
    catch (std::out_of_range const & e)
    {
        std::cerr << "Container exception caught: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    Span singleSpan(5);
    singleSpan.addNumber(42);
    std::cout << "\n--- Single Number Span Test ---" << std::endl;
    try
    {
        singleSpan.shortestSpan();
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Container exception caught: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    try
    {
        singleSpan.longestSpan();
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Container exception caught: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    Span fullSpan(2);
    std::cout << "\n--- Capacity Overflow Test ---" << std::endl;
    try
    {
        fullSpan.addNumber(1);
        fullSpan.addNumber(2);
        fullSpan.addNumber(3);
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Container exception caught: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 3. TEMPLATE ITERATOR RANGE (STD::LIST & STD::DEQUE)                    */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============== 3. ITERATOR TEMPLATE TEST ==============" << std::endl;
    try
    {
        Span genericSpan(20);
        
        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(200);
        lst.push_back(300);

        std::deque<int> deq;
        deq.push_front(-50);
        deq.push_front(-150);

        std::cout << "Adding elements from std::list..." << std::endl;
        genericSpan.addNumbers(lst.begin(), lst.end());

        std::cout << "Adding elements from std::deque..." << std::endl;
        genericSpan.addNumbers(deq.begin(), deq.end());

        std::cout << "Shortest Span: " << genericSpan.shortestSpan() << " (Expected: 100)" << std::endl;
        std::cout << "Longest Span:  " << genericSpan.longestSpan() << " (Expected: 450)" << std::endl;
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Container exception caught: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 4. EXTREME LIMITS TEST (UNSIGNED CAST VERIFICATION)                    */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n=============== 4. EXTREME LIMITS TEST ================" << std::endl;
    try
    {
        Span limitsSpan(2);
        limitsSpan.addNumber(std::numeric_limits<int>::min());
        limitsSpan.addNumber(std::numeric_limits<int>::max());
        
        std::cout << "Added INT_MIN and INT_MAX." << std::endl;
        std::cout << "Longest Span (Max potential difference): " << limitsSpan.longestSpan() << std::endl;
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Container exception caught: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 5. 10,000+ NUMBERS STRESS TEST                                         */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n=============== 5. MASSIVE STRESS TEST ================" << std::endl;
    try
    {
        unsigned int const MAX_VAL = 15000;
        Span hugeSpan(MAX_VAL);
        std::vector<int> randomNumbers;
        randomNumbers.reserve(MAX_VAL);

        for (unsigned int i = 0; i < MAX_VAL; ++i)
            randomNumbers.push_back((std::rand() % 1000000) - 500000);

        std::cout << "Inserting " << MAX_VAL << " random integers..." << std::endl;
        hugeSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());
        std::cout << "Insertion complete." << std::endl;

        std::cout << "Shortest Span: " << hugeSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span:  " << hugeSpan.longestSpan() << std::endl;
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Container exception caught: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 6. UNIQUE NUMBERS STRESS TEST (NO DUPLICATES)                          */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============ 6. UNIQUE NUMBERS STRESS TEST ============" << std::endl;
    try
    {
        unsigned int const UNIQUE_MAX = 15000;
        Span uniqueSpan(UNIQUE_MAX);
        std::vector<int> uniqueNumbers;
        uniqueNumbers.reserve(UNIQUE_MAX);

        int currentValue = 0;
        for (unsigned int i = 0; i < UNIQUE_MAX; ++i)
        {
            currentValue += (std::rand() % 100) + 1; 
            uniqueNumbers.push_back(currentValue);
        }

        std::random_shuffle(uniqueNumbers.begin(), uniqueNumbers.end());

        std::cout << "Inserting " << UNIQUE_MAX << " unique random integers..." << std::endl;
        uniqueSpan.addNumbers(uniqueNumbers.begin(), uniqueNumbers.end());
        std::cout << "Insertion complete." << std::endl;

        std::cout << "Shortest Span: " << uniqueSpan.shortestSpan() << " (Will be > 0)" << std::endl;
        std::cout << "Longest Span:  " << uniqueSpan.longestSpan() << std::endl;
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Container exception caught: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 7. ORTHODOX CANONICAL FORM (OCF) TESTS                                 */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n=========== 7. OCF DEEP COPY & DEFAULT INIT ===========" << std::endl;

    std::cout << "--- Default Constructor Test ---" << std::endl;
    Span defaultSpan;
    try
    {
        defaultSpan.addNumber(42);
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Container exception caught: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Copy Constructor & Assignment Operator Test ---" << std::endl;
    try
    {
        Span original(5);
        original.addNumber(10);
        original.addNumber(20);
        original.addNumber(30);

        Span copySpan(original);
        Span assignedSpan;
        assignedSpan = original;

        original.addNumber(100);
        original.addNumber(200);

        std::cout << "Original Span (5 numbers): longest is " << original.longestSpan() << std::endl;
        std::cout << "Copy Span     (3 numbers): longest is " << copySpan.longestSpan() << std::endl;
        std::cout << "Assigned Span (3 numbers): longest is " << assignedSpan.longestSpan() << std::endl;
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << "Caught container access exception: " << e.what() << std::endl;
    }
    catch (Span::Exception const & e)
    {
        std::cerr << "Span specific error caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
