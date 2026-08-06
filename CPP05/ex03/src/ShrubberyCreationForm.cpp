/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 02:02:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/15 03:05:19 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "ShrubberyCreationForm.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <fstream>

/* ========================================================================== */
/* PRIVATE METHODS                                                            */
/* ========================================================================== */

/**
 * @fn void ShrubberyCreationForm::executeAction(void) const
 * @brief Executes the specific action of the Shrubbery form.
 * @details Creates a file named <target>_shrubbery in the current working 
 * directory and writes an ASCII art tree into it as required by the subject. 
 * Throws a FileOpenException if the file cannot be created or opened.
 */
void ShrubberyCreationForm::executeAction(void) const
{
    std::ofstream outfile((getTarget() + "_shrubbery").c_str());
    if (!outfile.is_open())
        throw FileOpenException();

    outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠒⠉⠉⠉⢢⠤⠤⡀⢀⣀⣀⠀⡠⠖⠋⠉⠉⠒⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⠀⠀⢀⠎⠀⠀⠀⠙⠄⠀⠀⠀⠀⠀⠈⡇⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠐⠠⠄⡀⠀⠀⠀⢀⠄⠈⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠈⡇⠀⠀⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠹⠔⠒⠢⠇⠀⠀⠀⠀⠀⠀⠠⠤⡖⠁⠘⡄⠀⠀⠀⠀⣠⣃⠀⠀⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠀⢀⡠⠤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠀⠰⡄⠀⠀⠈⠁⠀⠙⣄⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⡔⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠁⠀⠀⠀⠀⠀⠀⡜⠂⠲⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠉⠀⠉⢢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣞⠀⠀⠘⠒⠂⡀\n"
            << "⠀⢀⡠⠐⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⠘⠂⠈⠆⠀⠀⠀⠀⠀⠀⠈⡆⠀⠀⠀⠀⡝\n"
            << "⢠⠋⠀⠀⠀⡠⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢄⣀⣀⡠⡂⠀⠀⠀⠠⡄⠀⠀⢀⡀⠀⢀⡰⠃⠀⠀⠀⠺⣅\n"
            << "⡇⠀⠀⠀⠀⠣⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⡄⠀⠰⣀⡠⣀⠀⢀⣠⠎⠉⣹⣀⠀⠀⠀⠀⠀⣸\n"
            << "⡇⠀⠀⠀⠀⢰⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣤⢷⠒⠂⠐⡎⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠁⠀⠉⢢⠀⢰⠊⠁\n"
            << "⠘⢤⡤⠀⠀⠀⠑⠂⠐⢆⠀⣄⣀⣀⠀⠀⡀⢀⡴⠀⠀⡧⣀⠜⠑⠂⢺⢳⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡜⠐⠃⠀⠀\n"
            << "⠀⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⢎⠀⠡⠀⠀⠱⡀⣠⠀⠀⡏⠈⢱⢲⠂⠀⠀⠀⠀⠀⠀⠀⠀⠱⠀⠀⠀⠀\n"
            << "⠀⠱⣄⡀⣠⠃⠀⠀⠀⠀⠀⠀⠀⠉⢫⣁⢫⡳⢄⢣⠀⠀⠉⠀⠀⢰⠇⢀⠇⢾⡻⠖⢖⠁⠀⡀⡀⠀⢀⡼⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠸⡀⠀⠀⠀⠐⣄⣀⣀⡠⠎⠓⢯⡀⠀⢸⠀⠀⠀⠀⠀⣸⢁⠎⡴⡋⠀⠀⠀⡉⠉⠀⠈⡏⠁⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠉⠒⠒⠒⠋⠀⠀⠀⠀⠀⠀⠀⠹⡄⠀⠀⠀⠀⠀⠀⣿⢏⡾⠝⠓⠢⠤⠊⠈⠑⠒⠊⠀⠀⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣧⠀⠀⠀⡠⠄⣀⣿⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⢸⡜⣉⢿⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⠀⠸⡱⡻⡸⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢤⡤⢄⡀⠀⢀⣀⣀⢇⠀⠀⠀⠉⠈⠀⡎⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠀⠀⠠⢤⡤⠀⢘⡆⠈⠋⣑⣽⣾⠌⠀⠀⠀⠀⠀⠀⠣⣸⣄⠀⢹⡅⠀⠔⠪⠿⢤⣤⠀⠀⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠀⠀⠐⠈⠉⠀⢀⣤⣖⣋⣁⣀⣋⣀⣀⠀⠒⠒⠄⠀⠀⠈⠈⠓⠦⢤⣀⠀⠀⠀⠀⠀⠑⠀⠀⠀⠀⠀⠀\n"
            << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠒⠦⣄⣸⡟⠒⠒⠒⠒⠒⠚⠛⠀⠀⠀⠀⠀⢰⣶⣶⣶⣶⣶" << std::endl;
    outfile.close();
}

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn ShrubberyCreationForm::ShrubberyCreationForm(void)
 * @brief Default constructor for the ShrubberyCreationForm class.
 * @details Initializes the base AForm with strict Shrubbery grades (Sign 145, 
 * Exec 137) and sets a default target of "shrub".
 */
