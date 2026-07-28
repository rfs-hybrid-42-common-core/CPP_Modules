/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:36:17 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:11:19 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Harl
 * @brief Automates complaint messages using pointers to member functions.
 * @details Harl outputs different messages based on log levels (DEBUG, INFO, 
 * WARNING, ERROR). It relies on an array of member function pointers to route 
 * the logic, explicitly avoiding the use of if/else if/else structures.
 */
class Harl
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE METHODS                                                    */
        /* ------------------------------------------------------------------ */
        void        debug(void);
        void        info(void);
        void        warning(void);
        void        error(void);
        std::string trimWhitespaces(std::string const & str);
    
    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Harl(void);
        ~Harl(void);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void complain(std::string level);
};

#endif
