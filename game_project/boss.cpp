#include "boss.hpp"
#include "player.hpp"
#include <iostream>

namespace game {
    Boss::Boss(const std::string& name, int health, int damage)
        : BaseEntity(name, health), m_damage(damage > 0 ? damage : 1) {}

    Boss::Boss(const Boss& other)
        : BaseEntity(other), m_damage(other.m_damage) {}

    Boss::~Boss() {
        std::cout << "[Boss] Уничтожен: " << m_name << "\n";
    }

    void Boss::TakeDamage(int damage) {
        if (damage <= 0) return;
        m_health = (m_health - damage < 0) ? 0 : m_health - damage;
        std::cout << "[Boss] " << m_name << " получил урон " << damage << ". ОЗ: " << m_health << "\n";
    }

    std::unique_ptr<BaseEntity> Boss::Clone() const {
        return std::make_unique<Boss>(*this);
    }

    std::string Boss::Describe() const {
        return "БОСС: " + m_name + " (Урон: " + std::to_string(m_damage) + ")";
    }

    void Boss::AttackTarget(Player& target) {
        if (!target.IsAlive()) {
            std::cout << "[Boss] Отказ: цель уже мертва.\n";
            return;
        }
        std::cout << "[Boss] " << m_name << " атакует " << target.GetName() << " на " << m_damage << " урона.\n";
        target.TakeDamage(m_damage);
    }
}