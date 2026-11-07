//
// ФАЙЛ main.cpp
// Лабораторная работа 3. Часть 2. Умные указатели.
//
#include "boss.hpp"
#include "player.hpp"
#include "weapon.hpp"
#include <locale>
#include <iostream>
#include <memory>  // Для unique_ptr, shared_ptr, weak_ptr
#include <vector>  // Для std::vector
#include <windows.h> // Для русского языка в консоли

using namespace game;

static void PrintState(const Player& player, const Boss& boss)
{
    std::cout << "--- Состояние ---\n";
    std::cout << "Игрок: " << player.GetName()
        << ", ОЗ: " << player.GetHealth() << "/" << player.GetMaxHealth()
        << ", зелий: " << player.GetPotions()
        << ", оружие: " << player.GetWeapon().GetName() << "\n";
    std::cout << "Босс: " << boss.GetName()
        << ", ОЗ: " << boss.GetHealth() << "\n";
    std::cout << "-----------------\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(65001); // UTF-8 для Windows
    SetConsoleCP(65001);

    std::cout << "=== ЛР 3: Умные указатели в C++ ===\n\n";

    // ==========================================
    // 1. Демонстрация std::unique_ptr
    // ==========================================
    {
        std::cout << "\n[1. unique_ptr: эксклюзивное владение и передача через std::move]\n";

        // Создание через make_unique (нет new)
        std::unique_ptr<Player> player = std::make_unique<Player>(
            "UniqueHero", 100, 1, Weapon::Type::eSword, "IronSword", 15
        );

        std::cout << "Игрок создан. ОЗ: " << player->GetHealth() << "\n";

        // Передача владения
        std::unique_ptr<Player> newOwner = std::move(player);

        if (!player) {
            std::cout << "Старый указатель player пуст (владение передано).\n";
        }
        if (newOwner) {
            std::cout << "Новый владелец newOwner управляет игроком: " << newOwner->GetName() << "\n";
        }
    } // Здесь newOwner выходит из области видимости, Player уничтожается автоматически
    std::cout << "Вышли из блока. Игрок уничтожен.\n";

    // ==========================================
    // 2. Демонстрация std::shared_ptr и std::weak_ptr
    // ==========================================
    {
        std::cout << "\n[2. shared_ptr и weak_ptr: совместное владение и наблюдение]\n";

        // Создаем игрока через shared_ptr
        std::shared_ptr<Player> hero = std::make_shared<Player>(
            "SharedHero", 100, 2, Weapon::Type::eSword, "Excalibur", 25
        );

        std::cout << "Счетчик владельцев hero: " << hero.use_count() << "\n"; // 1

        // Создаем босса и передаем ему weak_ptr (агрегация)
        // Boss не увеличивает счетчик владельцев!
        std::unique_ptr<Boss> boss = std::make_unique<Boss>("Dragon", 200, 45, hero);

        std::cout << "Счетчик владельцев hero после создания босса (weak_ptr): " << hero.use_count() << "\n"; // Все еще 1

        // Создаем копию shared_ptr (второй владелец)
        {
            std::shared_ptr<Player> heroCopy = hero;
            std::cout << "Счетчик владельцев hero (после копирования): " << hero.use_count() << "\n"; // 2

            PrintState(*hero, *boss);
            boss->AttackTarget(); // Босс успешно атакует через weak_ptr
        } // heroCopy уничтожается здесь
        std::cout << "Счетчик владельцев hero (копия уничтожена): " << hero.use_count() << "\n"; // 1

        // Проверяем weak_ptr, пока объект жив
        std::cout << "\n-- Босс атакует, пока игрок жив --\n";
        boss->AttackTarget();

        // Уничтожаем последнего владельца (игрока)
        std::cout << "\n-- Уничтожаем последнего владельца (hero.reset()) --\n";
        hero.reset();

        // В этот момент сработает деструктор Player и Weapon!

        std::cout << "\n-- Босс пытается атаковать мертвого (уничтоженного) игрока --\n";
        boss->AttackTarget(); // weak_ptr::lock() вернет nullptr, босс корректно обработает это

    } // Здесь уничтожается босс
    std::cout << "Вышли из блока. Босс уничтожен.\n";

    // ========================================= =
        // 3. Массив умных указателей (замена new[]/delete[])
        // ==========================================
    {
        std::cout << "\n[3. Массив умных указателей]\n";

    // Массив динамических объектов (как в ЛР2, но без new/delete)
        std::vector<std::unique_ptr<Player>>players;
        players.push_back(std::make_unique<Player>("P1", 50, 1, Weapon::Type::eSword, "Sword1", 10));
        players.push_back(std::make_unique<Player>("P2", 60, 1, Weapon::Type::eBow, "Bow1", 12));
        for(const auto& p : players){
            std::cout << "Игрок в массиве: " << p->GetName() << ", ОЗ:" << p->GetHealth() << "\n";
    }
    } // Вектор уничтожается, вместе с ним уничтожаются все unique_ptr и объекты Player

    std::cout << "\n=== Конец программы ===\n";
    return 0;
}