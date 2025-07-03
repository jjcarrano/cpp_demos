#include "pointers.hpp"
#include <fmt/core.h>

void pointerDemo() {
    int x = 42;
    int* p = &x; // Pointer to x
    fmt::println("Value of x: {}", x);
    fmt::println("Address of x: {}", static_cast<void*>(&x));
}