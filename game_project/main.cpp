#include "game_world.hpp"
#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace game;

int main() {    
    SetConsoleOutputCP(65001);
    std::cout << "=== ЛР 3: Умные указатели (GameWorld) ===\n\n";

    // 1. Демонстрация unique_ptr
    {
        auto boss = std::make_unique<Boss>("UniqueBoss", 200, 45);
        std::cout << "Босс создан (unique_ptr).\n";
    }
    std::cout << "Вышли из блока. Босс уничтожен.\n\n";

    // 2. Демонстрация shared_ptr и GameWorld
    {
        auto hero = std::make_shared<Player>("Hero", 100, 2, Weapon::Type::eSword, "Excalibur", 25);
        auto boss = std::make_unique<Boss>("Dragon", 200, 45);

        // Передаем их в мир (Босс передается по move, Игрок копируется)
        GameWorld world(hero, std::move(boss));

        std::cout << "Владельцев hero (в main): " << hero.use_count() << "\n"; // 1

        world.PrintState();
        world.StartCombat();
        world.PrintState();
    } // Уничтожается GameWorld (вместе с Boss и Player)

    return 0;
}