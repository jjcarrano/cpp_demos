#pragma once

namespace basic_class{
    class BankAccount {
    public:
        BankAccount(double initialBalance, double annualInterestRate);
        
        double get_balance() const;

        void deposit(double amount);
        [[nodiscard]] bool withdraw(double amount);
        void apply_interest(int years);

    private:
        double balance_;
        double annualInterestRate_;

        void apply_one_year_interest();
    };
}