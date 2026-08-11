/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 01:30:00 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/12 03:27:31 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* DATA STRUCTURES                                                            */
/* ========================================================================== */

/**
 * @struct Data
 * @brief A generic data structure payload.
 * @details Contains variables of different primitive and complex types to 
 * verify that data integrity is completely maintained during low-level memory 
 * serialization and deserialization operations.
 * @var Data::c   A standard character variable to test 1-byte data retention.
 * @var Data::i   An integer variable to test standard numeric data retention.
 * @var Data::f   A floating-point variable to test fractional/decimal data 
 * retention.
 * @var Data::str A standard string object to test complex, dynamically 
 * allocated object retention.
 */
struct Data
{
    char        c;
    int         i;
    float       f;
    std::string str;
};

#endif
