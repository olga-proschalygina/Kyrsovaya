#pragma once
#include <string>
#include <cstdint>

namespace game {
    class Weapon {
    private:
        std::string m_name;
        std::int32_t m_damage;
    public:
        Weapon(const std::string& name, std::int32_t damage);
        std::int32_t Attack() const;
        const std::string& GetName() const { return m_name; }
    };
}