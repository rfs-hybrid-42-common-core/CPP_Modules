/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:21:52 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:16:01 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "PhoneBook.hpp"
#include "utils.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <iomanip>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn PhoneBook::PhoneBook(void)
 * @brief Default constructor for PhoneBook.
 * @details Initializes the current index to 0. The internal array of Contacts 
 * is automatically initialized.
 */
PhoneBook::PhoneBook(void) : _currentIndex(0) {}

/**
 * @fn PhoneBook::~PhoneBook(void)
 * @brief Destructor for PhoneBook.
 * @details Cleans up the PhoneBook object. Memory is managed automatically as 
 * dynamic allocation is not used.
 */
PhoneBook::~PhoneBook(void) {}

/* ========================================================================== */
/* PRIVATE METHODS                                                            */
/* ========================================================================== */

/**
 * @fn bool PhoneBook::_promptField(std::string const & prompt, 
 * bool (Contact::*setter)(std::string const &))
 * @brief Prompts the user for a specific contact field and applies it.
 * @details Enters a loop requesting input until valid data is provided for the 
 * field. Uses a pointer-to-member function to delegate assignment to the 
 * current Contact. 
 * @param prompt The string message displayed to the user.
 * @param setter A pointer to the Contact member function responsible for 
 * saving the specific field.
 * @return       True if the field was successfully set, false on critical 
 * input failure (EOF/Error).
 */
bool PhoneBook::_promptField(std::string const & prompt, bool (Contact::*setter)(std::string const &))
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            if (std::cin.eof())
                std::cout << "\nEOF error detected, exiting program..." << std::endl;
            else
                std::cout << "\nUnknown input error detected, exiting program..." << std::endl;
            return false;
        }

        if ((_contacts[_currentIndex].*setter)(input)) return true;

        std::cout << "Invalid input detected, try again..." << std::endl;
    }
}

/**
 * @fn bool PhoneBook::_addContact(void)
 * @brief Handles the full sequence of adding a new contact.
 * @details Prompts for each contact field sequentially. If successful, stores 
 * the contact and increments the circular index so the oldest contact is 
 * overwritten if the book is full.
 * @return True on success, false if a critical input failure occurs during any prompt.
 */
bool PhoneBook::_addContact(void)
{
    if (!_promptField("Enter first name: ", &Contact::setFirstName)) return false;
    if (!_promptField("Enter last name: ", &Contact::setLastName)) return false;
    if (!_promptField("Enter nick name: ", &Contact::setNickName)) return false;
    if (!_promptField("Enter phone number: ", &Contact::setPhoneNumber)) return false;
    if (!_promptField("Enter darkest secret: ", &Contact::setDarkestSecret)) return false;

    std::cout << "New contact was saved successfully!" << std::endl;
    _currentIndex = (_currentIndex + 1) % _maxContacts;
    return true;
}

/**
 * @fn std::string PhoneBook::_truncatedString(std::string const & str) const
 * @brief Truncates a string to fit the column width requirements.
 * @details If the string exceeds the maximum column length, it is truncated 
 * and the last visible character is replaced with a dot ('.').
 * @param str The string to format.
 * @return    The correctly sized and potentially truncated string.
 */
std::string PhoneBook::_truncatedString(std::string const & str) const
{
    if (str.length() > _maxLength)
        return (str.substr(0, _maxLength - 1) + ".");
    return str;
}

/**
 * @fn bool PhoneBook::_listContacts(void)
 * @brief Displays the grid/table of currently saved contacts.
 * @details Prints up to 8 contacts in a formatted table with exactly 
 * 10-character wide columns. Only lists entries that actually contain data.
 * @return True if there are contacts to display, false if the phonebook is 
 * completely empty.
 */
