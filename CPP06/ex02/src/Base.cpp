/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 02:40:37 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/17 16:28:47 by maaugust         ###   ########.fr       */
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
#include <exception>
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Base::~Base(void)
 * @brief Virtual destructor for the Base class.
 * @details Ensures proper cleanup of derived classes (A, B, C) when deleted 
 * through a Base pointer. Also makes the Base class polymorphic, enabling 
 * the use of dynamic_cast.
 */
Base::~Base(void) {}

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn Base* generate(void)
 * @brief Randomly generates an instance of A, B, or C.
 * @details Instantiates one of the three derived classes based on a pseudo-random 
 * number and returns it upcast as a Base pointer.
 * @return A pointer to a newly allocated A, B, or C object.
 */
Base* generate(void)
{
    switch (std::rand() % 3)
    {
        case 0:
            std::cout << "Generating derived class A..." << std::endl;
            return new A();
        case 1:
            std::cout << "Generating derived class B..." << std::endl;
            return new B();
        case 2:
            std::cout << "Generating derived class C..." << std::endl;
            return new C();
        default:
            std::cout << "Failed to generate a derived class." << std::endl;
            return NULL;
    }
}

/**
 * @fn void identify(Base* p)
 * @brief Identifies the actual type of the object via its pointer.
 * @details Uses dynamic_cast to test the pointer against A*, B*, and C*. 
 * If a downcast fails, it safely evaluates to NULL.
 * @param p A pointer to the Base object.
 */
void identify(Base* p)
{
    std::cout << "Derived class type (Pointer): ";
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

/**
 * @fn void identify(Base& p)
 * @brief Identifies the actual type of the object via its reference.
 * @details Uses dynamic_cast on a reference. Since references cannot be NULL, 
 * a failed cast throws a std::bad_cast exception. Caught polymorphically 
 * as std::exception to avoid including the forbidden <typeinfo> header.
 * @param p A reference to the Base object.
 */
void identify(Base& p)
{
    std::cout << "Derived class type (Reference): ";

    try
    {
       (void)dynamic_cast<A&>(p);
       std::cout << "A" << std::endl;
       return;
    }
    catch (std::exception const & e) {}
    
    try
    {
       (void)dynamic_cast<B&>(p);
       std::cout << "B" << std::endl;
       return;
    }
    catch (std::exception const & e) {}

    try
    {
       (void)dynamic_cast<C&>(p);
       std::cout << "C" << std::endl;
       return;
    }
    catch (std::exception const & e)
    {
        std::cout << "Unknown" << std::endl;
    }
}
