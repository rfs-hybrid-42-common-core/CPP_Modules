/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:05:56 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/16 02:41:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <deque>
#include <stack>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class MutantStack
 * @brief A stack container adapter that provides iterator access.
 * @details Inherits from the standard std::stack and exposes its protected 
 * underlying container 'c' to allow iteration. This effectively bypasses the 
 * strict LIFO abstraction to provide standard container traversal capabilities 
 * while retaining all original stack functionalities.
 * @tparam T         The type of elements stored in the stack.
 * @tparam Container The underlying container type used to store the elements, 
 * defaulting to std::deque<T>.
 */
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        /* ------------------------------------------------------------------ */
        /* TYPE DEFINITIONS                                                   */
        /* ------------------------------------------------------------------ */
        typedef typename Container::iterator               iterator;
        typedef typename Container::const_iterator         const_iterator;
        typedef typename Container::reverse_iterator       reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;

        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        MutantStack(void);
        MutantStack(MutantStack const & other);
        ~MutantStack(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        MutantStack& operator=(MutantStack const & other);

        /* ------------------------------------------------------------------ */
        /* ITERATOR METHODS                                                   */
        /* ------------------------------------------------------------------ */
        iterator               begin(void);
        const_iterator         begin(void) const;
        iterator               end(void);
        const_iterator         end(void) const;
        reverse_iterator       rbegin(void);
        const_reverse_iterator rbegin(void) const;
        reverse_iterator       rend(void);
        const_reverse_iterator rend(void) const;
};

/* ========================================================================== */
/* TEMPLATE IMPLEMENTATION INCLUSION                                          */
/* ========================================================================== */
#include "MutantStack.tpp"

#endif