bool PhoneBook::_listContacts(void)
{
    if (_contacts[0].getFirstName().empty())
    {
        std::cout << "The PhoneBook list is empty!" << std::endl;
        return false;
    } 

    const std::string sep = "+----------+----------+----------+----------+\n";
    std::cout << sep << std::right
              << "|" << std::setw(_maxLength) << "Index"
              << "|" << std::setw(_maxLength) << "First Name"
              << "|" << std::setw(_maxLength) << "Last Name"
              << "|" << std::setw(_maxLength) << "Nick Name"
              << "|\n" << sep;

    for (int i = 0; i < _maxContacts; ++i)
    {
        if (_contacts[i].getFirstName().empty())
            break;
        std::cout << "|" << std::setw(_maxLength) << std::right << i
                  << "|" << std::setw(_maxLength) << _truncatedString(_contacts[i].getFirstName())
                  << "|" << std::setw(_maxLength) << _truncatedString(_contacts[i].getLastName())
                  << "|" << std::setw(_maxLength) << _truncatedString(_contacts[i].getNickName())
                  << "|" << std::endl;
    }
    std::cout << sep << std::endl;
    return true;
}

/**
 * @fn bool PhoneBook::_searchContact(void)
 * @brief Handles the SEARCH command flow.
 * @details Displays the contact table, prompts the user for an index, 
 * validates the input (checking for out-of-bounds, non-numeric, or empty 
 * data), and displays the chosen contact.
 * @return True if the search sequence completes or catches standard errors, 
 * false only on critical input failure (EOF/Stream error).
 */
bool PhoneBook::_searchContact(void)
{
    if (!_listContacts()) return true;

    std::string input;
    std::cout << "Pick an index [0-7] to check the contact's info: ";
    if (!std::getline(std::cin, input))
    {
        if (std::cin.eof())
            std::cout << "\nEOF error detected, exiting program..." << std::endl;
        else
            std::cout << "\nUnknown input error detected, exiting program..." << std::endl;
        return false;
    }

    input = trimWhitespaces(input);

    if (input.empty() || input.length() > 1 || !std::isdigit(static_cast<unsigned char>(input[0])))
    {
        std::cout << "Error: Invalid input format. Returning to main menu..." << std::endl;
        return true;
    }

    int index = input[0] - '0';

    if (index >= _maxContacts)
        std::cout << "Error: Index is out of range. Returning to main menu..." << std::endl;
    else if (_contacts[index].getFirstName().empty())
        std::cout << "Error: No contact saved at this index. Returning to main menu..." << std::endl;
    else
        _contacts[index].displayContactInfo();

    return true;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn bool PhoneBook::executePhoneBook(void)
 * @brief Starts the main application loop.
 * @details The primary CLI loop that continuously prompts the user for 
 * commands (ADD, SEARCH, EXIT) and routes to the appropriate internal method. 
 * Terminates gracefully on EXIT command.
 * @return True if application exits cleanly via EXIT command, false if an 
 * unrecoverable input error (e.g., EOF) occurs.
 */
bool PhoneBook::executePhoneBook(void)
{
    std::cout << "Welcome to the C++ Awesome PhoneBook App!" << std::endl;

    while (true)
    {
        std::string command;
        std::cout << "\nChoose any of the following commands: ADD, SEARCH or EXIT: " << std::endl;
        if (!std::getline(std::cin, command))
        {
            if (std::cin.eof())
                std::cout << "\nEOF error detected, exiting program..." << std::endl;
            else
                std::cout << "\nUnknown input error detected, exiting program..." << std::endl;
            return false;
        }

        command = trimWhitespaces(command);

        if (command == "ADD")
        {
            if (!_addContact()) return false;
        }
        else if (command == "SEARCH")
        {
            if (!_searchContact()) return false;
        } 
        else if (command == "EXIT")
        {
            std::cout << "\nThank you for using the C++ Awesome Phonebook App. Have a nice day! :)" << std::endl;
            break;
        }
        else
            std::cout << "Invalid command detected!" << std::endl;
    }
    return true;
}
