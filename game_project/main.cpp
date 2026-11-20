#include "boss.hpp"
#include "player.hpp"
#include "weapon.hpp"
#include <iostream>
#include <locale.h>
#include <windows.h>

using namespace game;

static void PrintState(const Player& player, const Boss& boss)
{
    std::cout << "--- Состояние ---\n";
    std::cout << "Игрок: " << player.GetName()
        << ", ОЗ: " << player.GetHealth() << "/" << player.GetMaxHealth()
        << ", зелий: " << player.GetPotions()
        << ", оружие: " << player.GetWeapon().GetName()
        << " (" << player.GetWeapon().GetDamage() << ")\n";
    std::cout<< "Босс: " << boss.GetName()
        << ", ОЗ: " << boss.GetHealth() << "\n";
    std::cout << "-----------------\n";
}

int main()
{  
    setlocale(LC_ALL, "Russian");
    std::cout << "=== Сценарий 5: смерть от босса ===\n\n";

    // --- Статическая инициализация ---
    {
        std::cout << "\n[Статическая инициализация]\n";
        Player staticPlayer("StaticHero", 100, 2, Weapon::Type::eSword, "SteelSword", 15);
        Boss staticBoss("StaticBoss", 200, 30, &staticPlayer);

        PrintState(staticPlayer, staticBoss);
        staticBoss.AttackTarget();
        staticPlayer.Attack();
        PrintState(staticPlayer, staticBoss);
    }

    // --- Динамическая инициализация ---
    {
        std::cout << "\n[Динамическая инициализация new/delete]\n";
        auto* dynPlayer = new Player("DynHero", 100, 1, Weapon::Type::eBow, "LongBow", 12);
        auto* dynBoss = new Boss("DynBoss", 150, 35, dynPlayer);

        PrintState(*dynPlayer, *dynBoss);
        dynBoss->AttackTarget();
        dynPlayer->Attack();
        PrintState(*dynPlayer, *dynBoss);

        delete dynBoss;
        delete dynPlayer;
    }

    // --- Ссылки и указатели ---
    {
        std::cout << "\n[Работа по ссылке и указателю]\n";
        Player refPlayer("RefHero", 80, 2, Weapon::Type::eSpear, "Spear", 18);
        Boss   refBoss("RefBoss", 120, 25, &refPlayer);

        Player& playerRef = refPlayer;
        Boss* bossPtr = &refBoss;

        PrintState(playerRef, *bossPtr);
        bossPtr->AttackTarget();
        playerRef.Attack();
        PrintState(playerRef, *bossPtr);
    }

    // --- Динамический массив объектов класса ---
    {
        std::cout << "\n[Динамический массив объектов класса]\n";
        Player* players = new Player[2]{
            Player("P1", 50, 1, Weapon::Type::eSword, "Sword1", 10),
            Player("P2", 60, 1, Weapon::Type::eBow, "Bow1", 12)
        };

        std::cout << "Игрок 1: " << players[0].GetName()
            << ", ОЗ: " << players[0].GetHealth() << "\n";
        std::cout << "Игрок 2: " << players[1].GetName()
            << ", ОЗ: " << players[1].GetHealth() << "\n";

        delete[] players;
    }

    // --- Массив динамических объектов класса ---
    {
        std::cout << "\n[Массив динамических объектов класса]\n";
        auto** playerPtrs = new Player * [2];
        playerPtrs[0] = new Player("DP1", 70, 1, Weapon::Type::eSpear, "Spear1", 15);
        playerPtrs[1] = new Player("DP2", 90, 2, Weapon::Type::eSword, "Sword2", 20);

        std::cout << "Игрок 1: " << playerPtrs[0]->GetName()
            << ", ОЗ: " << playerPtrs[0]->GetHealth() << "\n";
        std::cout << "Игрок 2: " << playerPtrs[1]->GetName()
            << ", ОЗ: " << playerPtrs[1]->GetHealth() << "\n";

        delete playerPtrs[0];
        delete playerPtrs[1];
        delete[] playerPtrs;
    }

    // --- Время жизни: композиция ---
    {
        std::cout << "\n[Композиция: Player содержит Weapon]\n";
        std::cout << "Входим во вложенный блок...\n";
        {
            Player innerPlayer("InnerHero", 100, 1, Weapon::Type::eSword, "InnerSword", 15);
            std::cout << "Игрок создан, оружие: " << innerPlayer.GetWeapon().GetName() << "\n";
            std::cout << "Выходим из вложенного блока...\n";
        }
        std::cout<< "Вышли из блока. Деструкторы Player и Weapon вызваны автоматически.\n";
    }

    // -- - Время жизни : агрегация-- -
    {
        std::cout << "\n[Агрегация: Boss использует Player]\n";
        Player aggPlayer("AggHero", 100, 1, Weapon::Type::eSword, "AggSword", 15);

        {
            std::cout << "Входим во вложенный блок, создаём босса...\n";
            Boss aggBoss("AggBoss", 100, 20, &aggPlayer);
            aggBoss.AttackTarget();
            aggPlayer.Attack();
            std::cout << "Выходим из вложенного блока, босс уничтожается...\n";
        }

        std::cout << "Босс уничтожен, но игрок продолжает существовать.\n";
        std::cout << "Игрок: " << aggPlayer.GetName()
            << ", ОЗ: " << aggPlayer.GetHealth() << "/" << aggPlayer.GetMaxHealth() << "\n";

        aggPlayer.TakeDamage(10);
        std::cout << "Игрок после урона: ОЗ = " << aggPlayer.GetHealth() << "\n";
        std::cout << "Игрок жив: " <<(aggPlayer.IsAlive() ? "да" : "нет") << "\n";
    }

    // --- Сценарий 5 ---
    {
        std::cout << "\n=== Сценарий 5: смерть от босса ===\n";

        Player hero("Hero", 100, 2, Weapon::Type::eSword, "Excalibur", 25);
        Boss   boss("Dragon", 200, 45, &hero);

        PrintState(hero, boss);

        std::cout << "\n-- Бой начинается --\n";
        boss.AttackTarget();
        PrintState(hero, boss);

        std::cout << "\n-- Игрок использует зелье --\n";
        hero.UsePotion();
        PrintState(hero, boss);

        std::cout << "\n-- Босс атакует снова --\n";
        boss.AttackTarget();
        PrintState(hero, boss);

        std::cout << "\n-- Игрок использует последнее зелье --\n";
        hero.UsePotion();
        PrintState(hero, boss);

        std::cout << "\n-- Босс атакует снова --\n";
        boss.AttackTarget();
        PrintState(hero, boss);

        std::cout << "\n-- Попытка использовать зелье, когда их нет --\n";
        hero.UsePotion();

        std::cout << "\n-- Босс наносит смертельный удар --\n";
        boss.AttackTarget();
        PrintState(hero, boss);

        std::cout << "\n-- Проверка: игрок мёртв --\n";
        std::cout << "Игрок жив: " <<(hero.IsAlive() ? "да" : "нет") << "\n";

        std::cout << "\n-- Босс пытается атаковать мёртвого игрока --\n";
        boss.AttackTarget();

        std::cout << "\n-- Конец боя --\n";
    }

    std::cout << "\n=== Конец программы ===\n";
    return 0;
}