/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 22:32:37 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 02:23:35 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <exception>
#include <string>
#include <ostream>

/* -------------------------- Forward Declarations -------------------------- */
class Bureaucrat;

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Form
 * @brief Represents a bureaucratic form.
 * @details Implements a Form with a constant name, a boolean to track if it 
 * is signed, and constant grades required to sign and execute it.
 */
class Form
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        std::string const _name;
        bool              _isSigned;
        int	const         _gradeToSign;
        int const         _gradeToExecute;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Form(void);
        Form(std::string const & name, int gradeToSign, int gradeToExecute);
        Form(Form const & other);
        ~Form(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        Form& operator=(Form const & other);

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        std::string const & getName(void) const;
        bool                getIsSigned(void) const;
        int                 getGradeToSign(void) const;
        int                 getGradeToExecute(void) const;

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void beSigned(Bureaucrat const & signatory);

    /* ====================================================================== */
    /* EXCEPTIONS                                                             */
    /* ====================================================================== */

    /**
     * @class Exception
     * @brief Generic exception for the Form class.
     * @details Inherits from std::exception. Serves as the base class for all 
     * specific Form exceptions, allowing polymorphic catching.
     */
    class Exception : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class GradeTooHighException
     * @brief Exception thrown when a form's required grade goes above 1.
     * @details Inherits from Exception to provide custom error handling 
     * for invalid form creation or signing attempts. This enables 
     * polymorphic catching through the generic Form::Exception.
     */
    class GradeTooHighException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class GradeTooLowException
     * @brief Exception thrown when a form's required grade drops below 150.
     * @details Inherits from Exception to provide custom error handling 
     * for invalid form creation or signing attempts. This enables 
     * polymorphic catching through the generic Form::Exception.
     */
    class GradeTooLowException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class AlreadySignedException
     * @brief Exception thrown when attempting to sign an already signed form.
     * @details Inherits from Exception to provide custom error handling 
     * to prevent redundant signatures and enforce strict bureaucratic 
     * procedure. This enables polymorphic catching through the generic 
     * Form::Exception.
     */
    class AlreadySignedException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };
};

/* ========================================================================== */
/* NON-MEMBER OPERATOR OVERLOADS                                              */
/* ========================================================================== */

std::ostream& operator<<(std::ostream& o, Form const & form);

#endif
