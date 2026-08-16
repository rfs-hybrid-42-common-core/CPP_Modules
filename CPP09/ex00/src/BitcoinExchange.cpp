/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:44:26 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/24 03:59:03 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "BitcoinExchange.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <sstream>
#include <cctype>

/* ========================================================================== */
/* CONSTANTS & SETTINGS                                                       */
/* ========================================================================== */

const char* BitcoinExchange::_DB_FILENAME = "data.csv";

/* ========================================================================== */
/* PRIVATE METHODS                                                            */
/* ========================================================================== */

/**
 * @fn std::string BitcoinExchange::_trimWhitespaces(std::string const & str)
 * @brief Trims leading and trailing whitespaces from a string.
 * @details Scans the input string to find the first and last non-whitespace 
 * characters and returns the substring containing the actual content.
 * @param str The standard string to be trimmed.
 * @return    A newly constructed trimmed string or an empty string if the 
 * input contains only whitespaces.
 */
std::string BitcoinExchange::_trimWhitespaces(std::string const & str)
{
    size_t start = str.find_first_not_of(" \t\n\v\f\r");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t\n\v\f\r");

    return str.substr(start, end - start + 1);
}

/**
 * @fn void BitcoinExchange::_validateHeader(std::ifstream& file, std::string const & leftExp, std::string const & rightExp, char delim)
 * @brief Validates the strict column header format for the active file.
 * @details Ignores leading empty or whitespace-only lines. Verifies the exact 
 * strings expected on the left and right of a specific delimiter.
 * @param file     The active file stream being parsed.
 * @param leftExp  The expected string for the left column (e.g. "date").
 * @param rightExp The expected string for the right column.
 * @param delim    The specific character delimiting the two columns.
 * @throws         EmptyFileException if EOF is reached before text is found.
 * @throws         InvalidHeaderException if the format or strings mismatch.
 */
void BitcoinExchange::_validateHeader(std::ifstream& file, std::string const & leftExp, std::string const & rightExp, char delim)
{
    std::string line;
    bool foundHeader = false;

    while (std::getline(file, line))
    {
        if (!_trimWhitespaces(line).empty())
        {
            foundHeader = true;
            break;
        }
    }

    if (!foundHeader)
        throw EmptyFileException();

    std::istringstream iss(line);
    std::string leftToken;

    if (!std::getline(iss, leftToken, delim) || _trimWhitespaces(leftToken) != leftExp)
        throw InvalidHeaderException();

    std::string rightToken;
    if (!std::getline(iss, rightToken) || _trimWhitespaces(rightToken) != rightExp)
        throw InvalidHeaderException();
}

/**
 * @fn bool BitcoinExchange::_isLeapYear(int year) const
 * @brief Determines if a given year is a Gregorian leap year.
 * @details Applies the standard logic: years divisible by 4 are leap years, 
 * except those divisible by 100, unless they are also divisible by 400.
 * @param year The integer year to check.
 * @return     true if the year is a leap year, false otherwise.
 */
bool BitcoinExchange::_isLeapYear(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * @fn void BitcoinExchange::_validateDate(std::string const & date) const
 * @brief Verifies the YYYY-MM-DD format and valid calendar dates.
 * @details Checks strict structural requirements (hyphen positions, all 
 * digits) before mathematically confirming month bounds, day bounds, 30-day 
 * months, and February leap year rules.
 * @param date The date string to validate.
 * @throws     InvalidDateException if formatting or bounds are violated.
 */
void BitcoinExchange::_validateDate(std::string const & date) const
{
    if (date.empty() || date.length() != _dateLength)
        throw InvalidDateException();

    for (int i = 0; i < _dateLength; ++i)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                throw InvalidDateException();
        }
        else
        {
            if (!std::isdigit(static_cast<unsigned char>(date[i])))
                throw InvalidDateException();
        }
    }

    std::istringstream iss(date);
    int year, month, day;
    char dash;
    iss >> year >> dash >> month >> dash >> day;

    if (month > 12 || month < 1 || day > 31 || day < 1)
        throw InvalidDateException();

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw InvalidDateException();

    if (month == 2 && ((_isLeapYear(year) && day > 29) || (!_isLeapYear(year) && day > 28)))
        throw InvalidDateException();
}

/**
 * @fn double BitcoinExchange::_validateValue(std::string const & valueStr) const
 * @brief Extracts and strictly validates a floating point value.
 * @details Uses an input string stream to trap trailing garbage characters 
 * by asserting the eofbit alongside the failbit.
 * @param valueStr The string containing the numeric data.
 * @return         The successfully parsed double value.
 * @throws         InvalidValueException if extraction fails or garbage trails.
 * @throws         NegativeValueException if the value is less than 0.
 */
double BitcoinExchange::_validateValue(std::string const & valueStr) const
{
    if (valueStr.empty())
        throw InvalidValueException();

    std::istringstream iss(valueStr);
    double value;
    iss >> value;

    if (iss.fail() || !iss.eof())
        throw InvalidValueException();

    if (value < 0)
        throw NegativeValueException();

    return value;
}

