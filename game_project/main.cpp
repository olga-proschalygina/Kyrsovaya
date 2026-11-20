#include "game_world.hpp"
#include <iostream>
#include <vector>
#include <windows.h>

using namespace game;

int main() {
    SetConsoleOutputCP(65001);
    std::cout << "=== ЛР 4: Наследование (C++) ===\n\n";

    std::cout << "--- Создание объектов ---\n";
    auto hero = std::make_shared<Player>("Hero", 100, 2, "Excalibur", 25);
    auto boss = std::make_unique<Boss>("Dragon", 200, 45);

    std::cout << "\n--- Полиморфизм (через базовый класс) ---\n";
    std::vector < std::unique_ptr < BaseEntity>> entities;
    entities.push_back(hero->Clone());
    entities.push_back(boss->Clone());

    for (const auto& e : entities) {
        std::cout << e->Describe() << "\n";
    }

    std::cout << "\n--- Бой через GameWorld ---\n";
    GameWorld world(hero, std::move(boss));
    world.StartCombat();

    std::cout << "\n=== Конец программы ===\n";
    return 0;
}