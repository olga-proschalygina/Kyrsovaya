#pragma once
#include "entity.hpp"
#include "weapon.hpp"

namespace game {
    class Player final : public BaseEntity {
    private:
        Weapon m_weapon;
        int m_potions;
    public:
        Player(const std::string& name, int health, int potions, const std::string& weaponName, int weaponDamage);
        Player(const Player& other);
        ~Player() override;

        void TakeDamage(int damage) override;
        std::unique_ptr<BaseEntity> Clone() const override;
        std::string Describe() const override;

        void UsePotion();
        int Attack();
    };
}