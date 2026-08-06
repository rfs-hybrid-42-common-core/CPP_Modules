/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 22:51:34 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/08 18:02:57 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Form::Form(void)
 * @brief Default constructor for the Form class.
 * @details Initializes a blank form with default signing (100) and executing 
 * (50) grades.
 */
Form::Form(void) :
    _name("Blank"),
    _isSigned(false),
    _gradeToSign(100),
    _gradeToExecute(50)
{
    std::cout << "The " << getName() << " form has been successfully printed. You require a grade of " << getGradeToSign() 
              << " to sign and a grade of " << getGradeToExecute() << " to execute." << std::endl;
}

/**
 * @fn Form::Form(std::string const & name, int gradeToSign, int gradeToExecute)
 * @brief Parameterized constructor for the Form class.
 * @details Validates the provided grade bounds during instantiation and throws 
 * exceptions if the grades fall outside the 1-150 range.
 * @param name           The name of the form.
 * @param gradeToSign    The grade required to sign the form.
 * @param gradeToExecute The grade required to execute the form.
 */
Form::Form(std::string const & name, int gradeToSign, int gradeToExecute) :
    _name(name),
    _isSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    if (getGradeToSign() < 1 || getGradeToExecute() < 1)
        throw GradeTooHighException();
    else if (getGradeToSign() > 150 || getGradeToExecute() > 150)
        throw GradeTooLowException();

    std::cout << "The " << getName() << " form has been successfully printed. You require a grade of " << getGradeToSign() 
              << " to sign and a grade of " << getGradeToExecute() << " to execute." << std::endl;
}

/**
 * @fn Form::Form(Form const & other)
 * @brief Copy constructor for the Form class.
 * @details Constructs a new Form object as a clone of an existing one. Since 
 * the name and grades are constant, they must be initialized via the 
 * initializer list.
 * @param other The Form object to copy from.
 */
Form::Form(Form const & other) :
    _name(other.getName()),
    _isSigned(false),
    _gradeToSign(other.getGradeToSign()),
    _gradeToExecute(other.getGradeToExecute())
{
    std::cout << "Another " << getName() << " form has been successfully printed. You require a grade of " << getGradeToSign() 
            << " to sign and a grade of " << getGradeToExecute() << " to execute." << std::endl;
}

/**
 * @fn Form::~Form(void)
 * @brief Destructor for the Form class.
 * @details Cleans up the Form object. Memory is managed automatically, but a 
 * standard destruction message is printed to track the object's lifecycle.
 */
Form::~Form(void)
{
    std::cout << "The " << getName() << " form has become obselete and has been sent to the shredder." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Form& Form::operator=(Form const & other)
 * @brief Copy assignment operator overload.
 * @details Updates the mutable attributes (isSigned) while safely ignoring the 
 * constant name and grade attributes. Contains a safeguard against 
 * self-assignment.
 * @param other The Form object to assign from.
 * @return      A reference to the updated Form object.
 */
Form& Form::operator=(Form const & other)
{
    if (this != &other && getIsSigned() != other.getIsSigned())
    {
        std::string signStatus = (_isSigned = other.getIsSigned()) ? "'signed'" : "'not signed'";
        std::cout << "The " << getName() << " form status has been updated to " << signStatus << "." << std::endl;
    }
    else
        std::cout << "No changes were applied to form " << getName() << "." << std::endl;

    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & Form::getName(void) const
 * @brief Retrieves the form's name.
 * @details Provides read-only access to the internal constant _name attribute.
 * @return A constant reference to the name string.
 */
std::string const & Form::getName(void) const
{
    return _name;
}

/**
 * @fn bool Form::getIsSigned(void) const
 * @brief Retrieves the signature status of the form.
 * @details Provides read-only access to the internal _isSigned boolean flag.
 * @return True if signed, false otherwise.
 */
bool Form::getIsSigned(void) const
{
    return _isSigned;
}

/**
 * @fn int Form::getGradeToSign(void) const
 * @brief Retrieves the required grade to sign the form.
 * @details Provides read-only access to the internal constant _gradeToSign 
 * attribute.
 * @return The integer value of the required signing grade.
 */
int Form::getGradeToSign(void) const
{
    return _gradeToSign;
}

/**
 * @fn int Form::getGradeToExecute(void) const
 * @brief Retrieves the required grade to execute the form.
 * @details Provides read-only access to the internal constant _gradeToExecute 
 * attribute.
 * @return The integer value of the required executing grade.
 */
int Form::getGradeToExecute(void) const
{
    return _gradeToExecute;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Form::beSigned(Bureaucrat const & bureaucrat)
 * @brief Attempts to sign the form based on a bureaucrat's grade.
 * @details Compares the bureaucrat's grade against the form's required signing 
 * grade. Throws a GradeTooLowException if the bureaucrat's grade is 
 * numerically too high (lower authority). Throws AlreadySignedException if the 
 * form is already signed.
 * @param bureaucrat The bureaucrat attempting to sign the form.
 */
void Form::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    getIsSigned() ? throw AlreadySignedException() : _isSigned = true;
}

/* ========================================================================== */
/* EXCEPTIONS                                                                 */
/* ========================================================================== */

/**
 * @fn const char* Form::GradeTooHighException::what() const throw()
 * @brief Returns the error message for grades that are too high.
 * @details Overrides the what() function from std::exception to provide a 
 * statically allocated string detailing the exact error without memory 
 * overhead.
 */
const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high.");
}

/**
 * @fn const char* Form::GradeTooLowException::what() const throw()
 * @brief Returns the error message for grades that are too low.
 * @details Overrides the what() function from std::exception to provide a 
 * statically allocated string detailing the exact error without memory 
 * overhead.
 */
const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low.");
}

/**
 * @fn const char* Form::AlreadySignedException::what() const throw()
 * @brief Returns the error message when a form is already signed.
 * @details Overrides the what() function from std::exception to prevent 
 * redundant actions and ensure proper bureaucratic procedure.
 */
const char* Form::AlreadySignedException::what() const throw()
{
    return ("the form is already signed.");
}

/* ========================================================================== */
/* NON-MEMBER OPERATOR OVERLOADS                                              */
/* ========================================================================== */

/**
 * @fn std::ostream& operator<<(std::ostream& o, Form const & form)
 * @brief Overloads the insertion operator for the Form class.
 * @details Extracts and formats all of the form's essential data properties 
 * into a readable output stream format.
 * @param o    The output stream object.
 * @param form The Form object to print.
 * @return     A reference to the modified output stream.
 */
std::ostream& operator<<(std::ostream& o, Form const & form)
{
    o << std::boolalpha << "[FORM INFO]"
      << "\nName: " << form.getName()
      << "\nSigned: " << form.getIsSigned()
      << "\nGrade to sign: " << form.getGradeToSign()
      << "\nGrade to execute: " << form.getGradeToExecute() << std::noboolalpha;
    return o;
}
