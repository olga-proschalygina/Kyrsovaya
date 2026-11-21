#pragma once
<<<<<<< HEAD
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
=======

#include "player.hpp"
#include <cstdint>
#include <string>

namespace game
{

    class Boss
    {
    private:
        std::string m_name{ "Boss" };
        std::int32_t m_health{ 300 };
        std::int32_t m_damage{ 40 };

        Player* m_target{ nullptr };  // ���������

    public:
        Boss();
        Boss(const std::string& name, std::int32_t health, std::int32_t damage, Player* target);

        Boss(const Boss&) = default;
        Boss& operator=(const Boss&) = default;
        Boss(Boss&&) = default;
        Boss& operator=(Boss&&) = default;

        ~Boss();

        [[nodiscard]] const std::string& GetName() const { return m_name; }
        [[nodiscard]] std::int32_t GetHealth() const { return m_health; }
        [[nodiscard]] bool IsAlive() const { return m_health > 0; }
        [[nodiscard]] Player* GetTarget() const { return m_target; }

        void SetTarget(Player* target) { m_target = target; }

        bool AttackTarget();
        void TakeDamage(std::int32_t damage);
    };

} // namespace game
>>>>>>> d941f764dba2971ef00876f5c442597fa0856ab9
