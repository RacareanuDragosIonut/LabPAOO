#include "Account.hpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Lista de conturi, de tipul Account
    std::vector<Account> accounts;

    int numAccounts;
    std::cout << "Enter the number of accounts to create: ";
    std::cin >> numAccounts;

    // Initializarea conturilor
    for (int i = 0; i < numAccounts; i++) {
        std::string accountNumber;
        double initialBalance;

        std::cout << "Enter Account Number for Account " << i + 1 << ": ";
        std::cin >> accountNumber;

        std::cout << "Enter Initial Balance for Account " << i + 1 << ": $";
        std::cin >> initialBalance;

        Account account(accountNumber, initialBalance);
        accounts.push_back(account);
    }

    // Simularea initiala a unor tranzactii
    for (Account& account : accounts) {
        double amount;
        std::cout << "Enter the deposit amount for " << account.getAccountNumber() << ": $";
        std::cin >> amount;
        account.deposit(amount);

        std::cout << "Enter the withdrawal amount for " << account.getAccountNumber() << ": $";
        std::cin >> amount;
        account.withdraw(amount);
    }

    // Afisarea informatiilor despre cont
    std::cout << "\nAccount Information:" << std::endl;
    for (const Account& account : accounts) {
        account.displayAccountInfo();
    }

    // Copy Constructor si assignment operator
    if (accounts.size() >= 2) {
        std::cout << "\nCopying an existing account - Deep Copy:" << std::endl;
        Account copiedAccount1(accounts[0]); 
        // Folosesc copy constructor pentru a crea un deep copy
        copiedAccount1.displayAccountInfo();
        //afisam initial informatiile contului - deep copy

        double depositAmount1;
        std::cout << "\nEnter the deposit amount for the copied account: $";
        std::cin >> depositAmount1;
        copiedAccount1.deposit(depositAmount1);
        // depozitam in cont
        std::cout << "\nOriginal Account Information:" << std::endl;
        accounts[0].displayAccountInfo();
        //verificam pentru obiectul din care s-a copiat si observam ca
        //schimbarile in membrul balance nu au impactat obiectul din care s-a copiat
        std::cout << "\nCopying an existing account - Shallow Copy:" << std::endl;
        Account copiedAccount2("113", 25);
        copiedAccount2 = accounts[1]; 
        // Folosim assignment operator pentru shallow copy
        copiedAccount2.displayAccountInfo();
        // afisam initial informatiile contului-shallow copy
        double depositAmount2;
        std::cout << "\nEnter the deposit amount for the copied account: $";
        std::cin >> depositAmount2;
        copiedAccount2.deposit(depositAmount2);
        //depozitam in cont
        std::cout << "\nOriginal Account Information:" << std::endl;
        accounts[1].displayAccountInfo();
        //verificam pentru obiectul din care s-a copiat si observam ca
        //schimbarile in membrul balance au impactat obiectul din care s-a copiat
    }
    return 0;
}
