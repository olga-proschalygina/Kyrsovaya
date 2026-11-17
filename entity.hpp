#pragma once

#include "iattackable.hpp"
#include <string>
#include <memory>

namespace game
{

    class BaseEntity : public IAttackable
    {
    protected:
        std::string m_name;
        int m_health;
        int m_maxHealth;
        inline static int s_nextId{ 1 };
        int m_id;
        virtual std::string GetHeader() const;

    public:
        BaseEntity(const std::string& name, int health);
        BaseEntity(const BaseEntity& other); // Конструктор копирования
        virtual ~BaseEntity() = default;

        void ReceiveDamage(int damage) override;
        virtual std::unique_ptr<BaseEntity> Clone() const = 0;
        virtual std::string Describe() const;
        virtual std::string GetTypeName() const { return "Сущность"; }
        std::string GetEarlyBindingType() const { return "Базовая сущность (раннее)"; }

        [[nodiscard]] int GetId() const { return m_id; }
        [[nodiscard]] const std::string& GetName() const { return m_name; }
        [[nodiscard]] int GetHealth() const { return m_health; }
        [[nodiscard]] bool IsAlive() const { return m_health > 0; }
    };

} // namespace game