/**
 * @fn void BitcoinExchange::_loadDatabase(void)
 * @brief Parses the data.csv file to populate the historical exchange rates.
 * @details Triggers hard program failures upon encountering any missing data, 
 * corrupt values, or bad headers in the database, ensuring perfect data 
 * integrity before user input is processed.
 * @throws FileOpenException, EmptyFileException, EmptyDatabaseException, or 
 * Exception (if bad stream state) if the database cannot be reliably loaded.
 */
void BitcoinExchange::_loadDatabase(void)
{
    std::ifstream infile(_DB_FILENAME);
    if (!infile.is_open())
        throw FileOpenException();

    if (infile.peek() == std::ifstream::traits_type::eof())
        throw EmptyFileException();

    _validateHeader(infile, "date", "exchange_rate", ',');

    std::string line;
    std::istringstream iss;

    while (std::getline(infile, line))
    {
        if (_trimWhitespaces(line).empty())
            continue;

        iss.clear();
        iss.str(line);
    
        std::string date;
        if (!std::getline(iss, date, ','))
            throw ParserTokenException();
        date = _trimWhitespaces(date);
        _validateDate(date);

        std::string valueStr;
        if (!std::getline(iss, valueStr))
            throw ParserTokenException();
        valueStr = _trimWhitespaces(valueStr);
        double value = _validateValue(valueStr);

        _database[date] = value;
    }

    if (infile.bad())
        throw Exception();

    if(_database.empty())
        throw EmptyDatabaseException();

    infile.close();
}

/**
 * @fn void BitcoinExchange::_calculator(std::string const & date, double value)
 * @brief Resolves the historical rate and prints the final calculation.
 * @details Utilizes std::map::lower_bound to achieve an O(log N) search for 
 * the closest prior date in the database if an exact match does not exist.
 * @param date  The strictly validated date string.
 * @param value The validated Bitcoin amount from the input file.
 */
void BitcoinExchange::_calculator(std::string const & date, double value)
{
    std::map<std::string, double>::iterator it = _database.lower_bound(date);

    if (it == _database.begin() && it->first != date)
    {
        std::cerr << "Error: date is prior to database inception." << std::endl;
        return;
    }

    if (it == _database.end() || it->first != date)
        --it;

    std::cout << date << " => " << value << " = " << it->second * value << std::endl;
}

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn BitcoinExchange::BitcoinExchange(void)
 * @brief Default constructor for BitcoinExchange.
 * @details Automatically triggers the database loading mechanism. Will abort 
 * the program initialization if the database is missing or corrupted.
 */
BitcoinExchange::BitcoinExchange(void)
{
    _loadDatabase();
}

/**
 * @fn BitcoinExchange::BitcoinExchange(BitcoinExchange const & other)
 * @brief Copy constructor for BitcoinExchange.
 * @details Performs a deep copy of the historical database map.
 * @param other The BitcoinExchange instance to copy.
 */
BitcoinExchange::BitcoinExchange(BitcoinExchange const & other)
{
    _database = other._database;
}

/**
 * @fn BitcoinExchange::~BitcoinExchange(void)
 * @brief Destructor for BitcoinExchange.
 * @details Safely destroys the object. STL map memory is auto-managed.
 */
BitcoinExchange::~BitcoinExchange(void) {}

/* ========================================================================== */
/* OPERATOR OVERLOADS                                                         */
/* ========================================================================== */

/**
 * @fn BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & other)
 * @brief Copy assignment operator overload.
 * @details Safely replaces the internal database map with the one from 
 * 'other', guarding against self-assignment.
 * @param other The BitcoinExchange object to assign from.
 * @return      A reference to the active object.
 */
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void BitcoinExchange::processInput(std::string const & filename)
 * @brief Parses the user-provided file and calculates exchange values.
 * @details Executes a "soft-fail" loop where bad dates or invalid lines print 
 * custom errors to stderr and continue execution, rather than crashing the 
 * program. Catches custom polymorphic exceptions to fulfill subject output 
 * requirements.
 * @param filename The path to the user's input text file.
 * @throws         FileOpenException, EmptyFileException, or Exception on fatal 
 * I/O failure.
 */
