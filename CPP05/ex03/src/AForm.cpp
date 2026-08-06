/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
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
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn AForm::AForm(void)
 * @brief Default constructor for the AForm class.
 * @details Initializes a blank form with default signing (100) and executing 
 * (50) grades.
 */
AForm::AForm(void) :
    _name("Blank"),
    _isSigned(false),
    _gradeToSign(100),
    _gradeToExecute(50)
{
    std::cout << "The " << getName() << " has been successfully printed. You require a grade of " << getGradeToSign() 
              << " to sign and a grade of " << getGradeToExecute() << " to execute." << std::endl;
}

/**
 * @fn AForm::AForm(std::string const & name, int gradeToSign, int gradeToExecute)
 * @brief Parameterized constructor for the AForm class.
 * @details Validates the provided grade bounds during instantiation and throws 
 * exceptions if the grades fall outside the 1-150 range.
 * @param name           The name of the form.
 * @param gradeToSign    The grade required to sign the form.
 * @param gradeToExecute The grade required to execute the form.
 */
AForm::AForm(std::string const & name, int gradeToSign, int gradeToExecute) :
    _name(name),
    _isSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    if (getGradeToSign() < 1 || getGradeToExecute() < 1)
        throw GradeTooHighException();
    else if (getGradeToSign() > 150 || getGradeToExecute() > 150)
        throw GradeTooLowException();

    std::cout << "The " << getName() << " has been successfully printed. You require a grade of " << getGradeToSign() 
              << " to sign and a grade of " << getGradeToExecute() << " to execute." << std::endl;
}

/**
 * @fn AForm::AForm(AForm const & other)
 * @brief Copy constructor for the AForm class.
 * @details Constructs a new AForm object as an exact clone of an existing one, 
 * copying all constant attributes as well as its current signature status via 
 * the initializer list.
 * @param other The AForm object to copy from.
 */
AForm::AForm(AForm const & other) :
    _name(other.getName()),
    _isSigned(other.getIsSigned()),
    _gradeToSign(other.getGradeToSign()),
    _gradeToExecute(other.getGradeToExecute())
{
    std::cout << "The " << getName() << " has been successfully duplicated. " << std::endl;
}

/**
 * @fn AForm::~AForm(void)
 * @brief Destructor for the AForm class.
 * @details Cleans up the AForm object. Memory is managed automatically, but a 
 * standard destruction message is printed to track the object's lifecycle.
 */
