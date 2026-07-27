/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:20:55 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:16:40 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Contact.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */
/**
 * @class PhoneBook
 * @brief Represents the main PhoneBook application.
 * @details Manages a limited array of Contact objects, handling adding, 
 * searching, and navigating the main execution loop. Uses a circular buffer 
 * pattern for contacts.
 */
class PhoneBook
{
    private:
        /* ------------------------------------------------------------------ */
        /* CONSTANTS & SETTINGS                                               */
        /* ------------------------------------------------------------------ */
        static const int _maxContacts = 8;
        static const int _maxLength = 10;

        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        Contact _contacts[_maxContacts];
        int     _currentIndex;

        /* ------------------------------------------------------------------ */
        /* PRIVATE METHODS                                                    */
        /* ------------------------------------------------------------------ */
        bool        _promptField(std::string const & prompt, bool (Contact::*setter)(std::string const &));
        bool        _addContact(void);
        std::string _truncatedString(std::string const & str) const;
        bool        _listContacts(void);
        bool        _searchContact(void);

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        PhoneBook(void);
        ~PhoneBook(void);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        bool executePhoneBook(void);
};

#endif
