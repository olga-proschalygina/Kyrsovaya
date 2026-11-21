#include "entity.hpp"

namespace game {
    BaseEntity::BaseEntity(const std::string& name, int health)
        : m_name(name), m_health(health), m_maxHealth(health), m_id(s_nextId++) {
        if (m_health <= 0) { m_health = 1; m_maxHealth = 1; }
        std::cout << "[BaseEntity] Создан: " << m_name << " (ID: " << m_id << ")\n";
    }

    BaseEntity::BaseEntity(const BaseEntity& other)
        : m_name(other.m_name), m_health(other.m_health), m_maxHealth(other.m_maxHealth), m_id(s_nextId++) {
        std::cout << "[BaseEntity] Копирование: " << m_name << " (Новый ID: " << m_id << ")\n";
    }

    BaseEntity::~BaseEntity() {
        std::cout << "[BaseEntity] Уничтожен: " << m_name << "\n";
    }

    std::string BaseEntity::GetHeader() const {
        return "[" + std::to_string(m_id) + "] " + m_name + " (ОЗ: " + std::to_string(m_health) + ")";
    }

    std::string BaseEntity::Describe() const {
        return GetHeader();
    }
}