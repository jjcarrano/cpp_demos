#include "basic_class/core.hpp"
#include "basic_class/BankAccount.hpp"
#include <fmt/core.h>

namespace basic_class{
    void demo() {

        fmt::println("\n===== BASIC CLASS DEMO =====");

        double initialBalance = 0;
        double annualInterestRate = .041;
        BankAccount myBankAccount(initialBalance, annualInterestRate);

        fmt::println("Initial balance: {}", myBankAccount.get_balance());

        myBankAccount.deposit(100);

        fmt::println("Balance after first deposit: {}", myBankAccount.get_balance());

        int yearsOfInterest = 5;
        myBankAccount.apply_interest(yearsOfInterest);

        fmt::println("Balance after {} years of interest: {}", yearsOfInterest, myBankAccount.get_balance());

        bool withdrawalSuccess = myBankAccount.withdraw(40);

        if (withdrawalSuccess) {
            fmt::println("Balance after first withdrawl: {}", myBankAccount.get_balance());
        } else {
            fmt::println("Attempted to withdraw amount greater than balance");
        }

    }
}