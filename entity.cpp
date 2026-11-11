#include "entity.hpp"

namespace game
{

    BaseEntity::BaseEntity(const std::string& name, int health)
        : m_name(name), m_health(health), m_maxHealth(health), m_id(s_nextId++)
    {
        if (m_health <= 0) m_health = 1;
        std::cout << "[BaseEntity] Создан объект: " << m_name << " (ID: " << m_id << ")\n";
    }

    BaseEntity::BaseEntity(const BaseEntity& other)
        : m_name(other.m_name), m_health(other.m_health), m_maxHealth(other.m_maxHealth), m_id(s_nextId++)
    {
        std::cout << "[BaseEntity] Копирование (глубокая копия): " << m_name << " (Новый ID: " << m_id << ")\n";
    }

    BaseEntity& BaseEntity::operator=(const BaseEntity& other)
    {
        if (this == &other) return *this; // Проверка самоприсваивания через this!
        m_name = other.m_name;
        m_health = other.m_health;
        m_maxHealth = other.m_maxHealth;
        std::cout << "[BaseEntity] Оператор присваивания: " << m_name << "\n";
        return *this;
    }

    BaseEntity::BaseEntity(BaseEntity&& other) noexcept
        : m_name(std::move(other.m_name)), m_health(other.m_health), m_maxHealth(other.m_maxHealth), m_id(other.m_id)
    {
        std::cout << "[BaseEntity] Перемещение: " << m_name << "\n";
    }

    BaseEntity& BaseEntity::operator=(BaseEntity&& other) noexcept
    {
        if (this == &other) return *this;
        m_name = std::move(other.m_name);
        m_health = other.m_health;
        m_maxHealth = other.m_maxHealth;
        return *this;
    }

    BaseEntity::~BaseEntity()
    {
        std::cout << "[BaseEntity] Уничтожение: " << m_name << " (ID: " << m_id << ")\n";
    }

    std::string BaseEntity::GetHeader() const
    {
        return "[" + std::to_string(m_id) + "] " + m_name + " (ОЗ: " + std::to_string(m_health) + ")";
    }

    std::string BaseEntity::Describe() const
    {
        return GetHeader();
    }

} // namespace game





