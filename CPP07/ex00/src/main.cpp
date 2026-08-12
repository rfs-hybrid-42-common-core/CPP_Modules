/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 21:06:47 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/18 20:51:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "whatever.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <string>
#include <cstdlib>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Test
 * @brief A generic test class to validate template functions.
 * @details Implements all required comparison operators to be fully compatible 
 * with the generic min and max templates.
 * @tparam T The underlying data type of the test object.
 */
template <typename T>
class Test
{
    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Test(void) : _n(T()) {}
        Test(T const & n) : _n(n) {}
        Test(Test const & other) : _n(other.getN()) {}
        ~Test(void) {}

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        Test& operator=(Test const & other)
        {
            if(this != &other)
                _n = other.getN();
            return *this;
        }
        bool operator==(Test<T> const & other) const { return (this->getN() == other.getN()); }
        bool operator!=(Test<T> const & other) const { return (this->getN() != other.getN()); }
        bool operator>(Test<T> const & other) const { return (this->getN() > other.getN()); }
        bool operator<(Test<T> const & other) const { return (this->getN() < other.getN()); }
        bool operator>=(Test<T> const & other) const { return (this->getN() >= other.getN()); }
        bool operator<=(Test<T> const & other) const { return (this->getN() <= other.getN()); }

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        T const & getN() const { return _n; }

    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        T _n;
};

/* ========================================================================== */
/* NON-MEMBER OPERATOR OVERLOADS                                              */
/* ========================================================================== */

/**
 * @fn std::ostream & operator<<(std::ostream & o, Test<T> const & test)
 * @brief Overloads the insertion operator for the Test class.
 * @details Allows outputting the internal value of the Test object to standard 
 * output.
 * @tparam T    The underlying data type of the test object.
 * @param  o    The output stream object.
 * @param  test The Test object to insert into the stream.
 * @return      A reference to the modified output stream object.
 */
template <typename T>
std::ostream & operator<<(std::ostream & o, Test<T> const & test) {
    o << test.getN();
    return o;
}

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn int main(void)
 * @brief The main execution point for testing the whatever templates.
 * @details Runs the mandatory subject tests followed by custom 
 * complex type tests and a strict memory address equality test.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(void)
{
    /* ---------------------------------------------------------------------- */
    /* 1. MANDATORY SUBJECT TESTS                                             */
    /* ---------------------------------------------------------------------- */
    std::cout << "=============== MANDATORY SUBJECT TESTS ===============" << std::endl;
    
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 2. CUSTOM COMPLEX TYPE TESTS                                           */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============== CUSTOM COMPLEX TYPE TESTS ==============" << std::endl;
    
    Test<int> t1(42);
    Test<int> t2(21);
    
    std::cout << "Before swap -> t1: " << t1 << ", t2: " << t2 << std::endl;
    ::swap(t1, t2);
    std::cout << "After swap  -> t1: " << t1 << ", t2: " << t2 << std::endl;
    
    std::cout << "min( t1, t2 ) = " << ::min(t1, t2) << std::endl;
    std::cout << "max( t1, t2 ) = " << ::max(t1, t2) << std::endl;

    /* ---------------------------------------------------------------------- */
    /* 3. EDGE CASE: EQUALITY TEST (ADDRESS COMPARISON)                       */
    /* ---------------------------------------------------------------------- */
    std::cout << "\n============== EQUALITY EDGE CASE TESTS ===============" << std::endl;
    
    Test<std::string> t3("equal_value");
    Test<std::string> t4("equal_value");
    
    std::cout << "Comparing identical values to ensure the second argument is returned:" << std::endl;
    std::cout << "Address of t3: " << &t3 << std::endl;
    std::cout << "Address of t4: " << &t4 << std::endl;
    std::cout << "Address returned by max: " << &(::max(t3, t4)) << " (Should match t4)" << std::endl;
    std::cout << "Address returned by min: " << &(::min(t3, t4)) << " (Should match t4)" << std::endl;

    return EXIT_SUCCESS;
}
