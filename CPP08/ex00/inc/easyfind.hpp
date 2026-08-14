/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:17:54 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/19 19:20:43 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @brief Finds the first occurrence of an integer in a mutable container.
 * @details Assumes T is a container of integers. Searches for the integer 'n' 
 * and returns a mutable iterator pointing to its first occurrence, allowing 
 * for modification of the found element.
 * @tparam T         The data type of the container.
 * @param  container The mutable container to search in.
 * @param  n         The integer value to find.
 * @return           An iterator pointing to the first occurrence of 'n'.
 * @throws           std::runtime_error if 'n' is not found in the container.
 */
template <typename T>
typename T::iterator easyfind(T& container, int n);

/**
 * @brief Finds the first occurrence of an integer in a constant container.
 * @details Assumes T is a container of integers. Searches for the integer 'n' 
 * and returns a read-only iterator pointing to its first occurrence.
 * @tparam T         The data type of the container.
 * @param  container The constant container to search in.
 * @param  n         The integer value to find.
 * @return           A const_iterator pointing to the first occurrence of 'n'.
 * @throws           std::runtime_error if 'n' is not found in the container.
 */
template <typename T>
typename T::const_iterator easyfind(T const & container, int n);

/* ========================================================================== */
/* TEMPLATE IMPLEMENTATION INCLUSION                                          */
/* ========================================================================== */
#include "easyfind.tpp"

#endif
