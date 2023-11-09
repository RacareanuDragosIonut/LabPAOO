// Account.cpp
#include "Account.hpp"
#include <iostream>
#include <memory>
namespace BankingSystem{
// Constructor
Account::Account(const std::string& accountNumber, double balance)
    : accountNumber(accountNumber), balance(std::make_unique<double>(balance)) {}

// Copy Constructor
Account::Account(const Account& other)
    : accountNumber(other.accountNumber), balance(std::make_unique<double>(*other.balance)) {}

// Move Constructor
Account::Account(Account&& other) noexcept
    : accountNumber(std::move(other.accountNumber)), balance(std::move(other.balance)) {
        std::cout<<"move constructor";
    }

// Move Assignment Operator
Account& Account::operator=(Account&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    accountNumber = std::move(other.accountNumber);
    balance = std::move(other.balance);

    return *this;
}
// Copy Assignment Operator
Account& Account::operator=(const Account& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    accountNumber = other.accountNumber;
    balance = std::make_unique<double>(*other.balance);

    return *this;
}
// Destructor
Account::~Account() {
    /*(*referenceCount)--;
    // se decrementeaza referenceCount in destructor
    if (*referenceCount == 0 && shouldDelete) {
        delete balance;
        balance = nullptr;
        delete referenceCount;
        referenceCount = nullptr;
    }
    */
    //apoi doar daca devine 0 referenceCount se dealoca din memorie referenceCount si balance
    // trebuie sa se evite dealocarea in alta situatie
    // pentru a evita double free error
}

// functie publica pentru a depozita in cont
void Account::deposit(double amount) {
    *balance += amount;
}

// functie publica pentru a retrage din cont
void Account::withdraw(double amount) {
    if (*balance >= amount) {
        *balance -= amount;
    } else {
        std::cout << "Insufficient funds." << std::endl;
    }
}

//functie publica pentru a afisa informatiile contului
void Account::displayAccountInfo() const {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Balance: $" << *balance << std::endl;
}
// functie publica pentru a extrage numarul contului
std::string Account::getAccountNumber(){
        return accountNumber;
}

double Account::getBalance() const {
    return *balance;
}

void Account::setBalance(double newBalance) {
    *balance = newBalance;
}
// SavingsAccount methods
SavingsAccount::SavingsAccount(const std::string& accountNumber, double balance, double interestRate)
    : Account(accountNumber, balance), interestRate(interestRate), accountType("Savings Account") {
}

void SavingsAccount::addInterest() {
    double currentBalance = getBalance();
    currentBalance += currentBalance * (interestRate / 100.0);
    //*balance = currentBalance;
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
