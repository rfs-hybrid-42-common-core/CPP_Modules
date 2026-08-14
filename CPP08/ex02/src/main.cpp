/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:06:29 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/16 02:48:35 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "MutantStack.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point for testing the MutantStack class.
 * @details Executes the mandatory subject tests, proves identical behavior 
 * against a standard std::list, verifies the custom reverse and const 
 * iterators, confirms Orthodox Canonical Form compliance, and demonstrates 
 * custom underlying container instantiation.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. SUBJECT MANDATORY TEST (MUTANTSTACK)                                */
    /* ---------------------------------------------------------------------- */
    std::cout << "============ 1. SUBJECT TEST: MUTANTSTACK =============" << std::endl;

    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;
    
    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "Iterating through MutantStack (default deque):" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    /* ---------------------------------------------------------------------- */
    /* 2. SUBJECT MANDATORY TEST (STD::LIST COMPARISON)                       */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============= 2. SUBJECT TEST: STD::LIST ==============" << std::endl;

    std::list<int> list;

    list.push_back(5);
    list.push_back(17);

    std::cout << "Back element (Top): " << list.back() << std::endl;

    list.pop_back();

    std::cout << "Size after pop_back: " << list.size() << std::endl;

    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    //[...]
    list.push_back(0);

    std::list<int>::iterator list_it = list.begin();
    std::list<int>::iterator list_ite = list.end();

    ++list_it;
    --list_it;

    std::cout << "Iterating through std::list:" << std::endl;
    while (list_it != list_ite)
    {
        std::cout << *list_it << std::endl;
        ++list_it;
    }

    /* ---------------------------------------------------------------------- */
    /* 3. ADVANCED ITERATORS TEST (REVERSE & CONST)                           */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============= 3. ADVANCED ITERATORS TEST ==============" << std::endl;

    std::cout << "Reverse Iteration:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "\nConst Iteration (Read-only):" << std::endl;
    MutantStack<int> const const_mstack(mstack);
    MutantStack<int>::const_iterator cit = const_mstack.begin();
    MutantStack<int>::const_iterator cite = const_mstack.end();
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    /* ---------------------------------------------------------------------- */
    /* 4. ORTHODOX CANONICAL FORM (OCF) TEST                                  */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n================ 4. OCF DEEP COPY TEST ================" << std::endl;

    MutantStack<int> assigned_stack;
    assigned_stack = mstack;

    std::cout << "Original stack size: " << mstack.size() << std::endl;
    std::cout << "Assigned stack size: " << assigned_stack.size() << std::endl;

    std::cout << "\nPopping all elements from original stack..." << std::endl;
    while (!mstack.empty())
        mstack.pop();

    std::cout << "Original stack size after pop: " << mstack.size() << std::endl;
    std::cout << "Assigned stack size remains:   " << assigned_stack.size() << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 5. CUSTOM UNDERLYING CONTAINER TEST (STD::VECTOR)                      */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n========== 5. CUSTOM CONTAINER TEST (VECTOR) ==========" << std::endl;

    MutantStack<int, std::vector<int> > vstack;

    vstack.push(42);
    vstack.push(100);
    vstack.push(21);

    std::cout << "Iterating through MutantStack backed by std::vector:" << std::endl;
    for (MutantStack<int, std::vector<int> >::iterator vit = vstack.begin(); vit != vstack.end(); ++vit)
        std::cout << *vit << std::endl;

    return EXIT_SUCCESS;
}
