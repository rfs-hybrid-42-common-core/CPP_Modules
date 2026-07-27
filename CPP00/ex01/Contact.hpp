/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:21:02 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:14:59 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */
/**
 * @class Contact
 * @brief Represents a single contact in the PhoneBook.
 * @details Stores personal information such as name, nickname, phone number, 
 * and darkest secret. Handles its own data validation and terminal display.
 */
class Contact
{
    private:
        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        Contact(void);
        ~Contact(void);

        /* ------------------------------------------------------------------ */
        /* GETTERS                                                            */
        /* ------------------------------------------------------------------ */
        std::string const & getFirstName(void) const;
        std::string const & getLastName(void) const;
        std::string const & getNickName(void) const;
        std::string const & getPhoneNumber(void) const;
        std::string const & getDarkestSecret(void) const;

        /* ------------------------------------------------------------------ */
        /* SETTERS                                                            */
        /* ------------------------------------------------------------------ */
        bool setFirstName(std::string const & firstName);
        bool setLastName(std::string const & lastName);
        bool setNickName(std::string const & nickName);
        bool setPhoneNumber(std::string const & phoneNumber);
        bool setDarkestSecret(std::string const & darkestSecret);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void displayContactInfo(void) const;
};

#endif
