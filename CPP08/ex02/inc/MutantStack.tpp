/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:06:18 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/16 02:17:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn MutantStack<T, Container>::MutantStack(void)
 * @brief Default constructor for the MutantStack class.
 * @details Initializes an empty MutantStack, utilizing the default underlying 
 * container (std::deque by default).
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 */
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) {}

/**
 * @fn MutantStack<T, Container>::MutantStack(MutantStack const & other)
 * @brief Copy constructor for the MutantStack class.
 * @details Performs a deep copy by explicitly invoking the base std::stack 
 * copy constructor, ensuring the underlying container 'c' is perfectly 
 * duplicated.
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 * @param  other     The MutantStack object to copy from.
 */
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack const & other) : std::stack<T, Container>(other) {}

/**
 * @fn MutantStack<T, Container>::~MutantStack(void)
 * @brief Destructor for the MutantStack class.
 * @details Safely destroys the MutantStack. The base std::stack destructor 
 * automatically handles the cleanup of the underlying container.
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 */
template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) {}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn MutantStack<T, Container>& MutantStack<T, Container>::operator=(MutantStack const & other)
 * @brief Copy assignment operator overload.
 * @details Safely assigns the values of 'other' to the current instance by 
 * leveraging the base std::stack assignment operator, protecting against 
 * self-assignment.
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 * @param other      The MutantStack object to assign from.
 * @return           A reference to the newly assigned MutantStack object.
 */
template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(MutantStack const & other)
{
    if (this != &other)
        std::stack<T, Container>::operator=(other);
    return *this;
}

/* ========================================================================== */
/* ITERATOR METHODS                                                           */
/* ========================================================================== */

/**
 * @fn typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
 * @brief Retrieves an iterator to the beginning of the stack.
 * @details Exposes the iterators of the std::stack adapter by accessing its 
 * protected member 'c' (the underlying container).
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 * @return           An iterator pointing to the first element.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
{
    return this->c.begin();
}

/**
 * @fn typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin(void) const
 * @brief Retrieves a constant iterator to the beginning of the stack.
 * @details Exposes the constant iterators of the std::stack adapter by 
 * accessing its protected member 'c' (the underlying container).
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 * @return           A constant iterator pointing to the first element.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin(void) const
{
    return this->c.begin();
}

/**
 * @fn typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
 * @brief Retrieves an iterator to the end of the stack.
 * @details Exposes the iterators of the std::stack adapter by accessing its 
 * protected member 'c' (the underlying container).
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 * @return           An iterator pointing to the theoretical element past the 
 * last element.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
{
    return this->c.end();
}

/**
 * @fn typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end(void) const
 * @brief Retrieves a constant iterator to the end of the stack.
 * @details Exposes the constant iterators of the std::stack adapter by 
 * accessing its protected member 'c' (the underlying container).
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 * @return           A constant iterator pointing to the theoretical element 
 * past the last element.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end(void) const
{
    return this->c.end();
}

/**
 * @fn typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin(void)
 * @brief Retrieves a reverse iterator to the beginning of the reversed stack.
 * @details Exposes the reverse iterators of the std::stack adapter by 
 * accessing its protected member 'c' (the underlying container).
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 * @return           A reverse iterator pointing to the last element.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin(void)
{
    return this->c.rbegin();
}

/**
 * @fn typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin(void) const
 * @brief Retrieves a constant reverse iterator to the beginning of the 
 * reversed stack.
 * @details Exposes the constant reverse iterators of the std::stack adapter by 
 * accessing its protected member 'c' (the underlying container).
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 * @return           A constant reverse iterator pointing to the last element.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin(void) const
{
    return this->c.rbegin();
}

/**
 * @fn typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend(void)
 * @brief Retrieves a reverse iterator to the end of the reversed stack.
 * @details Exposes the reverse iterators of the std::stack adapter by 
 * accessing its protected member 'c' (the underlying container).
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 * @return           A reverse iterator pointing to the theoretical element 
 * preceding the first element.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend(void)
{
    return this->c.rend();
}

/**
 * @fn typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend(void) const
 * @brief Retrieves a constant reverse iterator to the end of the reversed 
 * stack.
 * @details Exposes the constant reverse iterators of the std::stack adapter by 
 * accessing its protected member 'c' (the underlying container).
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements.
 * @return           A constant reverse iterator pointing to the theoretical 
 * element preceding the first element.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend(void) const
{
    return this->c.rend();
}
