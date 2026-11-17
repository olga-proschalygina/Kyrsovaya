#include "entity.hpp"
#include "game_exceptions.hpp"
#include <iostream>

namespace game
{

    BaseEntity::BaseEntity(const std::string& name, int health)
        : m_name(name), m_health(health), m_maxHealth(health), m_id(s_nextId++)
    {
        if (m_health <= 0) {
            throw GameRuleException("Здоровье при создании не может быть <= 0");
        }
        std::cout << "[BaseEntity] Создан: " << m_name << " (ID: " << m_id << ")\n";
    }

    BaseEntity::BaseEntity(const BaseEntity& other)
        : m_name(other.m_name), m_health(other.m_health), m_maxHealth(other.m_maxHealth), m_id(s_nextId++)
    {
        std::cout << "[BaseEntity] Копирование: " << m_name << " (Новый ID: " << m_id << ")\n";
    }

    void BaseEntity::ReceiveDamage(int damage)
    {
        if (damage <= 0) {
            throw GameRuleException("Урон не может быть отрицательным или нулевым");
        }
        m_health = (m_health - damage < 0) ? 0 : m_health - damage;
        std::cout << "[BaseEntity] " << m_name << " получил урон " << damage << ". ОЗ: " << m_health << "\n";
    }

    std::string BaseEntity::GetHeader() const
    {
        return "[" + std::to_string(m_id) + "] " + m_name;
    }

    std::string BaseEntity::Describe() const
    {
        return GetHeader();
    }

} // namespace game