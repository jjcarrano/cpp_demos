#include <memory>
#include <vector>
#include "fmt/core.h"
#include "abstract_base_classes.hpp"

class Bakable {
public:
    virtual void bake() const = 0;
    virtual ~Bakable() {}
};

class Cookies : public Bakable {
public:
    void bake() const override {
        fmt::println("Baking cookies!");
    }
};

class Bread : public Bakable {
public:
    void bake() const override {
        fmt::println("Baking bread!");
    }
};

class Bakery {
public:
    Bakery(const std::vector<std::shared_ptr<Bakable>>& items) : itemsToBake(items) {}

    void start_baking() const {
        for (const auto& item : itemsToBake) {
            item->bake();
        }
    }
private:
    std::vector<std::shared_ptr<Bakable>> itemsToBake;
};

void abc_demo() {
    fmt::println("\n===== ABSTRACT BASE CLASS DEMO =====");

    std::vector<std::shared_ptr<Bakable>> itemsToBake = {
        std::make_shared<Cookies>(),
        std::make_shared<Bread>()
    };

    Bakery myBakery(itemsToBake);
    myBakery.start_baking();
}