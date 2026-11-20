#include "player.hpp"

namespace game {
    Player::Player(const std::string& name, int health, int potions, const std::string& weaponName, int weaponDamage)
        : BaseEntity(name, health), m_weapon(weaponName, weaponDamage), m_potions(potions) {}

    Player::Player(const Player& other)
        : BaseEntity(other), m_weapon(other.m_weapon), m_potions(other.m_potions) {}

    Player::~Player() {
        std::cout << "[Player] Уничтожен: " << m_name << "\n";
    }

    void Player::TakeDamage(int damage) {
        if (damage <= 0) return;
        m_health = (m_health - damage < 0) ? 0 : m_health - damage;
        std::cout << "[Player] " << m_name << " получил урон " << damage << ". ОЗ: " << m_health << "\n";
    }

    std::unique_ptr<BaseEntity> Player::Clone() const {
        return std::make_unique<Player>(*this);
    }

    std::string Player::Describe() const {
        return BaseEntity::Describe() + ", зелий: " + std::to_string(m_potions);
    }

    void Player::UsePotion() {
        if (m_potions <= 0 || m_health >= m_maxHealth) return;
        m_potions--;
        m_health = (m_health + 30 > m_maxHealth) ? m_maxHealth : m_health + 30;
        std::cout << "[Player] " << m_name << " использовал зелье. ОЗ: " << m_health << "\n";
    }

    int Player::Attack() {
        return m_weapon.Attack();
    }
}