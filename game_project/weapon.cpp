#include "weapon.hpp"

namespace game {
    Weapon::Weapon(const std::string& name, std::int32_t damage)
        : m_name(name), m_damage(damage > 0 ? damage : 1) {}

    std::int32_t Weapon::Attack() const {
        return m_damage;
    }
}