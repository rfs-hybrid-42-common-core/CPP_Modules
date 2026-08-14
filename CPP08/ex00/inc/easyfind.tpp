/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:18:01 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/19 19:22:31 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <algorithm>
#include <stdexcept>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn typename T::iterator easyfind(T& container, int n)
 * @brief Implementation of the mutable easyfind template function.
 * @details Utilizes std::find from the <algorithm> library to locate the 
 * first occurrence of 'n' in the mutable 'container'. If the end of the 
 * container is reached without finding the value, a standard exception is 
 * thrown.
 * @tparam T         The data type of the container.
 * @param  container The mutable container to search in.
 * @param  n         The integer value to find.
 * @return           An iterator pointing to the found element.
 * @throws           std::runtime_error if std::find returns the container's end 
 * iterator.
 */
template <typename T>
typename T::iterator easyfind(T& container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it != container.end())  
        return it;
    throw std::runtime_error("value not found in container.");
}

/**
 * @fn typename T::const_iterator easyfind(T const & container, int n)
 * @brief Implementation of the constant easyfind template function.
 * @details Utilizes std::find from the <algorithm> library to locate the 
 * first occurrence of 'n' in the constant 'container'. If the end of the 
 * container is reached without finding the value, a standard exception is 
 * thrown.
 * @tparam T         The data type of the container.
 * @param  container The constant container to search in.
 * @param  n         The integer value to find.
 * @return           A const_iterator pointing to the found element.
 * @throws           std::runtime_error if std::find returns the container's end 
 * iterator.
 */
template <typename T>
typename T::const_iterator easyfind(T const & container, int n)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), n);
    if (it != container.end())  
        return it;
    throw std::runtime_error("value not found in container.");
}
