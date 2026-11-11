#pragma once

#include <string>
#include <memory>
#include <iostream>

namespace game
{

    class BaseEntity
    {
    protected:
        // Защищенное поле: нужно наследникам, но недоступно снаружи
        std::string m_name;
        int m_health;
        int m_maxHealth;

        // Статический счетчик (генератор ID)
        inline static int s_nextId{ 1 };
        int m_id;

        // Защищенный метод, чтобы наследники могли собрать описание
        virtual std::string GetHeader() const;

    public:
        // Конструктор с параметрами
        BaseEntity(const std::string& name, int health);

        // Копирование и перемещение (правило пяти)
        BaseEntity(const BaseEntity& other);
        BaseEntity& operator=(const BaseEntity& other);
        BaseEntity(BaseEntity&& other) noexcept;
        BaseEntity& operator=(BaseEntity&& other) noexcept;

        // ВИРТУАЛЬНЫЙ ДЕСТРУКТОР (обязательно!)
        virtual ~BaseEntity();

        // Чисто виртуальные методы
        virtual void TakeDamage(int damage) = 0;
        virtual std::unique_ptr<BaseEntity> Clone() const = 0;

        // Виртуальный метод с реализацией (можно переопределить)
        virtual std::string Describe() const;

        // Геттеры (const-корректность)
        [[nodiscard]] int GetId() const { return m_id; }
        [[nodiscard]] const std::string& GetName() const { return m_name; }
        [[nodiscard]] int GetHealth() const { return m_health; }
        [[nodiscard]] bool IsAlive() const { return m_health > 0; }

        // Статический метод
        static int GetTotalCount() { return s_nextId - 1; }
    };

} // namespace game





