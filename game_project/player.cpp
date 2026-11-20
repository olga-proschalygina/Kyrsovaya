#include "player.hpp"
#include <iostream>

<<<<<<< HEAD
namespace game {
    Player::Player(const std::string& name, std::int32_t health, std::int32_t potions, Weapon::Type weaponType, const std::string& weaponName, std::int32_t weaponDamage)
        : m_name(name), m_health(health), m_maxHealth(health), m_potions(potions), m_weapon(weaponType, weaponName, weaponDamage) {
        if (m_health <= 0) { m_health = 1; m_maxHealth = 1; }
    }

    void Player::TakeDamage(std::int32_t damage) {
        if (damage <= 0) return;
        m_health = (m_health - damage < 0) ? 0 : m_health - damage;
        std::cout << "[Player] " << m_name << " РїРѕР»СѓС‡РёР» СѓСЂРѕРЅ " << damage << ". РћР—: " << m_health << "/" << m_maxHealth << "\n";
    }

    bool Player::UsePotion() {
        if (m_potions <= 0 || m_health >= m_maxHealth) return false;
        m_potions--;
        m_health = (m_health + 30 > m_maxHealth) ? m_maxHealth : m_health + 30;
        std::cout << "[Player] " << m_name << " РёСЃРїРѕР»СЊР·РѕРІР°Р» Р·РµР»СЊРµ. РћР—: " << m_health << "\n";
        return true;
    }

    std::int32_t Player::Attack() {
        return m_weapon.Attack();
    }
}
=======
namespace game
{

    Player::Player()
        : m_name{ "Hero" }, m_health{ 100 }, m_maxHealth{ 100 }, m_potions{ 2 }
        , m_weapon{ Weapon::Type::eSword, "Sword", 10 }
    {}

    Player::Player(const std::string& name, std::int32_t health, std::int32_t potions,
        Weapon::Type weaponType, const std::string& weaponName, std::int32_t weaponDamage)
        : m_name{ name }, m_health{ health }, m_maxHealth{ health }, m_potions{ potions }
        , m_weapon{ weaponType, weaponName, weaponDamage }
    {
        if (m_health <= 0)
        {
            std::cerr<< "[Player] Ошибка: здоровье не может быть <= 0. Установлено 1.\n";
            m_health = 1;
            m_maxHealth = 1;
        }
        if (m_potions < 0)
        {
            std::cerr<< "[Player] Ошибка: зелий не может быть < 0. Установлено 0.\n";
            m_potions = 0;
        }
    }

    Player::~Player()
    {
        std::cout<< "[Player] Уничтожается игрок: "<< m_name<< "\n";
    }

    void Player::TakeDamage(std::int32_t damage)
    {
        if (damage <= 0)
        {
            std::cerr<< "[Player] Ошибка: урон не может быть <= 0.\n";
            return;
        }
        if (m_health - damage < 0)
            m_health = 0;
        else
            m_health -= damage;

        std::cout<< "[Player] "<< m_name<< " получил урон "<< damage
           << ". ОЗ: "<< m_health<< "/"<< m_maxHealth<< "\n";
    }

    bool Player::UsePotion()
    {
        if (m_potions <= 0)
        {
            std::cerr<< "[Player] Отказ: зелий нет.\n";
            return false;
        }
        if (m_health >= m_maxHealth)
        {
            std::cerr<< "[Player] Отказ: здоровье уже максимальное.\n";
            return false;
        }
        --m_potions;
        m_health += 30;
        if (m_health > m_maxHealth)
            m_health = m_maxHealth;

        std::cout<< "[Player] "<< m_name<< " использовал зелье. ОЗ: "
           << m_health<< "/"<< m_maxHealth<< ", зелий осталось: "<< m_potions<< "\n";
        return true;
    }

    std::int32_t Player::Attack()
    {
        const std::int32_t dmg = m_weapon.Attack();
        std::cout<< "[Player] "<< m_name<< " атакует оружием "<< m_weapon.GetName()
            << " на " << dmg<< " урона.\n";
        return dmg;
    }

} // namespace game
>>>>>>> d941f764dba2971ef00876f5c442597fa0856ab9
