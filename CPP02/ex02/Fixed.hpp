/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 01:32:17 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 02:48:18 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <ostream>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Fixed
 * @brief Represents a fixed-point number.
 * @details Implements a fixed-point number class in Orthodox Canonical Form 
 * with the ability to convert between integers, floating-point numbers, and 
 * fixed-point values.
 */
class Fixed
{
    private:
        /* ------------------------------------------------------------------ */
        /* CONSTANTS & SETTINGS                                               */
        /* ------------------------------------------------------------------ */
        static int const _bits = 8;

        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        int _n;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Fixed(void);
        Fixed(int const n);
        Fixed(float const n);
        Fixed(Fixed const & other);
        ~Fixed(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        
        /* ---------------------- Assignment operator ----------------------- */
        Fixed& operator=(Fixed const & other);

        /* ---------------------- Comparison operators ---------------------- */
        bool   operator>(Fixed const & other) const;
        bool   operator<(Fixed const & other) const;
        bool   operator>=(Fixed const & other) const;
        bool   operator<=(Fixed const & other) const;
        bool   operator==(Fixed const & other) const;
        bool   operator!=(Fixed const & other) const;

        /* ---------------------- Arithmetic operators ---------------------- */
        Fixed  operator+(Fixed const & other) const;
        Fixed  operator-(Fixed const & other) const;
        Fixed  operator*(Fixed const & other) const;
        Fixed  operator/(Fixed const & other) const;

        /* ----------------- Increment/Decrement operators ------------------ */
        Fixed& operator++(void);
        Fixed  operator++(int);
        Fixed& operator--(void);
        Fixed  operator--(int);

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        int getRawBits(void) const;

        /* ------------------------------------------------------------------ */
        /* SETTERS                                                            */
        /* ------------------------------------------------------------------ */        
        void setRawBits(int const raw);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        float toFloat(void) const;
        int   toInt(void) const;

        /* ------------------------------------------------------------------ */
        /* STATIC PUBLIC METHODS                                              */
        /* ------------------------------------------------------------------ */
        static Fixed&        min(Fixed& fixed1, Fixed& fixed2);
        static Fixed&        max(Fixed& fixed1, Fixed& fixed2);
        static Fixed const & min(Fixed const & fixed1, Fixed const & fixed2);
        static Fixed const & max(Fixed const & fixed1, Fixed const & fixed2);
};

/* ========================================================================== */
/* NON-MEMBER OPERATOR OVERLOADS                                              */
/* ========================================================================== */

std::ostream& operator<<(std::ostream& o, Fixed const & fixed);

#endif
