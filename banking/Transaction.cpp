#include "Transaction.hpp"
#include <stdexcept>

Transaction::Transaction(Account* fromAcc, Account* toAcc, double amt)
    : from(fromAcc), to(toAcc), amount(amt), completed(false) {}

void Transaction::execute() {
    if (completed) throw std::runtime_error("Transaction already executed");
    if (amount <= 0) throw std::invalid_argument("Amount must be positive");
    
    from->withdraw(amount);
    to->deposit(amount);
    completed = true;
}

void Transaction::rollback() {
    if (!completed) throw std::runtime_error("Transaction not executed yet");
    
    from->deposit(amount);
    to->withdraw(amount);
    completed = false;
}

bool Transaction::isCompleted() const {
    return completed;
}
