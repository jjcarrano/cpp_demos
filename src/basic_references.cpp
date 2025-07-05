#include "basic_references.hpp"
#include "fmt/core.h"

namespace basic_references {
    void increment_by_two(int& x) {
        x += 2;
    }

    void demo() {
        fmt::println("\n===== BASIC REFERENCES DEMO =====");

        int a = 10;

        fmt::println("Value of a: {}", a);

        increment_by_two(a);

        fmt::println("Value of a after increment_by_two: {}", a);
    }
}