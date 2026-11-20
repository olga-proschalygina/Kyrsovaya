#include "boss.hpp"
#include "player.hpp"
#include <iostream>

namespace game {
    Boss::Boss(const std::string& name, std::int32_t health, std::int32_t damage)
        : m_name(name), m_health(health), m_damage(damage > 0 ? damage : 1) {}

    void Boss::AttackTarget(Player& target) {
        if (!target.IsAlive()) {
            std::cerr << "[Boss] Отказ: цель мертва\n";
            return;
        }
        std::cout << "[Boss] " << m_name << " атакует " << target.GetName() << " на " << m_damage << " урона.\n";
        target.TakeDamage(m_damage);
    }

    void Boss::TakeDamage(std::int32_t damage) {
        if (damage <= 0) return;
        m_health = (m_health - damage < 0) ? 0 : m_health - damage;
        std::cout << "[Boss] " << m_name << " получил урон " << damage << ". ОЗ: " << m_health << "\n";
    }
}