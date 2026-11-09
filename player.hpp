#pragma once

#include "entity.hpp"
#include "weapon.hpp"

namespace game
{

    // final запрещает дальнейшее наследование от Player
    class Player final : public BaseEntity
    {
    private:
        Weapon m_weapon;
        int m_potions;

    public:
        Player(const std::string& name, int health, int potions, Weapon::Type weaponType, const std::string& weaponName, int weaponDamage);

        // Правило нуля (поля сами управляют памятью, но нам нужен клонирующий конструктор для глубокой копии)
        Player(const Player& other);

        // Переопределяем чисто виртуальные методы
        void TakeDamage(int damage) override;
        std::unique_ptr<BaseEntity> Clone() const override;

        // Переопределяем с вызовом базового метода
        std::string Describe() const override;

        bool UsePotion();
        int Attack();
        const Weapon& GetWeapon() const { return m_weapon; }
    };

} // namespace game