/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:08:13 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/07 03:24:54 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Bureaucrat.hpp"

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
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Bureaucrat::Bureaucrat(void)
 * @brief Default constructor for the Bureaucrat class.
 * @details Initializes the bureaucrat with a default name ("John Doe") and 
 * sets the initial grade to 100, fulfilling Orthodox Canonical Form.
 */
Bureaucrat::Bureaucrat(void) : _name("John Doe"), _grade(100)
{
    std::cout << "Welcome to the bureaucratic team " << getName() << ". Your initial grade is " << getGrade() << "." << std::endl;
}

/**
 * @fn Bureaucrat::Bureaucrat(std::string const & name, int grade)
 * @brief Parameterized constructor for the Bureaucrat class.
 * @details Validates the grade bounds and throws exceptions if invalid. Also 
 * sanitizes the input name using the trimWhitespaces helper function.
 * @param name  The name of the bureaucrat.
 * @param grade The initial grade of the bureaucrat.
 */
Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(trimWhitespaces(name)), _grade(grade)
{
    if (getGrade() < 1)
        throw GradeTooHighException();
    else if (getGrade() > 150)
        throw GradeTooLowException();

    std::cout << "Welcome to the bureaucratic team " << getName() << ". Your initial grade is " << getGrade() << "." << std::endl;
}

/**
 * @fn Bureaucrat::Bureaucrat(Bureaucrat const & other)
 * @brief Copy constructor for the Bureaucrat class.
 * @details Constructs a new Bureaucrat object as a clone of an existing one. 
 * Since the name is constant, it must be initialized in the initializer list.
 * @param other The Bureaucrat object to copy from.
 */
Bureaucrat::Bureaucrat(Bureaucrat const & other) : _name(other.getName()), _grade(other.getGrade())
{
    std::cout << "Wow, another " << getName() << " is joining our bureaucratic team. Welcome! Your initial grade is " << getGrade() << "." << std::endl;
}

/**
 * @fn Bureaucrat::~Bureaucrat(void)
 * @brief Destructor for the Bureaucrat class.
 * @details Cleans up the Bureaucrat object. Memory is managed automatically, 
 * but a standard sign-off message is printed to track object destruction.
 */
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Your shift is done for today " << getName() << ". There'll be more bureaucratic work for you to handle tomorrow." << std::endl;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn Bureaucrat& Bureaucrat::operator=(Bureaucrat const & other)
 * @brief Copy assignment operator overload.
 * @details Updates the mutable attributes (grade) while safely ignoring the 
 * constant name attribute. Protects against self-assignment.
 * @param other The Bureaucrat object to assign from.
 * @return      A reference to the updated Bureaucrat object.
 */
Bureaucrat& Bureaucrat::operator=(Bureaucrat const & other)
{
    if (this != &other && getGrade() != other.getGrade())
    {
        _grade = other.getGrade();
        std::cout << "Here's your newly updated profile " << getName() << ". From now on your grade is " << getGrade() << "." << std::endl;
    }
    else
        std::cout << "Sorry " << getName() << ", but unfortunately we're unable to update your bureaucrat profile since nothing changed." << std::endl;

    return *this;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & Bureaucrat::getName(void) const
 * @brief Retrieves the bureaucrat's name.
 * @details Provides read-only access to the internal constant _name attribute.
 * @return A constant reference to the name string.
 */
std::string const & Bureaucrat::getName(void) const
{
    return _name;
}

/**
 * @fn int Bureaucrat::getGrade(void) const
 * @brief Retrieves the bureaucrat's current grade.
 * @details Provides read-only access to the internal _grade attribute.
 * @return The integer value of the grade.
 */
int Bureaucrat::getGrade(void) const
{
    return _grade;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Bureaucrat::incrementGrade(void)
 * @brief Increases the bureaucrat's grade (closer to 1).
 * @details Subtracts 1 from the internal grade integer. Throws a 
 * GradeTooHighException if the resulting grade drops below 1.
 */
void Bureaucrat::incrementGrade(void)
{
    if (getGrade() - 1 < 1)
        throw GradeTooHighException();
    else
    {
        --_grade;
        std::cout << getName() << " grade has been increased." << std::endl;
    }
}

/**
 * @fn void Bureaucrat::decrementGrade(void)
 * @brief Decreases the bureaucrat's grade (closer to 150).
 * @details Adds 1 to the internal grade integer. Throws a 
 * GradeTooLowException if the resulting grade exceeds 150.
 */
void Bureaucrat::decrementGrade(void)
{
    if (getGrade() + 1 > 150)
        throw GradeTooLowException();
    else
    {
        ++_grade;
        std::cout << getName() << " grade has been decreased." << std::endl;
    }
}

/* ========================================================================== */
/* EXCEPTIONS                                                                 */
/* ========================================================================== */

/**
 * @fn const char* Bureaucrat::GradeTooHighException::what() const throw()
 * @brief Returns the error message for grades that are too high.
 * @details Overrides the what() function from std::exception to provide a 
 * strictly formatted error message without dynamic memory allocation.
 */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("The grade is too high.");
}

/**
 * @fn const char* Bureaucrat::GradeTooLowException::what() const throw()
 * @brief Returns the error message for grades that are too low.
 * @details Overrides the what() function from std::exception to provide a 
 * strictly formatted error message without dynamic memory allocation.
 */
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("The grade is too low.");
}

/* ========================================================================== */
/* NON-MEMBER OPERATOR OVERLOADS                                              */
/* ========================================================================== */

/**
 * @fn std::ostream& operator<<(std::ostream& o, Bureaucrat const & bureaucrat)
 * @brief Overloads the insertion operator for the Bureaucrat class.
 * @details Outputs the bureaucrat's status in the strictly required format 
 * `<name>, bureaucrat grade <grade>.` required by the subject.
 * @param o          The output stream object.
 * @param bureaucrat The Bureaucrat object to print.
 * @return           A reference to the modified output stream.
 */
std::ostream& operator<<(std::ostream& o, Bureaucrat const & bureaucrat)
{
    o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return o;
}
