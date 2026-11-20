#pragma once
#include "weapon.hpp"
#include <string>
#include <cstdint>

namespace game {
    class Player {
    private:
        std::string m_name;
        std::int32_t m_health;
        std::int32_t m_maxHealth;
        std::int32_t m_potions;
        Weapon m_weapon; // Композиция
    public:
        Player(const std::string& name, std::int32_t health, std::int32_t potions, Weapon::Type weaponType, const std::string& weaponName, std::int32_t weaponDamage);
        ~Player() = default;

        void TakeDamage(std::int32_t damage);
        bool UsePotion();
        std::int32_t Attack();

        const std::string& GetName() const { return m_name; }
        std::int32_t GetHealth() const { return m_health; }
        bool IsAlive() const { return m_health > 0; }
        const Weapon& GetWeapon() const { return m_weapon; }
    };
}