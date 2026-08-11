/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 02:43:37 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/12 03:27:58 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
#define B_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Base.hpp"

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class B
 * @brief An empty derived class.
 * @details Publicly inherits from the polymorphic Base class. Used 
 * specifically to test runtime type identification and pointer/reference 
 * downcasting.
 */
class B : public Base {};

#endif
