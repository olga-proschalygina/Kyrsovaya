#include "player.hpp"
#include "boss.hpp"
#include "game_exceptions.hpp"
#include <iostream>
#include <vector>
#include <windows.h>
#include <locale.h>

using namespace game;

// Функция, работающая ТОЛЬКО через интерфейс (не зная классов)
void ApplyDamage(IAttackable& target, int damage)
{
    std::cout << "[Система] Наносим урон через интерфейс IAttackable...\n";
    target.ReceiveDamage(damage);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(65001);
    std::cout << "=== ЛР 5: Полиморфизм, интерфейсы, исключения ===\n\n";

    try {
        auto hero = std::make_shared<Player>("Hero", 100, 1, Weapon::Type::eSword, "Excalibur", 20);
        auto boss = std::make_unique<Boss>("Dragon", 200, 45, hero);

        std::cout << "\n--- 1. Интерфейсы и множественное наследование ---\n";
        // Передаем объекты через интерфейс
        ApplyDamage(*hero, 10);
        ApplyDamage(*boss, 50);

        std::cout << "\n--- 2. Раннее и позднее связывание ---\n";
        BaseEntity* ptr = hero.get();
        // Раннее связывание (вызывается метод BaseEntity)
        std::cout << "Раннее: " << ptr->GetEarlyBindingType() << "\n";
        // Позднее связывание (вызывается метод Player)
        std::cout << "Позднее: " << ptr->GetTypeName() << "\n";

        std::cout << "\n--- 3. Проверка типа (dynamic_cast) ---\n";
        BaseEntity* entities[] = { hero.get(), boss.get() };
        for (auto* e : entities) {
            // Проверяем, реализует ли объект интерфейс (хотя тут все реализуют, для примера)
            if (auto* attackable = dynamic_cast<IAttackable*>(e)) {
                std::cout << e->GetName() << " умеет получать урон.\n";
            }
        }

        std::cout << "\n--- 4. Конфигурирование (смена поведения) ---\n";
        std::cout << "Обычная атака:\n";
        hero->Attack();

        std::cout << "Меняем тактику на критическую:\n";
        hero->SetStrategy(std::make_unique<CriticalDamageStrategy>());
        hero->Attack();

        std::cout << "\n--- 5. Исключения ---\n";
        std::cout << "Пытаемся использовать зелье (оно есть):\n";
        hero->UsePotion(); // Успешно

        std::cout << "Пытаемся использовать зелье еще раз (их больше нет):\n";
        hero->UsePotion(); // Бросит исключение GameRuleException

    }
    catch (const GameRuleException& ex) {
        // Перехват частного исключения
        std::cerr << "\n[ОШИБКА ИГРЫ]: " << ex.what() << "\n";
    }
    catch (const std::exception& ex) {
        // Перехват общего исключения (идет после частного)
        std::cerr << "\n[СИСТЕМНАЯ ОШИБКА]: " << ex.what() << "\n";
    }

    std::cout << "\n=== Конец программы ===\n";
    return 0;
}