void BitcoinExchange::processInput(std::string const & filename)
{
    std::string trimmedFilename = _trimWhitespaces(filename);

    if (trimmedFilename.empty())
        throw EmptyFileException();

    std::ifstream infile(trimmedFilename.c_str());
    if (!infile.is_open())
        throw FileOpenException();

    if (infile.peek() == std::ifstream::traits_type::eof())
        throw EmptyFileException();

    _validateHeader(infile, "date", "value", '|');

    std::string line;
    std::istringstream iss;

    while (std::getline(infile, line))
    {
        if (_trimWhitespaces(line).empty())
            continue;

        iss.clear();
        iss.str(line);
    
        std::string date;
        if (!std::getline(iss, date, '|'))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string valueStr;
        if (!std::getline(iss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = _trimWhitespaces(date);
        valueStr = _trimWhitespaces(valueStr);
        double value;

        try
        {
            _validateDate(date);
            value = _validateValue(valueStr);

            if (value > 1000)
                throw TooLargeValueException();
        }
        catch(InvalidDateException const & e)
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        catch(InvalidValueException const & e)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        catch (Exception const & e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            continue;
        }

        _calculator(date, value);
    } 

    if (infile.bad())
        throw Exception();

    infile.close();
}

/* ========================================================================== */
/* EXCEPTIONS                                                                 */
/* ========================================================================== */

/**
 * @fn const char* BitcoinExchange::Exception::what() const throw()
 * @brief Returns the generic error message.
 * @details Overrides std::exception::what() to provide a statically allocated 
 * error message acting as a generic fallback for polymorphic exception 
 * handling.
 * @return A C-style character string describing the error.
 */
const char* BitcoinExchange::Exception::what() const throw()
{
    return ("encountered a generic error.");
}

/**
 * @fn const char* BitcoinExchange::FileOpenException::what() const throw()
 * @brief Returns the specific error message for file open failures.
 * @details Inherits from Exception to provide a specific, statically allocated 
 * string indicating an inaccessible file stream.
 * @return A C-style character string describing the error.
 */
const char* BitcoinExchange::FileOpenException::what() const throw()
{
    return ("could not open file.");
}

/**
 * @fn const char* BitcoinExchange::EmptyFileException::what() const throw()
 * @brief Returns the specific error message for empty files.
 * @details Inherits from Exception to provide a specific, statically allocated 
 * string indicating an empty or whitespace-only file.
 * @return A C-style character string describing the error.
 */
const char* BitcoinExchange::EmptyFileException::what() const throw()
{
    return ("file is empty.");
}

/**
 * @fn const char* BitcoinExchange::EmptyDatabaseException::what() const throw()
 * @brief Returns the specific error message for empty database maps.
 * @details Inherits from Exception to provide a specific, statically allocated 
 * string indicating a missing or completely invalid internal database dataset.
 * @return A C-style character string describing the error.
 */
const char* BitcoinExchange::EmptyDatabaseException::what() const throw()
{
    return ("database is empty.");
}

/**
 * @fn const char* BitcoinExchange::ParserTokenException::what() const throw()
 * @brief Returns the specific error message for missing tokens.
 * @details Inherits from Exception to provide a specific, statically allocated 
 * string indicating a failure to split strings by their expected delimiter.
 * @return A C-style character string describing the error.
 */
const char* BitcoinExchange::ParserTokenException::what() const throw()
{
    return ("invalid/missing token.");
}

/**
 * @fn const char* BitcoinExchange::InvalidHeaderException::what() const throw()
 * @brief Returns the specific error message for malformed headers.
 * @details Inherits from Exception to provide a specific, statically allocated 
 * string indicating a failure to match exact column names in the first row.
 * @return A C-style character string describing the error.
 */
const char* BitcoinExchange::InvalidHeaderException::what() const throw()
{
    return ("invalid header.");
}

/**
 * @fn const char* BitcoinExchange::InvalidDateException::what() const throw()
 * @brief Returns the generic error message for invalid dates.
 * @details Not primarily used by processInput (which relies on local variables 
 * to print custom messages), but acts as a robust fallback for database 
 * failures.
 * @return A C-style character string describing the error.
 */
const char* BitcoinExchange::InvalidDateException::what() const throw()
{
    return ("invalid date format.");
}

/**
 * @fn const char* BitcoinExchange::InvalidValueException::what() const throw()
 * @brief Returns the generic error message for invalid values.
 * @details Like InvalidDateException, acts as a fallback for database fatal 
 * failures instead of relying on dynamically generated text.
 * @return A C-style character string describing the error.
 */
const char* BitcoinExchange::InvalidValueException::what() const throw()
{
    return ("invalid value format.");
}

/**
 * @fn const char* BitcoinExchange::NegativeValueException::what() const throw()
 * @brief Returns the specific error message matching the subject requirements.
 * @details Provides the exact required subject string to be seamlessly printed 
 * in the polymorphic soft-fail loop inside processInput().
 * @return A C-style character string describing the error.
 */
const char* BitcoinExchange::NegativeValueException::what() const throw()
{
    return ("not a positive number.");
}

/**
 * @fn const char* BitcoinExchange::TooLargeValueException::what() const throw()
 * @brief Returns the specific error message matching the subject requirements.
 * @details Provides the exact required subject string to be seamlessly printed 
 * in the polymorphic soft-fail loop inside processInput().
 * @return A C-style character string describing the error.
 */
const char* BitcoinExchange::TooLargeValueException::what() const throw()
{
    return ("too large a number.");
}
