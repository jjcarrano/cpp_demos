#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <fmt/core.h>
#include <fmt/ranges.h>

namespace basic_containers {
    void demo() {
        fmt::println("\n===== CONTAINERS DEMO =====");

        // vector
        std::vector<int> emptyVector; // if you want to make an empty integer vector

        std::vector<int> v{1, 2, 3, 4};
        fmt::println("Initial vector: {}", v);

        fmt::println("Element at index 2: {}", v.at(2)); // use v[2] if you want to omit bounds checking

        v.at(1) = 7;
        fmt::println("Vector after modifying element at index 1: {}", v);

        v.push_back(10);
        fmt::println("Vector after appending 10: {}", v);

        fmt::println("Last element: {}", v.back());

        v.pop_back();
        fmt::println("Vector after popping last element: {}", v);

        fmt::println("Vector size: {}", v.size());

        // unordered_map
        std::unordered_map<std::string, int> ageMap {
            {"Alice", 30},
            {"Bob", 25},
            {"Charlie", 40}
        };
        fmt::println("Initial map: {}", ageMap);

        ageMap["Sarah"] = 56;
        fmt::println("Map after insertion: {}", ageMap);

        fmt::println("Alice's age: {}", ageMap["Alice"]);

        std::string name = "Susan";
        if (ageMap.find(name) == ageMap.end()) {
            fmt::println("{} not found", name);
        } else {
            fmt::println("{} found", name);
        }

        for (const auto& pair : ageMap) {
            fmt::println("{} is {}", pair.first, pair.second);
        }

        // unordered_set
        std::unordered_set<std::string> s = {"John", "Ryan", "Nelson"};
        fmt::println("Initial set: {}", s);

        s.insert("Kelly");
        fmt::println("Set after insertion: {}", s);

        std::string nombre = "Bob";
        if (s.find(nombre) != s.end()) {
            fmt::println("Found {}", nombre);
        } else {
            fmt::println("Didn't find {}", nombre);
        }
    }
}