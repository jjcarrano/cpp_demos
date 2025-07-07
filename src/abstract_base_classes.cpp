#include <memory>
#include <vector>
#include "fmt/core.h"
#include "abstract_base_classes.hpp"

namespace {
    class Bakable {
    public:
        virtual void bake() const = 0;
        virtual ~Bakable() = default;
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
        explicit Bakery(const std::vector<std::shared_ptr<Bakable>>& items) : itemsToBake_(items) {}

        void start_baking() const {
            for (const auto& item : itemsToBake_) {
                item->bake();
            }
        }
    private:
        std::vector<std::shared_ptr<Bakable>> itemsToBake_;
    };
}

namespace abstract_base_classes {
    void demo() {
    fmt::println("\n===== ABSTRACT BASE CLASS DEMO =====");

    std::vector<std::shared_ptr<Bakable>> itemsToBake = {
        std::make_shared<Cookies>(),
        std::make_shared<Bread>()
    };

    Bakery myBakery(itemsToBake);
    myBakery.start_baking();
    }
}
