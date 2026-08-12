/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 02:10:28 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/16 03:57:03 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Array
 * @brief A generic, dynamically allocated array class template.
 * @details Manages memory safely using the Orthodox Canonical Form and 
 * provides bounds-checked element access.
 * @tparam T The data type of the elements stored in the array.
 */
template <typename T>
class Array
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        unsigned int _size;
        T*           _elements;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Array(void);
        Array(unsigned int n);
        Array(Array<T> const & other);
        ~Array(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        Array<T>& operator=(Array<T> const & other);
        T& operator[](unsigned int i);
        T const & operator[](unsigned int i) const;

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        unsigned int size(void) const;
};

/* ========================================================================== */
/* TEMPLATE IMPLEMENTATION INCLUSION                                          */
/* ========================================================================== */
#include "Array.tpp"

#endif
