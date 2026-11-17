#pragma once

#include <cstdint>
#include <string>

namespace game
{

    class Weapon
    {
    public:
        enum class Type { eSword, eBow, eSpear };

    private:
        Type m_type{ Type::eSword };
        std::string m_name{ "Sword" };
        std::int32_t m_damage{ 10 };
        bool m_broken{ false };

    public:
        Weapon() = default;
        Weapon(Type type, const std::string& name, std::int32_t damage);

        Weapon(const Weapon&) = default;
        Weapon& operator=(const Weapon&) = default;
        Weapon(Weapon&&) = default;
        Weapon& operator=(Weapon&&) = default;

        ~Weapon();

        [[nodiscard]] Type GetType() const { return m_type; }
        [[nodiscard]] const std::string& GetName() const { return m_name; }
        [[nodiscard]] std::int32_t GetDamage() const { return m_damage; }
        [[nodiscard]] bool IsBroken() const { return m_broken; }

        void SetBroken(bool broken) { m_broken = broken; }

        std::int32_t Attack() const;
        void Break();
    };

} // namespace game