ShrubberyCreationForm::ShrubberyCreationForm(void) :
    AForm("Shrubbery Creation Form", _signGrade, _execGrade),
    _target("shrub")
{
    std::cout << getName() << " was successfully generated. Its destination target is " << getTarget() << "." << std::endl;
}

/**
 * @fn ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
 * @brief Parameterized constructor for the ShrubberyCreationForm class.
 * @details Initializes the base AForm with strict Shrubbery grades and assigns 
 * the specific target for the ASCII tree planting.
 * @param target The string representing the target file's prefix.
 */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
    AForm("Shrubbery Creation Form", _signGrade, _execGrade),
    _target(target)
{
    std::cout << getName() << " was successfully generated. Its destination target is " << getTarget() << "." << std::endl;
}

/**
 * @fn ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other)
 * @brief Copy constructor for the ShrubberyCreationForm class.
 * @details Constructs a new object by deeply copying the base AForm properties 
 * and the specific _target attribute.
 * @param other The ShrubberyCreationForm object to copy from.
 */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other) :
    AForm(other),
    _target(other.getTarget())
{
    std::cout << getName() << " was successfully duplicated. Its destination target is " << getTarget() << "." << std::endl;
}

/**
 * @fn ShrubberyCreationForm::~ShrubberyCreationForm(void)
 * @brief Destructor for the ShrubberyCreationForm class.
 * @details Safely destroys the form.
 */
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << getName() << " has fulfilled its purpose and is no longer needed." << std::endl;
}

/* ========================================================================== */
/* GETTERS                                                                    */
/* ========================================================================== */

/**
 * @fn std::string const & ShrubberyCreationForm::getTarget(void) const
 * @brief Retrieves the form's target.
 * @details Provides read-only access to the target string attribute.
 * @return A constant reference to the target string.
 */
std::string const & ShrubberyCreationForm::getTarget(void) const
{
    return _target;
}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
 * @brief Copy assignment operator.
 * @details Safely calls the base class assignment operator to copy the 
 * signature status, then assigns the specific _target. Protects against 
 * self-assignment.
 * @param other The ShrubberyCreationForm to assign from.
 * @return      A reference to the newly updated object.
 */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
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

/* ========================================================================== */
/* EXCEPTIONS                                                                 */
/* ========================================================================== */

/**
 * @fn const char* ShrubberyCreationForm::FileOpenException::what() const throw()
 * @brief Error message for failed file creation.
 * @details Overrides the what() function from std::exception to provide a 
 * statically allocated string detailing that the output file stream failed 
 * to open or create the target file. By inheriting from AForm::Exception, it 
 * integrates seamlessly into the polymorphic exception catching structure.
 */
const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return ("the file could not be opened.");
}
