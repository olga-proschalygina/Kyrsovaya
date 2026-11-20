#include "weapon.hpp"
#include <iostream>

<<<<<<< HEAD
namespace game {
    Weapon::Weapon(Type type, const std::string& name, std::int32_t damage)
        : m_type(type), m_name(name), m_damage(damage), m_broken(false) {
        if (m_damage <= 0) {
            std::cerr << "[Weapon] РћС€РёР±РєР°: СѓСЂРѕРЅ <= 0\n";
=======
namespace game
{

    Weapon::Weapon(Type type, const std::string& name, std::int32_t damage)
        : m_type{ type }, m_name{ name }, m_damage{ damage }
    {
        if (m_damage <= 0)
        {
            std::cerr<< "[Weapon] Ошибка: урон не может быть <= 0. Установлено 1.\n";
>>>>>>> d941f764dba2971ef00876f5c442597fa0856ab9
            m_damage = 1;
        }
    }

<<<<<<< HEAD
    std::int32_t Weapon::Attack() const {
        if (m_broken) {
            std::cerr << "[Weapon] РћС‚РєР°Р·: РѕСЂСѓР¶РёРµ СЃР»РѕРјР°РЅРѕ\n";
=======
    Weapon::~Weapon()
    {
        std::cout <<"[Weapon] Уничтожается оружие: "<< m_name<< "\n";
    }

    std::int32_t Weapon::Attack() const
    {
        if (m_broken)
        {
            std::cerr <<"[Weapon] Отказ: оружие сломано, атака невозможна.\n";
>>>>>>> d941f764dba2971ef00876f5c442597fa0856ab9
            return 0;
        }
        return m_damage;
    }

<<<<<<< HEAD
    void Weapon::Break() {
        m_broken = true;
    }
}
=======
    void Weapon::Break()
    {
        m_broken = true;
        std::cout<< "[Weapon] Оружие "<< m_name<< " сломано.\n";
    }

} // namespace game
>>>>>>> d941f764dba2971ef00876f5c442597fa0856ab9
