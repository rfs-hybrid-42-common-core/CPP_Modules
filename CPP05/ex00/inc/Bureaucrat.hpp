/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:57:04 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 02:02:19 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <exception>
#include <string>
#include <ostream>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class Bureaucrat
 * @brief Represents a cog in the bureaucratic machine.
 * @details Implements a Bureaucrat with a constant name and a strictly 
 * controlled grade ranging from 1 (highest) to 150 (lowest).
 */
class Bureaucrat
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        std::string const _name;
        int				  _grade;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Bureaucrat(void);
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & other);
        ~Bureaucrat(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        Bureaucrat& operator=(Bureaucrat const & other);

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        std::string const & getName(void) const;
        int                 getGrade(void) const;

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void incrementGrade(void);
        void decrementGrade(void);

    /* ====================================================================== */
    /* EXCEPTIONS                                                             */
    /* ====================================================================== */

    /**
     * @class Exception
     * @brief Generic exception for the Bureaucrat class.
     * @details Inherits from std::exception. Serves as the base class for all 
     * specific Bureaucrat exceptions, allowing polymorphic catching.
     */
    class Exception : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class GradeTooHighException
     * @brief Exception thrown when a bureaucrat's grade goes above 1.
     * @details Inherits from Exception to provide custom error handling 
     * for invalid bureaucratic promotions or instantiations. This enables 
     * polymorphic catching through the generic Bureaucrat::Exception.
     */
    class GradeTooHighException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class GradeTooLowException
     * @brief Exception thrown when a bureaucrat's grade drops below 150.
     * @details Inherits from Exception to provide custom error handling 
     * for invalid bureaucratic demotions or instantiations. This enables 
     * polymorphic catching through the generic Bureaucrat::Exception.
     */
    class GradeTooLowException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };
};

/* ========================================================================== */
/* NON-MEMBER OPERATOR OVERLOADS                                              */
/* ========================================================================== */

std::ostream& operator<<(std::ostream& o, Bureaucrat const & bureaucrat);

#endif
