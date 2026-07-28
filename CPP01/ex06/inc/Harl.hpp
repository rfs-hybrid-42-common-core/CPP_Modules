/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:36:17 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:13:13 by maaugust         ###   ########.fr       */
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
 * @brief Filters and outputs cascading complaint messages based on log levels.
 * @details Harl outputs different messages based on log levels (DEBUG, INFO, 
 * WARNING, ERROR). This specific implementation utilizes a `switch` statement 
 * with intentional fall-through logic to display all messages from the 
 * requested level and above, ignoring less severe levels.
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
        int         getLevelIndex(std::string const & level);
    
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
