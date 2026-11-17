#include "boss.hpp"
#include "game_exceptions.hpp"
#include <iostream>

namespace game
{

    Boss::Boss(const std::string& name, int health, int damage, std::shared_ptr<Player> target)
        : BaseEntity(name, health)
        , m_damage(damage > 0 ? damage : 1)
        , m_target(target)
    {
        if (damage <= 0) {
            throw GameRuleException("Урон босса не может быть <= 0");
        }
    }

    Boss::Boss(const Boss& other)
        : BaseEntity(other)
        , m_damage(other.m_damage)
        , m_target(other.m_target) // Копируем weak_ptr
    {}

    void Boss::ReceiveDamage(int damage)
    {
        BaseEntity::ReceiveDamage(damage);
    }

    std::unique_ptr<BaseEntity> Boss::Clone() const
    {
        return std::make_unique<Boss>(*this);
    }

    std::string Boss::Describe() const
    {
        return "БОСС: " + m_name + " (Урон: " + std::to_string(m_damage) + ")";
    }

    void Boss::SetTarget(std::shared_ptr<Player> target)
    {
        m_target = target;
    }

    void Boss::AttackTarget()
    {
        auto target = m_target.lock();

        if (!target) {
            throw GameRuleException("Босс не может атаковать: цель уничтожена или отсутствует.");
        }
        if (!target->IsAlive()) {
            throw GameRuleException("Босс не может атаковать: цель уже мертва.");
        }

        std::cout << "[Boss] " << m_name << " атакует " << target->GetName() << "!\n";
        target->ReceiveDamage(m_damage);
    }

} // namespace game