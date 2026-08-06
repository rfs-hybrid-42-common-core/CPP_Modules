/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 22:32:37 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 02:50:42 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

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
 * @class AForm
 * @brief Abstract base class representing a bureaucratic form.
 * @details Implements a Form with a constant name, a signature status, and 
 * constant grades required to sign and execute it. It enforces the Template 
 * Method pattern for execution by requiring derived classes to implement the 
 * pure virtual executeAction() method.
 */
class AForm
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        std::string const _name;
        bool              _isSigned;
        int	const         _gradeToSign;
        int const         _gradeToExecute;

    protected:
        /* ------------------------------------------------------------------ */
        /* PROTECTED METHODS                                                  */
        /* ------------------------------------------------------------------ */
        virtual void executeAction(void) const = 0;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        AForm(void);
        AForm(std::string const & name, int gradeToSign, int gradeToExecute);
        AForm(AForm const & other);
        virtual ~AForm(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        AForm& operator=(AForm const & other);

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
        void beSigned(Bureaucrat const & bureaucrat);
        void execute(Bureaucrat const & executor) const;

    /* ====================================================================== */
    /* EXCEPTIONS                                                             */
    /* ====================================================================== */

    /**
     * @class Exception
     * @brief Generic exception for the Form class.
     * @details Inherits from std::exception. Serves as the base class for all 
     * specific AForm exceptions, allowing polymorphic catching.
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
     * polymorphic catching through the generic AForm::Exception.
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
     * polymorphic catching through the generic AForm::Exception.
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
     * AForm::Exception.
     */
    class AlreadySignedException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class NotSignedException
     * @brief Exception thrown when attempting to execute an unsigned form.
     * @details Inherits from Exception to enforce the rule that a form 
     * must be signed before it can be successfully executed. This enables 
     * polymorphic catching through the generic AForm::Exception.
     */
    class NotSignedException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };
};

/* ========================================================================== */
/* NON-MEMBER OPERATOR OVERLOADS                                              */
/* ========================================================================== */

std::ostream& operator<<(std::ostream& o, AForm const & form);

#endif
