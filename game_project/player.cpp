#include "player.hpp"
#include <iostream>

namespace game {
    Player::Player(const std::string& name, std::int32_t health, std::int32_t potions, Weapon::Type weaponType, const std::string& weaponName, std::int32_t weaponDamage)
        : m_name(name), m_health(health), m_maxHealth(health), m_potions(potions), m_weapon(weaponType, weaponName, weaponDamage) {
        if (m_health <= 0) { m_health = 1; m_maxHealth = 1; }
    }

    void Player::TakeDamage(std::int32_t damage) {
        if (damage <= 0) return;
        m_health = (m_health - damage < 0) ? 0 : m_health - damage;
        std::cout << "[Player] " << m_name << " получил урон " << damage << ". ОЗ: " << m_health << "/" << m_maxHealth << "\n";
    }

    bool Player::UsePotion() {
        if (m_potions <= 0 || m_health >= m_maxHealth) return false;
        m_potions--;
        m_health = (m_health + 30 > m_maxHealth) ? m_maxHealth : m_health + 30;
        std::cout << "[Player] " << m_name << " использовал зелье. ОЗ: " << m_health << "\n";
        return true;
    }

    std::int32_t Player::Attack() {
        return m_weapon.Attack();
    }
}