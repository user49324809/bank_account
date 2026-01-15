#pragma once
#include "Account.h"
#include <vector>
#include <memory>

class Bank {
private:
    std::vector<std::shared_ptr<Account>> accounts;
public:
    void addAccount(const std::shared_ptr<Account>& account);
    void showAccounts() const;
    void depositToAccount(int index, double amount);
    void withdrawFromAccount(int index, double amount);
    std::shared_ptr<Account> getAccount(int index);
};