// Account.hpp
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <string>
class Account {
public:
    // Constructor
    Account(const std::string& accountNumber, double balance);

    // Copy Constructor
    Account(const Account& other);

    // Assignment Operator
    Account& operator=(const Account& other);

    // Destructor
    ~Account();

    // functii membrii publici
    void deposit(double amount);
    void withdraw(double amount);
    void displayAccountInfo() const;
    std::string getAccountNumber();

private:
    //membrii privati
    std::string accountNumber; // numarul contului
    double* balance; // Pointer la balance care va fi alocat dinamic
    int* referenceCount; // Reference count pentru memorie share-uita
    bool shouldDelete;   // Flag to determine if memory should be deleted
};

#endif
