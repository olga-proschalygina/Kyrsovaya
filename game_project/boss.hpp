#pragma once

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

        Player* m_target{ nullptr };  // ÀÃÐÅÃÀÖÈß

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