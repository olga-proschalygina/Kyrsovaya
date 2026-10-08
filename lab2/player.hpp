#pragma once

#include "weapon.hpp"
#include <cstdint>
#include <string>

namespace game
{

    class Player
    {
    private:
        std::string m_name{ "Hero" };
        std::int32_t m_health{ 100 };
        std::int32_t m_maxHealth{ 100 };
        std::int32_t m_potions{ 2 };

        Weapon m_weapon;  // ÊÎÌÏÎÇÈÖÈß

    public:
        Player();
        Player(const std::string& name, std::int32_t health, std::int32_t potions,
            Weapon::Type weaponType, const std::string& weaponName, std::int32_t weaponDamage);

        Player(const Player&) = default;
        Player& operator=(const Player&) = default;
        Player(Player&&) = default;
        Player& operator=(Player&&) = default;

        ~Player();

        [[nodiscard]] const std::string& GetName() const { return m_name; }
        [[nodiscard]] std::int32_t GetHealth() const { return m_health; }
        [[nodiscard]] std::int32_t GetMaxHealth() const { return m_maxHealth; }
        [[nodiscard]] std::int32_t GetPotions() const { return m_potions; }
        [[nodiscard]] bool IsAlive() const { return m_health > 0; }

        [[nodiscard]] const Weapon& GetWeapon() const { return m_weapon; }
        [[nodiscard]] Weapon& GetWeapon() { return m_weapon; }

        void TakeDamage(std::int32_t damage);
        bool UsePotion();
        std::int32_t Attack();
    };

} // namespace game