/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:21:50 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:53:17 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Contact.hpp"
#include "utils.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <cctype>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Contact::Contact(void)
 * @brief Default constructor for the Contact class.
 * @details Initializes an empty Contact object.
 */
Contact::Contact(void) {}

/**
 * @fn Contact::~Contact(void)
 * @brief Destructor for the Contact class.
 * @details Cleans up the Contact object.
 */
Contact::~Contact(void) {}

/* ========================================================================== */
/* PUBLIC GETTERS                                                             */
/* ========================================================================== */

/**
 * @fn std::string const & Contact::getFirstName(void) const
 * @brief Retrieves the contact's first name.
 * @details Provides read-only access to the internal _firstName attribute.
 * @return A constant reference to the first name.
 */
std::string const & Contact::getFirstName(void) const
{
    return _firstName;
}

/**
 * @fn std::string const & Contact::getLastName(void) const
 * @brief Retrieves the contact's last name.
 * @details Provides read-only access to the internal _lastName attribute.
 * @return A constant reference to the last name.
 */
std::string const & Contact::getLastName(void) const
{
    return _lastName;
}

/**
 * @fn std::string const & Contact::getNickName(void) const
 * @brief Retrieves the contact's nickname.
 * @details Provides read-only access to the internal _nickName attribute.
 * @return A constant reference to the nickname.
 */
std::string const & Contact::getNickName(void) const
{
    return _nickName;
}

/**
 * @fn std::string const & Contact::getPhoneNumber(void) const
 * @brief Retrieves the contact's phone number.
 * @details Provides read-only access to the internal _phoneNumber attribute.
 * @return A constant reference to the phone number.
 */
std::string const & Contact::getPhoneNumber(void) const
{
    return _phoneNumber;
}

/**
 * @fn std::string const & Contact::getDarkestSecret(void) const
 * @brief Retrieves the contact's darkest secret.
 * @details Provides read-only access to the internal _darkestSecret attribute.
 * @return A constant reference to the darkest secret.
 */
std::string const & Contact::getDarkestSecret(void) const
{
    return _darkestSecret;
}

/* ========================================================================== */
/* PUBLIC SETTERS                                                             */
/* ========================================================================== */

/**
 * @fn bool Contact::setFirstName(std::string const & firstName)
 * @brief Validates and sets the contact's first name.
 * @details Trims the input string. Fails if the resulting string is empty.
 * @param firstName The input string to set.
 * @return          True if successful, false if the input is invalid.
 */
bool Contact::setFirstName(std::string const & firstName)
{
    std::string trimmed = trimWhitespaces(firstName);
    if (trimmed.empty()) return false;

    _firstName = trimmed;
    return true;
}

/**
 * @fn bool Contact::setLastName(std::string const & lastName)
 * @brief Validates and sets the contact's last name.
 * @details Trims the input string. Fails if the resulting string is empty.
 * @param lastName The input string to set.
 * @return         True if successful, false if the input is invalid.
 */
bool Contact::setLastName(std::string const & lastName)
{
    std::string trimmed = trimWhitespaces(lastName);
    if (trimmed.empty()) return false;

    _lastName = trimmed;
    return true;
}

/**
 * @fn bool Contact::setNickName(std::string const & nickName)
 * @brief Validates and sets the contact's nickname.
 * @details Trims the input string. Fails if the resulting string is empty.
 * @param nickName The input string to set.
 * @return         True if successful, false if the input is invalid.
 */
bool Contact::setNickName(std::string const & nickName)
{
    std::string trimmed = trimWhitespaces(nickName);
    if (trimmed.empty()) return false;

    _nickName = trimmed;
    return true;
}

/**
 * @fn bool Contact::setPhoneNumber(std::string const & phoneNumber)
 * @brief Validates and sets the contact's phone number.
 * @details Trims the input string and verifies its format. A valid phone 
 * number may start with an optional '+' sign (which must be immediately 
 * followed by a digit), followed by numerical digits and spaces.
 * @param phoneNumber The input string to set.
 * @return            True if successful, false if empty, contains invalid 
 * characters, or has improper '+' usage.
 */
bool Contact::setPhoneNumber(std::string const & phoneNumber)
{
    std::string trimmed = trimWhitespaces(phoneNumber);
    if (trimmed.empty()) return false;

    size_t i = 0;
    size_t len = trimmed.length();
    if (trimmed[i] == '+')
    {
        if (len == 1 || !std::isdigit(static_cast<unsigned char>(trimmed[i + 1])))
            return false;
        ++i;
    }

    while(i < len)
    {
        if (!std::isdigit(static_cast<unsigned char>(trimmed[i]))
            && !std::isspace(static_cast<unsigned char>(trimmed[i])))
            return false;
        ++i;
    }

    _phoneNumber = trimmed;
    return true;
}

/**
 * @fn bool Contact::setDarkestSecret(std::string const & darkestSecret)
 * @brief Validates and sets the contact's darkest secret.
 * @details Trims the input string. Fails if the resulting string is empty.
 * @param darkestSecret The input string to set.
 * @return              True if successful, false if the input is invalid.
 */
bool Contact::setDarkestSecret(std::string const & darkestSecret)
{
    std::string trimmed = trimWhitespaces(darkestSecret);
    if (trimmed.empty()) return false;

    _darkestSecret = trimmed;
    return true;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Contact::displayContactInfo(void) const
 * @brief Displays the full details of the contact.
 * @details Prints formatted headers and lists each contact attribute on a new 
 * line.
 */
void Contact::displayContactInfo(void) const
{
    std::cout << "\n*********************************************\n"
              << "*************** CONTACT INFO ****************\n"
              << "*********************************************\n"
              << "First name: " << _firstName << "\n"
              << "Last name: " << _lastName << "\n"
              << "Nickname: " << _nickName << "\n"
              << "Phone number: " << _phoneNumber << "\n"
              << "Darkest secret: " << _darkestSecret << std::endl;
}
