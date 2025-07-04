#include "BankAccount.hpp"

// ───── Constructor ────────────────────────────────────────────────
BankAccount::BankAccount(double initialBalance, double annualInterestRate) 
    : balance_(initialBalance), 
      annualInterestRate_(annualInterestRate) 
{}

// ───── Public methods ─────────────────────────────────────────────
double BankAccount::get_balance() const {
    return balance_;
}

void BankAccount::deposit(double amount) {
    balance_ += amount;
}

bool BankAccount::withdraw(double amount) {
    if (amount > balance_) {
        return false;
    } else {
        balance_ -= amount;
        return true;
    }
}

void BankAccount::apply_interest(int years) {
    for (int i = 0; i < years; ++i) {
        apply_one_year_interest();
    }
}

// ───── Private methods ─────────────────────────────────────────────
void BankAccount::apply_one_year_interest() {
    balance_ += balance_ * annualInterestRate_;
}