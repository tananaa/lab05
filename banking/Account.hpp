#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account {
private:
    std::string number;
    double balance;

public:
    Account(const std::string& num);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    std::string getNumber() const;
};

#endif
