#pragma once
#include <string>
#include <iostream>

class Account {
protected:
    std::string accountNumber;  
    double balance;
public:
    Account(const std::string& accNum, double bal);
    virtual void deposit(double amount);
    virtual void withdraw(double amount) = 0;  
    virtual void display() const = 0;          
    virtual ~Account() = default;
};

// Наследник: CheckingAccount
class CheckingAccount : public Account {
public:
    CheckingAccount(const std::string& accNum, double bal);
    void withdraw(double amount) override;
    void display() const override;
};

// Наследник: SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(const std::string& accNum, double bal, double rate);
    void withdraw(double amount) override;
    void addInterest();
    void display() const override;
};