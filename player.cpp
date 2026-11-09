#include "player.hpp"

namespace game
{

    Player::Player(const std::string& name, int health, int potions, Weapon::Type weaponType, const std::string& weaponName, int weaponDamage)
        : BaseEntity(name, health) // Вызов конструктора базы в списке инициализации
        , m_weapon(weaponType, weaponName, weaponDamage)
        , m_potions(potions)
    {
        if (m_potions < 0) m_potions = 0;
    }

    Player::Player(const Player& other)
        : BaseEntity(other) // Вызов копирующего конструктора базы
        , m_weapon(other.m_weapon)
        , m_potions(other.m_potions)
    {}

    void Player::TakeDamage(int damage)
    {
        if (damage <= 0) return;
        m_health = (m_health - damage < 0) ? 0 : m_health - damage;
        std::cout << "[Player] " << m_name << " получил урон " << damage << ". ОЗ: " << m_health << "\n";
    }

    std::unique_ptr<BaseEntity> Player::Clone() const
    {
        return std::make_unique<Player>(*this);
    }

    std::string Player::Describe() const
    {
        // Вызов версии базового класса
        return BaseEntity::Describe() + ", зелий: " + std::to_string(m_potions);
    }

    bool Player::UsePotion()
    {
        if (m_potions <= 0 || m_health >= m_maxHealth) return false;
        m_potions--;
        m_health = (m_health + 30 > m_maxHealth) ? m_maxHealth : m_health + 30;
        return true;
    }

    int Player::Attack()
    {
        return m_weapon.Attack();
    }

} // namespace game