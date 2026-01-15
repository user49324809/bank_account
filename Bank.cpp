#include "Bank.h"
#include <iostream>

void Bank::addAccount(const std::shared_ptr<Account>& account) {
    accounts.push_back(account);
}

void Bank::showAccounts() const {
    for(const auto& acc : accounts)
        acc->display();
}

void Bank::depositToAccount(int index, double amount) {
    if(index >= 0 && index < accounts.size())
        accounts[index]->deposit(amount);
}

void Bank::withdrawFromAccount(int index, double amount) {
    if(index >= 0 && index < accounts.size())
        accounts[index]->withdraw(amount);
}

std::shared_ptr<Account> Bank::getAccount(int index) {
    if(index >= 0 && index < accounts.size())
        return accounts[index];
    return nullptr;
}