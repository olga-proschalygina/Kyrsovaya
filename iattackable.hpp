#pragma once

#include <string>

namespace game
{

    // Интерфейс: только чисто виртуальные методы и виртуальный деструктор
    class IAttackable
    {
    public:
        virtual ~IAttackable() = default;

        // Контракт: любой атакуемый должен уметь получать урон
        virtual void ReceiveDamage(int damage) = 0;

        // Позднее связывание для невиртуального метода (демонстрация)
        virtual std::string GetAttackMessage() const = 0;
    };

} // namespace game