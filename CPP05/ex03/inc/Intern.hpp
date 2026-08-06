/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 02:45:33 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 03:13:59 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "AForm.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <exception>
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Intern
 * @brief Represents a nameless, gradeless intern whose only job is to create 
 * forms.
 * @details Implements a dispatch array mechanism to instantiate concrete forms 
 * dynamically based on a string input, strictly avoiding if/elseif/else chains 
 * as required by the subject.
 */
class Intern
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE METHODS                                                    */
        /* ------------------------------------------------------------------ */
        AForm* _makeShrubbery(std::string const & target);
        AForm* _makeRobotomy(std::string const & target);
        AForm* _makePardon(std::string const & target);

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Intern(void);
        Intern(Intern const & other);
        ~Intern(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        Intern& operator=(Intern const & other);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        AForm* makeForm(std::string const & name, std::string const & target);

    /* ====================================================================== */
    /* EXCEPTIONS                                                             */
    /* ====================================================================== */

    /**
     * @class Exception
     * @brief Generic exception for the Intern class.
     * @details Inherits from std::exception. Serves as the base class for all 
     * specific Intern exceptions, allowing polymorphic catching.
     */
    class Exception : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class FormNotFound
     * @brief Exception thrown when the intern is asked to create an unknown 
     * form.
     * @details Inherits from Exception to provide a clean escape route 
     * and explicit error message when the form name parameter does not match 
     * any known forms. This enables polymorphic catching through the generic 
     * Intern::Exception.
     */
    class FormNotFound : public Exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif
