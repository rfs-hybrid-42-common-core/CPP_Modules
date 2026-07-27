/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 21:46:33 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 03:17:39 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Account.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <iostream>
#include <ctime>

/* ========================================================================== */
/* STATIC INITIALIZATIONS                                                     */
/* ========================================================================== */

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* ========================================================================== */
/* CONSTRUCTORS & DESTRUCTORS                                                 */
/* ========================================================================== */

/**
 * @fn Account::Account(void)
 * @brief Default constructor for the Account class.
 * @details Initializes an empty account, assigning it an index and setting all 
 * amounts and counters to zero. Updates the global account count and logs the 
 * creation.
 */
Account::Account(void) : _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
    ++_nbAccounts;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount
              << ";created" << std::endl;
}

/**
 * @fn Account::Account(int initial_deposit)
 * @brief Parameterized constructor for the Account class.
 * @details Initializes an account with a starting deposit. Updates global 
 * statistics (account count and total bank amount) and logs the creation.
 * @param initial_deposit The starting amount to be deposited into the account.
 */
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    ++_nbAccounts;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount
              << ";created" << std::endl;
}

/**
 * @fn Account::~Account(void)
 * @brief Destructor for the Account class.
 * @details Simulates the closing of an account. Decrements the global account 
 * count, deducts the remaining account balance from the global bank total, and 
 * logs the closure.
 */
Account::~Account(void)
{
    --_nbAccounts;
    _totalAmount -= checkAmount();

    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << checkAmount()
              << ";closed" << std::endl;
}

/* ========================================================================== */
/* PRIVATE METHODS                                                            */
/* ========================================================================== */

/**
 * @fn void Account::_displayTimestamp(void)
 * @brief Generates and prints the current timestamp.
 * @details Uses the standard C library <ctime> to format the current local 
 * time into the specific "[YYYYMMDD_HHMMSS] " format required by the log file.
 */
void Account::_displayTimestamp(void)
{
    std::time_t rawtime;
    std::tm*    timeinfo;
    const int   bufferSize = 20;
    char        buffer[bufferSize];

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    std::strftime(buffer, bufferSize, "[%Y%m%d_%H%M%S] ", timeinfo);
    std::cout << buffer;
}

/* ========================================================================= */
/* PUBLIC STATIC GETTERS                                                     */
/* ========================================================================= */

/**
 * @fn int Account::getNbAccounts(void)
 * @brief Retrieves the total number of active accounts.
 * @details Provides read-only access to the static global variable 
 * _nbAccounts, representing the total number of active accounts within 
 * the bank.
 * @return The global number of accounts.
 */
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

/**
 * @fn int Account::getTotalAmount(void)
 * @brief Retrieves the total amount of money held across all accounts.
 * @details Provides read-only access to the static global variable 
 * _totalAmount, representing the combined balance of all active accounts 
 * within the bank.
 * @return The global bank total amount.
 */
int Account::getTotalAmount(void)
{
    return _totalAmount;
}

/**
 * @fn int Account::getNbDeposits(void)
 * @brief Retrieves the total number of deposits made across all accounts.
 * @details Provides read-only access to the static global variable 
 * _totalNbDeposits, tracking every deposit transaction processed across 
 * all accounts.
 * @return The global number of deposits.
 */
int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

/**
 * @fn int Account::getNbWithdrawals(void)
 * @brief Retrieves the total number of withdrawals made across all accounts.
 * @details Provides read-only access to the static global variable 
 * _totalNbWithdrawals, tracking every successful withdrawal transaction 
 * processed across all accounts.
 * @return The global number of withdrawals.
 */
int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

/**
 * @fn void Account::displayAccountsInfos(void)
 * @brief Displays the overall status of the global bank.
 * @details Logs the total number of accounts, total amount, total deposits, 
 * and total withdrawals in a formatted string.
 */
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

/* ========================================================================== */
/* PUBLIC METHODS                                                             */
/* ========================================================================== */

/**
 * @fn void Account::makeDeposit(int deposit)
 * @brief Processes a deposit into the account.
 * @details Increases both the individual account balance and the global bank 
 * total. Increments deposit counters and logs the transaction details.
 * @param deposit The amount to be deposited.
 */
void Account::makeDeposit(int deposit)
{
    const int p_amount = checkAmount();

    _amount += deposit;
    _totalAmount += deposit;
    ++_nbDeposits;
    ++_totalNbDeposits;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << p_amount
              << ";deposit:" << deposit
              << ";amount:" << checkAmount()
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

/**
 * @fn bool Account::makeWithdrawal(int withdrawal)
 * @brief Processes a withdrawal request from the account.
 * @details Checks if sufficient funds are available. If refused, logs the 
 * refusal and returns false. If accepted, decreases balances, increments 
 * counters, logs the transaction, and returns true.
 * @param withdrawal The requested withdrawal amount.
 * @return           True if the withdrawal was successful, false if refused 
 * due to insufficient funds.
 */
bool Account::makeWithdrawal(int withdrawal)
{
    const int p_amount = checkAmount();

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << p_amount;

    if (withdrawal > p_amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    ++_nbWithdrawals;
    ++_totalNbWithdrawals;

    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << checkAmount()
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

/**
 * @fn int Account::checkAmount(void) const
 * @brief Retrieves the current balance of the individual account.
 * @details Provides read-only access to the internal _amount attribute, 
 * used primarily for balance validations during withdrawal requests and 
 * for formatting status displays.
 * @return The current account balance.
 */
int Account::checkAmount(void) const
{
    return _amount;
}

/**
 * @fn void Account::displayStatus(void) const
 * @brief Displays the current status of the individual account.
 * @details Logs the account index, current amount, and the number of deposits 
 * and withdrawals made.
 */
void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << checkAmount()
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}
