#include "./Account/Account.hpp"
#include "./SavingsAccount/SavingsAccount.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace BankingSystem;

int main() {
    // vector de conturi, de tipul Account
    std::vector<Account<double>> accounts;
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

        Account <double> account(accountNumber, initialBalance);

        accounts.push_back(std::move(account));
    }

    // Simulation of initial transactions
    for (Account<double> &account : accounts) {
        double amount;
        std::cout << "Enter the deposit amount for " << account.getAccountNumber() << ": $";
        std::cin >> amount;
        account.deposit(amount);
        account.addTransaction("Deposit", amount);

        std::cout << "Enter the withdrawal amount for " << account.getAccountNumber() << ": $";
        std::cin >> amount;
        account.withdraw(amount);
        account.addTransaction("Withdrawal", amount);
    }

    // Display account information and transactions
    std::cout << "\nAccount Information:" << std::endl;
    for (Account<double> & account : accounts) {
        account.displayAccountInfo();
        account.displayTransactions();
    }

    // Copy Constructor si assignment operator
    if (accounts.size() >= 2) {
        std::cout << "\nCopying an existing account - Deep Copy:" << std::endl;
        Account<double> copiedAccount1(accounts[0]); 
        copiedAccount1.displayAccountInfo();
        
        double depositAmount1;
        std::cout << "\nEnter the deposit amount for the copied account: $";
        std::cin >> depositAmount1;
        copiedAccount1.deposit(depositAmount1);
        
        std::cout << "\nOriginal Account Information:" << std::endl;
        accounts[0].displayAccountInfo();
        
        std::cout << "\nCopying an existing account - Shallow Copy:" << std::endl;
        Account<double> copiedAccount2 = accounts[1];
        copiedAccount2.displayAccountInfo();
        
        double depositAmount2;
        std::cout << "\nEnter the deposit amount for the copied account: $";
        std::cin >> depositAmount2;
        copiedAccount2.deposit(depositAmount2);
        
        std::cout << "\nOriginal Account Information:" << std::endl;
        accounts[1].displayAccountInfo();
    }

    if (accounts.size() >= 1) {
        std::cout << "\nSavings Account - Adding Interest:" << std::endl;
        SavingsAccount savingsAccount("S123", 1000.0, 5.0); 
        savingsAccount.displayAccountInfo();
        savingsAccount.addInterest();
        std::cout << "Account Type: " << savingsAccount.getAccountType() << std::endl;
        savingsAccount.displayAccountInfo();
    }

    return 0;
}