AForm::~AForm(void)
{
    std::cout << "The " << getName() << " has become obsolete and has been sent to the shredder." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn AForm& AForm::operator=(AForm const & other)
 * @brief Copy assignment operator overload.
 * @details Updates the mutable attributes (isSigned) while safely ignoring the 
 * constant name and grade attributes. Contains a safeguard against 
 * self-assignment and provides specific console output detailing whether the 
 * signature status was modified, remained unchanged, or if self-assignment 
 * was attempted.
 * @param other The AForm object to assign from.
 * @return      A reference to the updated AForm object.
 */
AForm& AForm::operator=(AForm const & other)
{
    if (this != &other)
    {
        if (getIsSigned() != other.getIsSigned())
        {
            std::string signStatus = (_isSigned = other.getIsSigned()) ? "'signed'" : "'not signed'";
            std::cout << "The " << getName() << " signature status has been updated to " << signStatus << "." << std::endl;
        }
        else
        {
            std::string signStatus = getIsSigned() ? "'signed'" : "'not signed'";
            std::cout << "The " << getName() << " signature status remains " << signStatus << "." << std::endl;
        }
    }
    else
        std::cout << "You provided the same " << getName() << ". No changes were applied." << std::endl;

    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & AForm::getName(void) const
 * @brief Retrieves the form's name.
 * @details Provides read-only access to the internal constant _name attribute.
 * @return A constant reference to the name string.
 */
std::string const & AForm::getName(void) const
{
    return _name;
}

/**
 * @fn bool AForm::getIsSigned(void) const
 * @brief Retrieves the signature status of the form.
 * @details Provides read-only access to the internal _isSigned boolean flag.
 * @return True if signed, false otherwise.
 */
bool AForm::getIsSigned(void) const
{
    return _isSigned;
}

/**
 * @fn int AForm::getGradeToSign(void) const
 * @brief Retrieves the required grade to sign the form.
 * @details Provides read-only access to the internal constant _gradeToSign 
 * attribute.
 * @return The integer value of the required signing grade.
 */
int AForm::getGradeToSign(void) const
{
    return _gradeToSign;
}

/**
 * @fn int AForm::getGradeToExecute(void) const
 * @brief Retrieves the required grade to execute the form.
 * @details Provides read-only access to the internal constant _gradeToExecute 
 * attribute.
 * @return The integer value of the required executing grade.
 */
int AForm::getGradeToExecute(void) const
{
    return _gradeToExecute;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void AForm::beSigned(Bureaucrat const & signatory)
 * @brief Attempts to sign the form based on a signatory's grade.
 * @details Compares the signatory's grade against the form's required signing 
 * grade. Throws a GradeTooLowException if the signatory's grade is 
 * numerically too high (lower authority). Throws AlreadySignedException if the 
 * form is already signed.
 * @param signatory The bureaucrat attempting to sign the form.
 */
void AForm::beSigned(Bureaucrat const & signatory)
{
    if (signatory.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    getIsSigned() ? throw AlreadySignedException() : _isSigned = true;
}

/**
 * @fn void AForm::execute(Bureaucrat const & executor) const
 * @brief Checks requirements and executes the form's action.
 * @details Enforces the Template Method Pattern. Verifies that the form 
 * is signed and that the executor's grade is high enough to execute it. 
 * If the checks pass, it delegates the specific behavior to the pure virtual 
 * executeAction() method.
 * @param executor The bureaucrat attempting to execute the form.
 */
void AForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    executeAction();
}

/* ========================================================================== */
/* EXCEPTIONS                                                                 */
/* ========================================================================== */

/**
 * @fn const char* AForm::Exception::what() const throw()
 * @brief Returns the generic error message for Form errors.
 * @details Overrides the what() function from std::exception to provide a 
 * statically allocated, generic error message. This serves as the fallback 
 * message for the base exception class, enabling clean polymorphic error 
 * handling without dynamic memory allocation overhead.
 */
const char* AForm::Exception::what() const throw()
{
    return ("encountered a generic error.");
}

/**
 * @fn const char* AForm::GradeTooHighException::what() const throw()
 * @brief Returns the error message for grades that are too high.
 * @details Inherits from AForm::Exception to provide specific error 
 * handling for invalid form instantiations or interactions. By overriding 
 * the what() method, it integrates seamlessly into the polymorphic exception 
 * catching structure.
 */
const char* AForm::GradeTooHighException::what() const throw()
{
    return ("grade is too high.");
}

/**
 * @fn const char* AForm::GradeTooLowException::what() const throw()
 * @brief Returns the error message for grades that are too low.
 * @details Inherits from AForm::Exception to provide specific error 
 * handling for invalid form instantiations or interactions. By overriding 
 * the what() method, it integrates seamlessly into the polymorphic exception 
 * catching structure.
 */
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("grade is too low.");
}

/**
 * @fn const char* AForm::AlreadySignedException::what() const throw()
 * @brief Returns the error message when a form is already signed.
 * @details Inherits from AForm::Exception to provide specific error 
 * handling to prevent redundant signatures. By overriding the what() method, 
 * it integrates seamlessly into the polymorphic exception catching structure.
 */
const char* AForm::AlreadySignedException::what() const throw()
{
    return ("is already signed.");
}

/**
 * @fn const char* AForm::NotSignedException::what() const throw()
 * @brief Returns the error message when an unsigned form is executed.
 * @details Inherits from AForm::Exception to enforce the rule that a form 
 * must be signed before it can be successfully executed. By overriding the 
 * what() method, it integrates seamlessly into the polymorphic exception 
 * catching structure.
 */
const char* AForm::NotSignedException::what() const throw()
{
    return ("is not signed.");
}

/* ========================================================================== */
/* NON-MEMBER OPERATOR OVERLOADS                                              */
/* ========================================================================== */

/**
 * @fn std::ostream& operator<<(std::ostream& o, AForm const & form)
 * @brief Overloads the insertion operator for the AForm class.
 * @details Extracts and formats all of the form's essential data properties 
 * into a readable output stream format.
 * @param o    The output stream object.
 * @param form The AForm object to print.
 * @return     A reference to the modified output stream.
 */
std::ostream& operator<<(std::ostream& o, AForm const & form)
{
    o << "[FORM INFO]"
      << "\nName: " << form.getName()
      << "\nSigned: " << (form.getIsSigned() ? "yes" : "no")
      << "\nGrade to sign: " << form.getGradeToSign()
      << "\nGrade to execute: " << form.getGradeToExecute();
    return o;
}
