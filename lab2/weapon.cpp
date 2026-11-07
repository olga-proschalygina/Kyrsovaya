#include "weapon.hpp"
#include <iostream>

namespace game
{

    Weapon::Weapon(Type type, const std::string& name, std::int32_t damage)
        : m_type{ type }, m_name{ name }, m_damage{ damage }
    {
        if (m_damage <= 0)
        {
            std::cerr<< "[Weapon] Ошибка: урон не может быть <= 0. Установлено 1.\n";
            m_damage = 1;
        }
    }

    Weapon::~Weapon()
    {
        std::cout <<"[Weapon] Уничтожается оружие: "<< m_name<< "\n";
    }

    std::int32_t Weapon::Attack() const
    {
        if (m_broken)
        {
            std::cerr <<"[Weapon] Отказ: оружие сломано, атака невозможна.\n";
            return 0;
        }
        return m_damage;
    }

    void Weapon::Break()
    {
        m_broken = true;
        std::cout<< "[Weapon] Оружие "<< m_name<< " сломано.\n";
    }

} // namespace game