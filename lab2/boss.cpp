#include "boss.hpp"
#include <iostream>

namespace game
{

    Boss::Boss()
        : m_name{ "Boss" }, m_health{ 300 }, m_damage{ 40 }, m_target{ nullptr }
    {}

    Boss::Boss(const std::string& name, std::int32_t health, std::int32_t damage, Player* target)
        : m_name{ name }, m_health{ health }, m_damage{ damage }, m_target{ target }
    {
        if (m_health <= 0)
        {
            std::cerr<< "[Boss] Ошибка: здоровье не может быть <= 0. Установлено 1.\n";
            m_health = 1;
        }
        if (m_damage <= 0)
        {
            std::cerr << "[Boss] Ошибка: урон не может быть <= 0. Установлено 1.\n";
            m_damage = 1;
        }
    }

    Boss::~Boss()
    {
        std::cout<< "[Boss] Уничтожается босс: "<< m_name<< "\n";
    }

    bool Boss::AttackTarget()
    {
        if (m_target == nullptr)
        {
            std::cerr<< "[Boss] Отказ: цель не задана.\n";
            return false;
        }
        if (!m_target->IsAlive())
        {
            std::cerr << "[Boss] Отказ: цель уже мертва.\n";
            return false;
        }

        std::cout << "[Boss] " << m_name << " атакует " << m_target->GetName()
            << " на " << m_damage << " урона.\n";
        m_target->TakeDamage(m_damage);
        return true;
    }

    void Boss::TakeDamage(std::int32_t damage)
    {
        if (damage <= 0)
        {
            std::cerr << "[Boss] Ошибка: урон не может быть <= 0.\n";
            return;
        }
        if (m_health - damage < 0)
            m_health = 0;
        else
            m_health -= damage;

        std::cout << "[Boss] " << m_name << " получил урон " << damage
            << ". ОЗ: " << m_health << "\n";
    }

} // namespace game