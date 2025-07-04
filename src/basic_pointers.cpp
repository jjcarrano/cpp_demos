#include "basic_pointers.hpp"
#include <fmt/core.h>

void pointer_demo() {
    fmt::println("\n===== BASIC POINTER DEMO =====");

    int x = 42;
    int* p = &x; // Pointer to x
    fmt::println("Value of x: {}", x);
    fmt::println("Address of x: {}", static_cast<void*>(&x));
    fmt::println("Value of p: {}", static_cast<void*>(p)); // same as &x
    fmt::println("Value pointed to by p: {}", *p); // same as x

    *p = 100; // Change the value of x through the pointer
    fmt::println("New value of x: {}", x);
}