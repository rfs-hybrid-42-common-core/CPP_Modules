/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 00:20:21 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 03:05:03 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "AForm.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class ShrubberyCreationForm
 * @brief Concrete form that plants ASCII trees.
 * @details Inherits from AForm. Requires grade 145 to sign and 137 to execute. 
 * Creates a file named <target>_shrubbery containing ASCII trees.
 */
class ShrubberyCreationForm : public AForm
{
    private:
        /* ------------------------------------------------------------------ */
        /* CONSTANTS & SETTINGS                                               */
        /* ------------------------------------------------------------------ */
        static int const _signGrade = 145;
        static int const _execGrade = 137;

        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        std::string _target;

        /* ------------------------------------------------------------------ */
        /* PRIVATE METHODS                                                    */
        /* ------------------------------------------------------------------ */
        void executeAction(void) const;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string const & target);
        ShrubberyCreationForm(ShrubberyCreationForm const & other);
        virtual ~ShrubberyCreationForm(void);

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        std::string const & getTarget(void) const;

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const & other);

    /* ====================================================================== */
    /* EXCEPTIONS                                                             */
    /* ====================================================================== */

/**
     * @class FileOpenException
     * @brief Exception thrown when the shrubbery file cannot be opened.
     * @details Inherits from AForm::Exception to provide custom error handling 
     * specifically for file I/O failures during the execution of the 
     * ShrubberyCreationForm. This enables polymorphic catching through the 
     * generic AForm::Exception.
     */
    class FileOpenException : public AForm::Exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif
