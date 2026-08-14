/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:35:58 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/24 04:26:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "easyfind.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <iterator>
#include <deque>
#include <list>
#include <vector>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point for testing the easyfind template.
 * @details Rigorously tests the easyfind function using various standard 
 * sequence containers (vector, list, deque), handling both successful 
 * searches and exception throwing when values are absent.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. STD::VECTOR TEST                                                    */
    /* ---------------------------------------------------------------------- */
    std::cout << "================= 1. STD::VECTOR TEST =================" << std::endl;

    std::vector<int> vec;
    for (int i = 0; i < 5; ++i)
        vec.push_back(i * 10);

    std::cout << "Vector contents: ";
    for (int i = 0; i < static_cast<int>(vec.size()); ++i)
    {
        std::cout << vec.at(i);
        if (i < static_cast<int>(vec.size()) - 1)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

    try
    {
        std::cout << "Searching for 20..." << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Success! Found value: " << *it << std::endl;
        
        *it = 999;
        std::cout << "Successfully mutated the found value to: " << *it << std::endl;
    }
    catch (std::runtime_error const & e)
    {
        std::cerr << "Vector exception caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Searching for 99..." << std::endl;
        easyfind(vec, 99);
        std::cout << "This should not print." << std::endl;
    }
    catch (std::runtime_error const & e)
    {
        std::cerr << "Vector exception caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 2. STD::LIST TEST (MUTABLE ITERATOR)                                   */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================== 2. STD::LIST TEST ==================" << std::endl;

    std::list<int> lst;
    for (int i = 0; i < 5; ++i)
        lst.push_back(i * 5);

    std::cout << "List contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it;
        std::list<int>::iterator next_it = it;
        ++next_it;
        if (next_it != lst.end())
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

    try
    {
        std::cout << "Searching for 15..." << std::endl;
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Success! Found value: " << *it << std::endl;
    }
    catch (std::runtime_error const & e)
    {
        std::cerr << "List exception caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Searching for -1..." << std::endl;
        easyfind(lst, -1);
        std::cout << "This should not print." << std::endl;
    }
    catch (std::runtime_error const & e)
    {
        std::cerr << "List exception caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 3. STD::DEQUE TEST (MUTABLE ITERATOR)                                  */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================= 3. STD::DEQUE TEST ==================" << std::endl;

    std::deque<int> deq;
    for (int i = 0; i < 5; ++i)
        deq.push_front(i);

    std::cout << "Deque contents: ";
    for (int i = 0; i < static_cast<int>(deq.size()); ++i)
    {
        std::cout << deq.at(i);
        if (i < static_cast<int>(deq.size()) - 1)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

    try
    {
        std::cout << "Searching for 3..." << std::endl;
        std::deque<int>::iterator it = easyfind(deq, 3);
        std::cout << "Success! Found value: " << *it << std::endl;
    }
    catch (std::runtime_error const & e)
    {
        std::cerr << "Deque exception caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 4. CONST CONTAINER TEST (CONST ITERATOR)                               */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n=============== 4. CONST CONTAINER TEST ===============" << std::endl;

    std::vector<int> const constVec = vec;
    std::cout << "Const Vector contents: ";
    for (int i = 0; i < static_cast<int>(constVec.size()); ++i)
    {
        std::cout << constVec.at(i);
        if (i < static_cast<int>(constVec.size()) - 1)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

    try
    {
        std::cout << "Searching for 40 in a const container..." << std::endl;
        std::vector<int>::const_iterator it = easyfind(constVec, 40);
        std::cout << "Success! Found value: " << *it << std::endl;
    }
    catch (std::runtime_error const & e)
    {
        std::cerr << "Vector exception caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 5. EDGE CASES (EMPTY & DUPLICATES)                                     */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================= 5. EDGE CASES TEST ==================" << std::endl;

    std::vector<int> emptyVec;
    std::cout << "Attempting to search in an empty container..." << std::endl;
    try
    {
        easyfind(emptyVec, 42);
        std::cout << "This should not print." << std::endl;
    }
    catch (std::runtime_error const & e)
    {
        std::cerr << "Vector exception caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    std::vector<int> dupVec;
    dupVec.push_back(10);
    dupVec.push_back(42);
    dupVec.push_back(42);

    std::cout << "Duplicate Vector contents: ";
    for (int i = 0; i < static_cast<int>(dupVec.size()); ++i)
    {
        std::cout << dupVec.at(i);
        if (i < static_cast<int>(dupVec.size()) - 1)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

    std::cout << "Searching for 42 (should return the first occurrence)..." << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(dupVec, 42);
        std::cout << "Success! Found value: " << *it << " at index: " 
                  << std::distance<std::vector<int>::iterator>(dupVec.begin(), it) << std::endl;
    }
    catch (std::runtime_error const & e)
    {
        std::cerr << "Duplicate vector exception caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    /* ---------------------------------------------------------------------- */
    /* 6. DUCK TYPING & IMPLICIT CAST TEST                                    */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============ 6. IMPLICIT CAST TEST (CHAR) =============" << std::endl;
    std::cout << "Testing template duck typing with a non-int container..." << std::endl;

    std::vector<char> charVec;
    charVec.push_back('a');
    charVec.push_back('b');
    charVec.push_back('c');

    std::cout << "Char Vector contents: ";
    for (int i = 0; i < static_cast<int>(charVec.size()); ++i)
    {
        std::cout << "'" << charVec.at(i) << "'";
        if (i < static_cast<int>(charVec.size()) - 1)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

    try
    {
        std::cout << "Searching for integer 98 inside the vector<char>..." << std::endl;
        std::vector<char>::iterator it = easyfind(charVec, 98);
        std::cout << "Success! Found value: '" << *it << "' (ASCII: " << static_cast<int>(*it) << ")" << std::endl;
    }
    catch (std::runtime_error const & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
