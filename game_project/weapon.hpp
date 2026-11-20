#pragma once
#include <string>
#include <cstdint>

namespace game {
    class Weapon {
    public:
        enum class Type { eSword, eBow, eSpear };
    private:
        Type m_type;
        std::string m_name;
        std::int32_t m_damage;
        bool m_broken;
    public:
        Weapon(Type type, const std::string& name, std::int32_t damage);
        ~Weapon() = default;

        std::int32_t Attack() const;
        void Break();
        const std::string& GetName() const { return m_name; }
        std::int32_t GetDamage() const { return m_damage; }
        Type GetType() const { return m_type; }
    };
}