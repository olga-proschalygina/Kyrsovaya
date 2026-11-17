#include "player.hpp"
#include "game_exceptions.hpp"
#include <iostream>

namespace game
{

    Player::Player(const std::string& name, int health, int potions, Weapon::Type weaponType, const std::string& weaponName, int weaponDamage)
        : BaseEntity(name, health)
        , m_weapon(weaponType, weaponName, weaponDamage)
        , m_potions(potions)
        , m_strategy(std::make_unique<NormalDamageStrategy>())
    {
        if (m_potions < 0) {
            throw GameRuleException("Количество зелий не может быть отрицательным");
        }
    }

    Player::Player(const Player& other)
        : BaseEntity(other)
        , m_weapon(other.m_weapon)
        , m_potions(other.m_potions)
        , m_strategy(std::make_unique<NormalDamageStrategy>()) // Копируем базовую стратегию
    {}

    void Player::ReceiveDamage(int damage)
    {
        BaseEntity::ReceiveDamage(damage);
    }

    std::unique_ptr<BaseEntity> Player::Clone() const
    {
        return std::make_unique<Player>(*this);
    }

    std::string Player::Describe() const
    {
        return BaseEntity::Describe() + ", зелий: " + std::to_string(m_potions);
    }

    void Player::UsePotion()
    {
        if (m_potions <= 0) {
            throw GameRuleException("Нет зелий для использования!");
        }
        if (m_health >= m_maxHealth) {
            throw GameRuleException("Здоровье уже максимальное!");
        }
        m_potions--;
        m_health += 30;
        if (m_health > m_maxHealth) m_health = m_maxHealth;
        std::cout << "[Player] " << m_name << " использовал зелье. ОЗ: " << m_health << "\n";
    }

    int Player::Attack()
    {
        int baseDamage = m_weapon.Attack();
        int finalDamage = m_strategy->CalculateDamage(baseDamage);
        std::cout << "[Player] " << m_name << " атакует на " << finalDamage << " урона.\n";
        return finalDamage;
    }

    void Player::SetStrategy(std::unique_ptr<ICombatStrategy> strategy)
    {
        m_strategy = std::move(strategy);
    }

} // namespace game