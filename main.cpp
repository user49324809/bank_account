#include "Bank.h"
#include <iostream>

int main() {
    Bank bank;
bank.addAccount(std::make_shared<CheckingAccount>("CHK-1001", 500.0));
    bank.addAccount(std::make_shared<SavingsAccount>("SAV-2001", 1000.0, 0.05));

    std::cout << "All accounts:\n";
    bank.showAccounts();

    std::cout << "\nDepositing $200 to checking account...\n";
    bank.depositToAccount(0, 200);

    std::cout << "Withdrawing $150 from savings account...\n";
    bank.withdrawFromAccount(1, 150);

    std::cout << "\nUpdated accounts:\n";
    bank.showAccounts();

    std::cout << "\nAdding interest to savings account...\n";
    std::dynamic_pointer_cast<SavingsAccount>(bank.getAccount(1))->addInterest();

    bank.showAccounts();

    return 0;
}