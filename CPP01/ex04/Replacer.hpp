/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:29:58 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:10:32 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <fstream>
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Replacer
 * @brief Handles file reading and string replacement operations.
 * @details Stores the target filename and provides a method to read its 
 * contents, replace all occurrences of a specific string with another, and 
 * save the result to a new file appended with ".replace".
 */
class Replacer
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        std::string _filename;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Replacer(std::string const & filename);
        ~Replacer(void);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        bool replace(std::string const & s1, std::string const & s2);
};

#endif
