#include "boss.hpp"
#include "player.hpp"
#include "weapon.hpp"
#include <vector>
#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace game;

int main()
{
    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);
    

    std::cout << "=== ЛР 4: Наследование в C++ ===\n\n";

    // 1. Создаем игрока и босса
    auto hero = std::make_shared<Player>("Hero", 100, 2, Weapon::Type::eSword, "Excalibur", 25);
    auto boss = std::make_shared<Boss>("Dragon", 200, 45, hero);

    std::cout << "\n--- Массив указателей на базовый класс (полиморфизм) ---\n";
    std::vector < std::unique_ptr < BaseEntity>> entities;

    // Переносим владение в вектор (используем Clone для копии)
    entities.push_back(hero->Clone());
    entities.push_back(boss->Clone());

    // Демонстрация виртуального метода Describe
    for (const auto& entity : entities) {
        std::cout << entity->Describe() << "\n";
    }

    std::cout << "\n--- Демонстрация работы Clone() и глубокой копии ---\n";
    auto heroCopy = hero->Clone();
    std::cout << "Оригинал: " << hero->GetName() << " (ID: " << hero->GetId() << ")\n";
    std::cout << "Копия:    " << heroCopy->GetName() << " (ID: " << heroCopy->GetId() << ")\n";
    std::cout << "Всего сущностей создано: " << BaseEntity::GetTotalCount() << "\n";

    std::cout << "\n--- Выход из main (проверка виртуального деструктора) ---\n";
    // При очистке вектора entities будут вызваны деструкторы Player и Boss (через BaseEntity).
    // Если бы деструктор BaseEntity не был виртуальным, память наследников не очистилась бы корректно!
    return 0;
}





