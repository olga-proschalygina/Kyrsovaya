#pragma once

#include <memory>
#include <iostream>

namespace game
{

    // Интерфейс поведения
    class ICombatStrategy
    {
    public:
        virtual ~ICombatStrategy() = default;
        virtual int CalculateDamage(int baseDamage) const = 0;
    };

    // Реализация 1: Обычный урон
    class NormalDamageStrategy : public ICombatStrategy
    {
    public:
        int CalculateDamage(int baseDamage) const override
        {
            return baseDamage;
        }
    };

    // Реализация 2: Критический урон (x2)
    class CriticalDamageStrategy : public ICombatStrategy
    {
    public:
        int CalculateDamage(int baseDamage) const override
        {
            return baseDamage * 2;
        }
    };

} // namespace game