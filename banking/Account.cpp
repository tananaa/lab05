#include "Account.hpp"
#include <stdexcept>

Account::Account(const std::string& num) : number(num), balance(0.0) {}

void Account::deposit(double amount) {
    if (amount <= 0) throw std::invalid_argument("Amount must be positive");
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= 0) throw std::invalid_argument("Amount must be positive");
    if (amount > balance) throw std::runtime_error("Insufficient funds");
    balance -= amount;
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getNumber() const {
    return number;
}
