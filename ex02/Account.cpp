#include "Account.hpp"
#include <iostream>

// Static members initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;
}

// Destructor
Account::~Account() {
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
    _nbAccounts--;
}

// Static methods
int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
    std::cout << "Accounts: " << _nbAccounts << std::endl;
    std::cout << "Total: " << _totalAmount << std::endl;
    std::cout << "Deposits: " << _totalNbDeposits << std::endl;
    std::cout << "Withdrawals: " << _totalNbWithdrawals << std::endl;
}

// Private method
void Account::_displayTimestamp() {
    // Implementation of displaying timestamp, if needed
}

// Non-static methods
void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal <= _amount) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        return true;
    } else {
        return false; // Insufficient funds
    }
}

int Account::checkAmount() const {
    return _amount;
}

void Account::displayStatus() const {
    std::cout << "Account Index: " << _accountIndex << std::endl;
    std::cout << "Amount: " << _amount << std::endl;
    std::cout << "Deposits: " << _nbDeposits << std::endl;
    std::cout << "Withdrawals: " << _nbWithdrawals << std::endl;
}

struct DisplayStatusFunctor {
    void operator()(Account& acc) const {
        acc.displayStatus();
    }
};