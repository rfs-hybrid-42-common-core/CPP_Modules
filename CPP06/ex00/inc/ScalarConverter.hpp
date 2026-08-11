/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:11:16 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/12 01:19:20 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class ScalarConverter
 * @brief A utility class for converting string literals to scalar types.
 * @details Contains a single static method to detect the type of a C++ string 
 * literal and convert it into its char, int, float, and double representations. 
 * Designed as a purely static class that cannot be instantiated.
 */
class ScalarConverter
{
    private:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const & other);
        ~ScalarConverter(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        ScalarConverter& operator=(ScalarConverter const & other);

    public:
        /* ------------------------------------------------------------------ */
        /* STATIC PUBLIC METHODS                                              */
        /* ------------------------------------------------------------------ */
        static void convert(std::string const & str);
};

#endif
