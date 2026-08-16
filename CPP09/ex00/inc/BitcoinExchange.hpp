/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 03:40:24 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/19 03:32:18 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <exception>
#include <fstream>
#include <map>
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class BitcoinExchange
 * @brief Evaluates the value of a certain amount of bitcoin on a specific date.
 * @details Reads a historical exchange rate database in CSV format and 
 * calculates the corresponding value for a given date and amount provided 
 * in a separate input file. Enforces strict parsing and formatting rules.
 */
class BitcoinExchange
{
    private:
        /* ------------------------------------------------------------------ */
        /* CONSTANTS & SETTINGS                                               */
        /* ------------------------------------------------------------------ */
        static const char* _DB_FILENAME;
        static const int   _dateLength = 10;

        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        std::map<std::string, double> _database;

        /* ------------------------------------------------------------------ */
        /* PRIVATE METHODS                                                    */
        /* ------------------------------------------------------------------ */
        std::string _trimWhitespaces(std::string const & str);
        void        _validateHeader(std::ifstream& file, std::string const & leftExp, std::string const & rightExp, char delim);
        void        _loadDatabase(void);
        bool        _isLeapYear(int year) const;
        void        _validateDate(std::string const & date) const;
        double      _validateValue(std::string const & value) const;
        void        _calculator(std::string const & date, double value);

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const & other);
        ~BitcoinExchange(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        BitcoinExchange& operator=(BitcoinExchange const & other);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void processInput(std::string const & filename);

    /* ====================================================================== */
    /* EXCEPTIONS                                                             */
    /* ====================================================================== */

    /**
     * @class Exception
     * @brief Generic exception for the BitcoinExchange class.
     * @details Inherits from std::exception. Serves as the base class for all 
     * specific parsing and validation exceptions, allowing polymorphic catching.
     */
    class Exception : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class FileOpenException
     * @brief Exception thrown when a file stream fails to open.
     * @details Triggered when std::ifstream fails to access the provided file 
     * path, either for the internal database or the user input file.
     */
    class FileOpenException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class EmptyFileException
     * @brief Exception thrown when a file is entirely empty or only whitespace.
     * @details Triggered when std::ifstream::peek detects EOF immediately upon 
     * opening, or if the file contains exclusively whitespace characters.
     */
    class EmptyFileException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class EmptyDatabaseException
     * @brief Exception thrown when the database has a header but no valid data.
     * @details Triggered at the end of database initialization if the parser 
     * successfully passed the header but found no valid rows to populate the 
     * map.
     */
    class EmptyDatabaseException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class ParserTokenException
     * @brief Exception thrown when a required delimiter or token is missing.
     * @details Triggered when strict splitting by a required delimiter 
     * (e.g. ',' or '|') fails to extract the expected right-hand or 
     * left-hand tokens.
     */
    class ParserTokenException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class InvalidHeaderException
     * @brief Exception thrown when a file's header row is malformed or 
     * incorrect.
     * @details Triggered when a file's first non-empty line fails to match the 
     * required exact column names or expected delimiter.
     */
    class InvalidHeaderException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class InvalidDateException
     * @brief Exception thrown when a date fails calendar or format validation.
     * @details Triggered by the internal date validator if string lengths, 
     * structural hyphens, or numerical calendar rules (leap years, month 
     * bounds) are violated.
     */
    class InvalidDateException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class InvalidValueException
     * @brief Exception thrown when a value string contains garbage or text.
     * @details Triggered by the internal value validator if string-to-double 
     * extraction fails or leaves trailing garbage characters in the buffer.
     */
    class InvalidValueException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class NegativeValueException
     * @brief Exception thrown when a parsed numeric value is strictly less 
     * than 0.
     * @details Triggered to fulfill the subject's requirement that values 
     * cannot be negative numbers. Utilized in both database and input file 
     * parsing.
     */
    class NegativeValueException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };

    /**
     * @class TooLargeValueException
     * @brief Exception thrown when a parsed value exceeds the maximum limit 
     * (1000).
     * @details Triggered exclusively for the user input file to enforce the 
     * maximum value limit required by the subject specifications.
     */
    class TooLargeValueException : public Exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif
