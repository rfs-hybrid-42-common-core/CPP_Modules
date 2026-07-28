/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:30:06 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:10:55 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Replacer.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <sstream>

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Replacer::Replacer(std::string const & filename)
 * @brief Constructor for the Replacer class.
 * @details Initializes the _filename attribute using a member initializer list.
 * @param filename The name of the file to be processed.
 */
Replacer::Replacer(std::string const & filename) : _filename(filename) {}

/**
 * @fn Replacer::~Replacer(void)
 * @brief Destructor for the Replacer class.
 * @details Cleans up the Replacer object. No dynamic memory to manage.
 */
Replacer::~Replacer(void) {}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn bool Replacer::replace(std::string const & s1, std::string const & s2)
 * @brief Replaces all occurrences of s1 with s2 and writes to a new file.
 * @details Opens the source file, reads its entire content into memory, and 
 * manually iterates through the string using find() and substr(). Writes the 
 * processed text sequentially into a new file named "<filename>.replace". 
 * This approach avoids modifying the string in-place and prevents infinite 
 * loops when s1 is a substring of s2.
 * @param s1 The string to search for and replace.
 * @param s2 The string to insert in place of s1.
 * @return   True if file operations and replacements succeed, false if the 
 * input or output file fails to open.
 */
bool Replacer::replace(std::string const & s1, std::string const & s2)
{
    std::ifstream infile(_filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Failed to open file: " << _filename << std::endl;
        return false;
    }

    std::ostringstream ss;
    ss << infile.rdbuf();
    std::string content = ss.str();
    infile.close();

    std::ofstream outfile((_filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Failed to open file: " << _filename << ".replace" << std::endl;
        return false;
    }

    size_t currPos = 0;
    size_t prevPos = 0;
    for (; (currPos = content.find(s1, prevPos)) != std::string::npos; prevPos = currPos + s1.length())
    {
        outfile << content.substr(prevPos, currPos - prevPos);
        outfile << s2;
    }
    outfile << content.substr(prevPos);
    outfile.close();

    return true;
}
