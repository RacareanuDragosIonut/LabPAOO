#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <string>
#include <iostream>
#include <memory>
namespace BankingSystem {
    class AccountBase {
    public:
        virtual ~AccountBase() = default;
        virtual void deposit(double amount) = 0;
        virtual void withdraw(double amount) = 0;
        virtual void displayAccountInfo() const = 0;
        virtual std::string getAccountNumber() = 0;
    };

    class Account : public AccountBase {
    public:
        Account(const std::string& accountNumber, double balance);
        Account(const Account& other);  // Copy constructor
        Account(Account&& other) noexcept; // Move constructor
        Account& operator=(Account&& other) noexcept;  // Move assignment operator
        Account& operator=(const Account& other);
        // override virtual functions
        void deposit(double amount) override;
        void withdraw(double amount) override;
        void displayAccountInfo() const override;
        std::string getAccountNumber() override;
        double getBalance() const;
        void setBalance(double newBalance);
        ~Account();
    private:
        std::string accountNumber;
        std::unique_ptr<double> balance;
    };

    class SavingsAccount : public Account {
    public:
        SavingsAccount(const std::string& accountNumber, double balance, double interestRate);
        void addInterest(); 
        std::string getAccountType() const;
        void displayAccountInfo() const override;

    private:
        double interestRate;
        std::string accountType;
    };
}

#endif
