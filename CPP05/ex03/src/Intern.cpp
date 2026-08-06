/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:08:21 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 03:14:28 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* HELPER FUNCTIONS                                                           */
/* ========================================================================== */

/**
 * @fn static std::string trimWhitespaces(std::string const & str)
 * @brief Trims leading and trailing whitespaces from a string.
 * @details Scans the input string to find the first and last non-whitespace 
 * characters and returns the substring containing the actual content.
 * @param str The standard string to be trimmed.
 * @return    A newly constructed trimmed string or an empty string if the 
 * input contains only whitespaces.
 */
static std::string trimWhitespaces(std::string const & str)
{
    size_t start = str.find_first_not_of(" \t\n\v\f\r");
    if (start == std::string::npos) return "John Doe";
    size_t end = str.find_last_not_of(" \t\n\v\f\r");

    return str.substr(start, end - start + 1);
}

/* ========================================================================== */
/* PRIVATE METHODS                                                            */
/* ========================================================================== */

/**
 * @fn AForm* Intern::_makeShrubbery(std::string const & target)
 * @brief Helper function to instantiate a ShrubberyCreationForm.
 * @details Dynamically allocates a new form using the provided target string. 
 * @param target The string representing the target file's prefix.
 * @return       A pointer to the newly allocated AForm object.
 */
AForm* Intern::_makeShrubbery(std::string const & target)
{
    return new ShrubberyCreationForm(target);
}

/**
 * @fn AForm* Intern::_makeRobotomy(std::string const & target)
 * @brief Helper function to instantiate a RobotomyRequestForm.
 * @details Dynamically allocates a new form using the provided target string. 
 * @param target The string representing the target to be robotomized.
 * @return       A pointer to the newly allocated AForm object.
 */
AForm* Intern::_makeRobotomy(std::string const & target)
{
    return new RobotomyRequestForm(target);
}

/**
 * @fn AForm* Intern::_makePardon(std::string const & target)
 * @brief Helper function to instantiate a PresidentialPardonForm.
 * @details Dynamically allocates a new form using the provided target string. 
 * @param target The string representing the target to be pardoned.
 * @return       A pointer to the newly allocated AForm object.
 */
AForm* Intern::_makePardon(std::string const & target)
{
    return new PresidentialPardonForm(target);
}

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Intern::Intern(void)
 * @brief Default constructor for the Intern class.
 * @details Announces the recruitment of a new intern to the standard output.
 */
Intern::Intern(void)
{
    std::cout << "A new intern has been recruited to make bureaucratic forms." << std::endl;
}

/**
 * @fn Intern::Intern(Intern const & other)
 * @brief Copy constructor for the Intern class.
 * @details Since the intern has no unique characteristics, it simply announces 
 * the recruitment of another intern.
 * @param other The Intern object to copy from (unused).
 */
Intern::Intern(Intern const & other)
{
    (void)other;
    std::cout << "Another intern has been recruited to make bureaucratic forms." << std::endl;
}

/**
 * @fn Intern::~Intern(void)
 * @brief Destructor for the Intern class.
 * @details Announces the dismissal of the intern to the standard output.
 */
Intern::~Intern(void)
{
    std::cout << "An intern has been dismissed from making bureaucratic forms." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Intern& Intern::operator=(Intern const & other)
 * @brief Copy assignment operator overload.
 * @details Since the intern has no mutable state, this operator satisfies the 
 * Orthodox Canonical Form but performs no actual data assignment.
 * @param other The Intern object to assign from (unused).
 * @return      A reference to the unmodified Intern object.
 */
Intern& Intern::operator=(Intern const & other)
{
    (void)other;
    std::cout << "The intern's duties have not changed." << std::endl;
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn AForm* Intern::makeForm(std::string const & name, std::string const & target)
 * @brief Generates a new concrete form based on a string name.
 * @details Uses an array of strings and an array of member function pointers 
 * to dispatch the form creation logic without utilizing if/elseif/else chains. 
 * Prints a success message or throws an explicit error if the form does not 
 * exist.
 * @param name   The requested type of form.
 * @param target The target attribute to pass to the form's constructor.
 * @return       A pointer to the dynamically allocated AForm object.
 */
AForm* Intern::makeForm(std::string const & name, std::string const & target)
{
    static std::string const formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    static AForm* (Intern::*funcs[3])(std::string const & target) 
        = {&Intern::_makeShrubbery, &Intern::_makeRobotomy, &Intern::_makePardon};

    std::string const trimmedName = trimWhitespaces(name);
    std::string const trimmedTarget = trimWhitespaces(target);

    for (int i = 0; i < 3; ++i)
    {
        if (trimmedName == formNames[i])
        {
            AForm* form = (this->*funcs[i])(trimmedTarget);
            std::cout << "Intern creates " << form->getName() << "." << std::endl;
            return form;
        }
    }
    throw FormNotFound();
}

/* ========================================================================== */
/* EXCEPTIONS                                                                 */
/* ========================================================================== */

/**
 * @fn const char* Intern::Exception::what() const throw()
 * @brief Returns the generic error message for Intern errors.
 * @details Overrides the what() function from std::exception to provide a 
 * statically allocated, generic error message. This serves as the fallback 
 * message for the base exception class, enabling clean polymorphic error 
 * handling without dynamic memory allocation overhead.
 */
const char* Intern::Exception::what() const throw()
{
    return ("encountered a generic error.");
}

/**
 * @fn const char* Intern::FormNotFound::what() const throw()
 * @brief Error message for unknown form requests.
 * @details Inherits from Intern::Exception to provide specific error handling 
 * when the intern fails to match the requested form name. By overriding the 
 * what() method, it integrates seamlessly into the polymorphic exception 
 * catching structure.
 */
const char* Intern::FormNotFound::what() const throw()
{
    return ("form not found.");
}
