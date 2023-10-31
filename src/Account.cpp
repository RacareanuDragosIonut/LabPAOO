// Account.cpp
#include "Account.hpp"
#include <iostream>
// ReferenceCount si shouldDelete sunt pentru a dealocarea din 
//memorie a membrului privat balance
// Constructor
Account::Account(const std::string& accountNumber, double balance) : accountNumber(accountNumber) {
    this->balance = new double(balance);
    referenceCount = new int(1); // in constructor referenceCount se initializeaza cu 1
    shouldDelete = true; // Set the flag to true (delete memory when the object is destroyed)
}

// Copy Constructor
Account::Account(const Account& other) : accountNumber(other.accountNumber) {
    this->balance = new double(*(other.balance));
    this->referenceCount = other.referenceCount;
    (*referenceCount)++; 
    //Cand se creeaza un deep copy al obiectului, se incrementeaza count-ul de referinte
    this->shouldDelete = other.shouldDelete;
}

// Assignment Operator
Account& Account::operator=(const Account& other) {
    if (this == &other) {
        return *this;  // se verifica daca nu cumva este acelasi obiect
    }

    accountNumber = other.accountNumber;
     (*referenceCount)--;
    // se decrementeaza referenceCount si daca devine 0 se dealoca si balance si referenceCount
    if (*referenceCount == 0 && shouldDelete) {
        delete balance;
        balance = nullptr;
        delete referenceCount;
        referenceCount = nullptr;
    }
    balance = other.balance;
    referenceCount = other.referenceCount;
    shouldDelete = other.shouldDelete;
    
    // apoi se incrementeaza pentru ca este shallow copy
    (*referenceCount)++;
    return *this;
}

// Destructor
Account::~Account() {
    (*referenceCount)--;
    // se decrementeaza referenceCount in destructor
    if (*referenceCount == 0 && shouldDelete) {
        delete balance;
        balance = nullptr;
        delete referenceCount;
        referenceCount = nullptr;
    }
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
