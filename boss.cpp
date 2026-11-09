#include "boss.hpp"

namespace game
{

    Boss::Boss(const std::string& name, int health, int damage, std::shared_ptr<Player> target)
        : BaseEntity(name, health) // Вызов конструктора базы
        , m_damage(damage > 0 ? damage : 1)
        , m_target(target)
    {}

    void Boss::TakeDamage(int damage)
    {
        if (damage <= 0) return;
        m_health = (m_health - damage < 0) ? 0 : m_health - damage;
        std::cout << "[Boss] " << m_name << " получил урон " << damage << ". ОЗ: " << m_health << "\n";
    }

    std::unique_ptr<BaseEntity> Boss::Clone() const
    {
        // Для клонирования босса нужен пустой shared_ptr, так как weak_ptr не владеет
        return std::make_unique<Boss>(m_name, m_health, m_damage, nullptr);
    }

    std::string Boss::Describe() const
    {
        // Полностью заменяем описание (без вызова базового метода)
        return "БОСС: " + m_name + " (Урон: " + std::to_string(m_damage) + ")";
    }

    bool Boss::AttackTarget()
    {
        auto target = m_target.lock();
        if (!target || !target->IsAlive()) {
            std::cout << "[Boss] Отказ: цель мертва или отсутствует.\n";
            return false;
        }
        target->TakeDamage(m_damage);
        return true;
    }

} // namespace game