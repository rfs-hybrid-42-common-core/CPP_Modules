/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 01:58:53 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/18 20:41:34 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <stdexcept>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Array<T>::Array(void)
 * @brief Default constructor for the Array template class.
 * @details Initializes an empty array by setting the size to 0 and the 
 * elements pointer to NULL.
 */
template <typename T>
Array<T>::Array(void) : _size(0), _elements(NULL)
{
    std::cout << "Empty array has been created." << std::endl;
}

/**
 * @fn Array<T>::Array(unsigned int n)
 * @brief Parameterized constructor for the Array template class.
 * @details Allocates memory for an array of 'n' elements using new[] and 
 * default-initializes them.
 * @param n The number of elements to allocate.
 */
template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _elements(new T[n]())
{
    std::cout << "Array with " << size() << " elements has been created." << std::endl;
}

/**
 * @fn Array<T>::Array(Array const & other)
 * @brief Copy constructor for the Array template class.
 * @details Performs a deep copy of the 'other' array. Allocates new memory 
 * and copies each element individually so modifying the copy does not affect 
 * the original.
 * @param other The Array object to copy from.
 */
template <typename T>
Array<T>::Array(Array const & other) : _size(other._size), _elements(NULL)
{
    if (size() > 0)
    {
        _elements = new T[size()]();
        for (unsigned int i = 0; i < size(); ++i)
            _elements[i] = other._elements[i];
        std::cout << "Array with " << size() << " elements has been cloned." << std::endl;
    }
    else
        std::cout << "Empty array has been cloned." << std::endl;
}

/**
 * @fn Array<T>::~Array(void)
 * @brief Destructor for the Array template class.
 * @details Safely deallocates the dynamically allocated memory using delete[], 
 * preventing any memory leaks.
 */
template <typename T>
Array<T>::~Array(void)
{
    if (!_elements)
        std::cout << "Empty array has been destroyed." << std::endl;
    else
    {
        delete [] _elements;
        std::cout << "Array with " << size() << " elements has been destroyed." << std::endl;
    }
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Array<T>& Array<T>::operator=(Array<T> const & other)
 * @brief Copy assignment operator overload.
 * @details Safely cleans up existing memory before performing a deep copy of 
 * the 'other' array. Protects against self-assignment.
 * @param other The Array object to assign from.
 * @return      A reference to the newly assigned Array object.
 */
template <typename T>
Array<T>& Array<T>::operator=(Array<T> const & other)
{
    if (this != &other)
    {
        T* temp = NULL;
        if (other.size() > 0)
        {
            temp = new T[other.size()]();
            for (unsigned int i = 0; i < size(); ++i)
                temp[i] = other._elements[i];
            std::cout << "Array with " << size() << " elements has been copied." << std::endl;
        }

        delete [] _elements;

        _elements = temp;
        _size = other.size();

        if (size() == 0)
            std::cout << "Empty array has been copied." << std::endl;
        else
            std::cout << "Array of " << size() << " elements has been copied." << std::endl;
    }
    else
        std::cout << "Same array provided. No need to perform copy." << std::endl;
    return *this;
}

/**
 * @fn T& Array<T>::operator[](unsigned int i)
 * @brief Subscript operator overload for mutable element access.
 * @details Allows reading and modifying elements at the specified index. 
 * Throws a std::out_of_range exception if the index is out of bounds.
 * @param i The index of the element to access.
 * @return  A reference to the element at the requested index.
 * @throws  std::out_of_range if index is greater than or equal to the array 
 * size.
 */
template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= size())
        throw std::out_of_range("Index out of bounds.");
    return _elements[i];
}

/**
 * @fn T const & Array<T>::operator[](unsigned int i) const
 * @brief Subscript operator overload for read-only element access.
 * @details Allows reading elements from a const Array object. Throws a 
 * std::out_of_range exception if the index is out of bounds.
 * @param i The index of the element to access.
 * @return  A constant reference to the element at the requested index.
 * @throws  std::out_of_range if index is greater than or equal to the array 
 * size.
 */
template <typename T>
T const & Array<T>::operator[](unsigned int i) const
{
    if (i >= size())
        throw std::out_of_range("Index out of bounds.");
    return _elements[i];
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn unsigned int Array<T>::size(void) const
 * @brief Retrieves the number of elements in the array.
 * @details Provides read-only access to the internal _size attribute without 
 * modifying the current instance.
 * @return The size of the array.
 */
template <typename T>
unsigned int Array<T>::size(void) const
{
    return _size;
}
