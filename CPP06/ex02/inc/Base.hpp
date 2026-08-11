/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 02:31:35 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/12 03:27:42 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Base
 * @brief The polymorphic base class for Exercise 02.
 * @details Contains a virtual destructor, which makes the class polymorphic. 
 * This is the critical requirement that allows the C++ compiler to generate 
 * RTTI (Run-Time Type Information) for dynamic_cast to function properly.
 */
class Base
{
    public:
        virtual ~Base(void);
};

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
