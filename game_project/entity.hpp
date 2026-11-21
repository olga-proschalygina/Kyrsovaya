#pragma once
#include <string>
#include <memory>
#include <iostream>

namespace game {

    class BaseEntity {
    protected:
        std::string m_name;
        int m_health;
        int m_maxHealth;
        inline static int s_nextId{ 1 };
        int m_id;

        virtual std::string GetHeader() const;

    public:
        BaseEntity(const std::string& name, int health);
        BaseEntity(const BaseEntity& other); // Копирование
        virtual ~BaseEntity(); // Виртуальный деструктор

        virtual void TakeDamage(int damage) = 0;
        virtual std::unique_ptr<BaseEntity> Clone() const = 0;
        virtual std::string Describe() const;

        int GetId() const { return m_id; }
        std::string GetName() const { return m_name; }
        int GetHealth() const { return m_health; }
        bool IsAlive() const { return m_health > 0; }
    };
}