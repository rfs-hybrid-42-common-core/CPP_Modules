/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 21:06:50 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/16 03:51:24 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn void swap(T& x, T& y)
 * @brief Swaps the values of two given parameters.
 * @details Does not return anything. This function can be called with any type 
 * of argument, provided they are of the same type and support assignment.
 * @tparam T The type of the parameters.
 * @param  x The first value to swap.
 * @param  y The second value to swap.
 */
template <typename T>
void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

/**
 * @fn T const & min(T const & x, T const & y)
 * @brief Compares the two values passed as parameters and returns the smallest 
 * one.
 * @details If they are equal, it returns the second one. Both arguments 
 * must have the same type and support all the comparison operators.
 * @tparam T The type of the parameters.
 * @param  x The first value to compare.
 * @param  y The second value to compare.
 * @return   A constant reference to the smallest value.
 */
template <typename T>
T const & min(T const & x, T const & y)
{
    return x < y ? x : y;
}

/**
 * @fn T const & max(T const & x, T const & y)
 * @brief Compares the two values passed as parameters and returns the greatest 
 * one.
 * @details If they are equal, it returns the second one. Both arguments 
 * must have the same type and support all the comparison operators.
 * @tparam T The type of the parameters.
 * @param  x The first value to compare.
 * @param  y The second value to compare.
 * @return   A constant reference to the greatest value.
 */
template <typename T>
T const & max(T const & x, T const & y)
{
    return x > y ? x : y;
}

#endif
