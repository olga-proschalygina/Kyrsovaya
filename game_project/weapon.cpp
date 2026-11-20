#include "weapon.hpp"
#include <iostream>

namespace game {
    Weapon::Weapon(Type type, const std::string& name, std::int32_t damage)
        : m_type(type), m_name(name), m_damage(damage), m_broken(false) {
        if (m_damage <= 0) {
            std::cerr << "[Weapon] Ошибка: урон <= 0\n";
            m_damage = 1;
        }
    }

    std::int32_t Weapon::Attack() const {
        if (m_broken) {
            std::cerr << "[Weapon] Отказ: оружие сломано\n";
            return 0;
        }
        return m_damage;
    }

    void Weapon::Break() {
        m_broken = true;
    }
}