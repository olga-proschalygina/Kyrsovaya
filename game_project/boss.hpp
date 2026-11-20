#pragma once
#include <string>
#include <cstdint>

namespace game {
    class Player; // Предварительное объявление

    class Boss {
    private:
        std::string m_name;
        std::int32_t m_health;
        std::int32_t m_damage;
    public:
        Boss(const std::string& name, std::int32_t health, std::int32_t damage);
        ~Boss() = default;

        // Босс атакует цель, которую ему передали извне
        void AttackTarget(Player& target);
        void TakeDamage(std::int32_t damage);

        const std::string& GetName() const { return m_name; }
        std::int32_t GetHealth() const { return m_health; }
        bool IsAlive() const { return m_health > 0; }
    };
}