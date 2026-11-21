#pragma once
<<<<<<< HEAD
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
        Weapon m_weapon; // –ö–æ–º–ø–æ–∑–∏—Ü–∏—è
    public:
        Player(const std::string& name, std::int32_t health, std::int32_t potions, Weapon::Type weaponType, const std::string& weaponName, std::int32_t weaponDamage);
        ~Player() = default;
=======

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

        Weapon m_weapon;  //  ŒÃœŒ«»÷»ﬂ

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
>>>>>>> d941f764dba2971ef00876f5c442597fa0856ab9

        void TakeDamage(std::int32_t damage);
        bool UsePotion();
        std::int32_t Attack();
<<<<<<< HEAD

        const std::string& GetName() const { return m_name; }
        std::int32_t GetHealth() const { return m_health; }
        bool IsAlive() const { return m_health > 0; }
        const Weapon& GetWeapon() const { return m_weapon; }
    };
}
=======
    };

} // namespace game
>>>>>>> d941f764dba2971ef00876f5c442597fa0856ab9
