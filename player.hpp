#pragma once

#include "entity.hpp"
#include "weapon.hpp"
#include "combat_strategy.hpp"
#include <memory>

namespace game
{

    class Player final : public BaseEntity
    {
    private:
        Weapon m_weapon;
        int m_potions;
        std::unique_ptr<ICombatStrategy> m_strategy;

    public:
        Player(const std::string& name, int health, int potions, Weapon::Type weaponType, const std::string& weaponName, int weaponDamage);

        // Конструктор копирования (нужен для Clone)
        Player(const Player& other);

        ~Player() override = default;

        // Переопределение методов базового класса и интерфейса
        void ReceiveDamage(int damage) override;
        std::unique_ptr<BaseEntity> Clone() const override;
        std::string Describe() const override;
        std::string GetTypeName() const override { return "Игрок"; }
        std::string GetAttackMessage() const override { return "Игрок атакует!"; }

        // Методы предметной области
        void UsePotion();
        int Attack();
        void SetStrategy(std::unique_ptr<ICombatStrategy> strategy);
    };

} // namespace game