/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 02:02:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/10 01:49:35 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "RobotomyRequestForm.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cstdlib>

/* ========================================================================== */
/* PRIVATE METHODS                                                            */
/* ========================================================================== */

/**
 * @fn void RobotomyRequestForm::executeAction(void) const
 * @brief Executes the specific action of the Robotomy form.
 * @details Simulates drilling noises and utilizes std::rand() to determine 
 * the success of the robotomy with a 50% probability, printing the outcome 
 * as required by the subject.
 */
void RobotomyRequestForm::executeAction(void) const
{
    std::cout << "Beginning the robotomy procedure... Bzzzzzt! Vrrrrr-clack-clack-clack!" << std::endl;
    std::string result = std::rand() % 2 ? "a success." : "an absolute disaster.";
    std::cout << getTarget() << "'s robotomy was " << result << std::endl;
}

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn RobotomyRequestForm::RobotomyRequestForm(void)
 * @brief Default constructor for the RobotomyRequestForm class.
 * @details Initializes the base AForm with strict Robotomy grades (Sign 72, 
 * Exec 45) and sets a default target of "robot".
 */
RobotomyRequestForm::RobotomyRequestForm(void) :
    AForm("Robotomy Request Form", _signGrade, _execGrade),
    _target("robot")
{
    std::cout << getName() << " was successfully generated. Its destination target is " << getTarget() << "." << std::endl;
}

/**
 * @fn RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
 * @brief Parameterized constructor for the RobotomyRequestForm class.
 * @details Initializes the base AForm with strict Robotomy grades and assigns 
 * the specific target for the procedure.
 * @param target The string representing the target to be robotomized.
 */
RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
    AForm("Robotomy Request Form", _signGrade, _execGrade),
    _target(target)
{
    std::cout << getName() << " was successfully generated. Its destination target is " << getTarget() << "." << std::endl;
}

/**
 * @fn RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other)
 * @brief Copy constructor for the RobotomyRequestForm class.
 * @details Constructs a new object by deeply copying the base AForm properties 
 * and the specific _target attribute.
 * @param other The RobotomyRequestForm object to copy from.
 */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other) :
    AForm(other),
    _target(other.getTarget())
{
    std::cout << getName() << " was successfully duplicated. Its destination target is " << getTarget() << "." << std::endl;
}

/**
 * @fn RobotomyRequestForm::~RobotomyRequestForm(void)
 * @brief Destructor for the RobotomyRequestForm class.
 * @details Safely destroys the form.
 */
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << getName() << " has fulfilled its purpose and is no longer needed." << std::endl;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & RobotomyRequestForm::getTarget(void) const
 * @brief Retrieves the form's target.
 * @details Provides read-only access to the target string attribute.
 * @return A constant reference to the target string.
 */
std::string const & RobotomyRequestForm::getTarget(void) const
{
    return _target;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
 * @brief Copy assignment operator.
 * @details Safely calls the base class assignment operator to copy the signature 
 * status, then assigns the specific _target. Protects against self-assignment.
 * @param other The RobotomyRequestForm to assign from.
 * @return      A reference to the newly updated object.
 */
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        if (getTarget() != other.getTarget())
        {
            _target = other.getTarget();
            std::cout << getName() << " new target is " << getTarget() << "." << std::endl;
        }
        else
            std::cout << "The target is still " << getTarget() << "." << std::endl;
    }
    else
        std::cout << "You provided the same " << getName() << ". No changes were applied." << std::endl;
    return *this;
}
