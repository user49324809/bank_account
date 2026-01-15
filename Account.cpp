#include "Account.h"
#include <iomanip>

// Account
Account::Account(const std::string& accNum, double bal) : accountNumber(accNum), balance(bal) {}
void Account::deposit(double amount) {
    if(amount > 0) balance += amount;
}

// CheckingAccount
CheckingAccount::CheckingAccount(const std::string& accNum, double bal) : Account(accNum, bal) {}
void CheckingAccount::withdraw(double amount) {
    if(amount <= balance) balance -= amount;
    else std::cout << "Insufficient funds in checking account.\n";
}
void CheckingAccount::display() const {
    std::cout << "Checking Account: " << accountNumber
              << ", Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
}

// SavingsAccount
SavingsAccount::SavingsAccount(const std::string& accNum, double bal, double rate) 
    : Account(accNum, bal), interestRate(rate) {}

void SavingsAccount::withdraw(double amount) {
    if(amount <= balance) balance -= amount;
    else std::cout << "Insufficient funds in savings account.\n";
}

void SavingsAccount::addInterest() {
    balance += balance * interestRate;
}

void SavingsAccount::display() const {
    std::cout << "Savings Account: " << accountNumber
              << ", Balance: $" << std::fixed << std::setprecision(2) << balance
              << ", Interest rate: " << interestRate*100 << "%\n";
}