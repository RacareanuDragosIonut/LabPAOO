#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <string>
#include <iostream>
#include <memory>
#include <vector>
namespace BankingSystem {


    template <typename T>
    class AccountBase {
    public:
        virtual ~AccountBase() = default;
        virtual void deposit(T amount) = 0;
        virtual void withdraw(T amount) = 0;
        virtual void displayAccountInfo() const = 0;
        virtual std::string getAccountNumber() = 0;
    };
   template <typename T>
    class Transaction {
    public:
        Transaction(const std::string& description, T amount);
        void displayTransaction() const;

    private:
        std::string description;
        T amount;
    };

    template <typename T>
    Transaction<T>::Transaction(const std::string& description, T amount)
        : description(description), amount(amount) {}

    template <typename T>
    void Transaction<T>::displayTransaction() const {
        std::cout << "Description: " << description << ", Amount: $" << amount << std::endl;
    }
    template <typename T>
    class Account : public AccountBase<T> {
    public:
        Account(const std::string& accountNumber, T balance);
        Account(const Account& other);  // Copy constructor
        Account(Account&& other) noexcept; // Move constructor
        Account& operator=(Account&& other) noexcept;  // Move assignment operator
        Account& operator=(const Account& other);
        // override virtual functions
        void deposit(T amount) override;
        void withdraw(T amount) override;
        void displayAccountInfo() const override;
        std::string getAccountNumber() override;
        T getBalance() const;
        void setBalance(T newBalance);
        ~Account();
        void addTransaction(const std::string& description, T amount);
        void displayTransactions() const;
    private:
        std::string accountNumber;
        std::unique_ptr<T> balance;
        std::shared_ptr<std::vector<Transaction<T>>> transactions;
    };
    
// Constructor
template <typename T>
Account<T>::Account(const std::string& accountNumber, T balance)
    : accountNumber(accountNumber), balance(std::make_unique<T>(balance)) {}

// Copy Constructor
template <typename T>
Account<T>::Account(const Account& other)
    : accountNumber(other.accountNumber), balance(std::make_unique<T>(*other.balance)) {}

// Move Constructor
template <typename T>
Account<T>::Account(Account&& other) noexcept
    : accountNumber(std::move(other.accountNumber)), balance(std::move(other.balance)), transactions(std::move(other.transactions)) {
        std::cout<<"move constructor";
        other.balance = nullptr;
        other.transactions = std::make_shared<std::vector<Transaction<T>>>();
    }

// Copy Assignment Operator
template <typename T>
Account<T>& Account<T>::operator=(const Account& other) {
    if (this == &other) {
        return *this;
    }

    accountNumber = other.accountNumber;
    balance = std::make_unique<T>(*other.balance);

    return *this;
}
// Destructor
template <typename T>
Account<T>::~Account() {
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
template <typename T>
void Account<T>::deposit(T amount) {
    *balance += amount;
}

// functie publica pentru a retrage din cont
template <typename T>
void Account<T>::withdraw(T amount) {
    if (*balance >= amount) {
        *balance -= amount;
    } else {
        std::cout << "Insufficient funds." << std::endl;
    }
}

//functie publica pentru a afisa informatiile contului
template <typename T>
void Account<T>::displayAccountInfo() const {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Balance: $" << *balance << std::endl;
}
// functie publica pentru a extrage numarul contului
template <typename T>
std::string Account<T>::getAccountNumber(){
        return accountNumber;
}

template <typename T>
T Account<T>::getBalance() const {
    return *balance;
}

template <typename T>
void Account<T>::setBalance(T newBalance) {
    *balance = newBalance;
}
template <typename T>
    void Account<T>::addTransaction(const std::string& description, T amount) {
        transactions->emplace_back(description, amount);
    }

template <typename T>
    void Account<T>::displayTransactions() const {
        std::cout << "Transaction History:" << std::endl;
        for (const auto& transaction : *transactions) {
            transaction.displayTransaction();
        }
    }

}

    

#endif
