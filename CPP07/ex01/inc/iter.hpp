/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 01:08:45 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/16 03:55:20 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include <cstddef>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn void iter(T* addr, size_t const len, F func)
 * @brief Iterates over an array and applies a function to each element.
 * @details Takes the address of an array, its length, and calls the provided 
 * function on every single element. Thanks to the secondary template 
 * parameter 'F', it gracefully handles both const and non-const elements by 
 * dynamically deducing the function signature.
 * @tparam T    The data type of the array elements.
 * @tparam F    The type of the callable function/functor.
 * @param  addr The address of the array.
 * @param  len  The length of the array, passed as a const value.
 * @param  func The function that will be called on every element of the array.
 */
template <typename T, typename F>
void iter(T* addr, size_t const len, F func)
{
    if (!addr)
        return;
    for (size_t i = 0; i < len; ++i)
        func(addr[i]);
}

#endif
