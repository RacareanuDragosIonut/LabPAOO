#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP
#include "../Account/Account.hpp"
#include <string>
#include <iostream>
#include <memory>
namespace BankingSystem{
    class SavingsAccount : public Account<double> {
    public:
        SavingsAccount(const std::string& accountNumber, double balance, double interestRate);
        void addInterest(); 
        std::string getAccountType() const;
        void displayAccountInfo() const override;

    private:
        double interestRate;
        std::string accountType;
    };
    SavingsAccount::SavingsAccount(const std::string& accountNumber, double balance, double interestRate)
    : Account<double>(accountNumber, balance), interestRate(interestRate), accountType("Savings Account") {
}

void SavingsAccount::addInterest() {
    double currentBalance = getBalance();
    currentBalance += currentBalance * (interestRate / 100.0);
    setBalance(currentBalance);
}

std::string SavingsAccount::getAccountType() const {
    return accountType;
}

void SavingsAccount::displayAccountInfo() const {
    Account::displayAccountInfo();
    std::cout << "Account Type: " << accountType << std::endl;
}
}
#endif
