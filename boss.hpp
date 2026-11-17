#pragma once

#include "entity.hpp"
#include "player.hpp"
#include <string>
#include <memory>

namespace game
{

    class Boss : public BaseEntity
    {
    private:
        int m_damage;
        std::weak_ptr<Player> m_target;

    public:
        Boss(const std::string& name, int health, int damage, std::shared_ptr<Player> target);

        // Конструктор копирования (нужен для Clone)
        Boss(const Boss& other);

        ~Boss() override = default;

        void ReceiveDamage(int damage) override;
        std::unique_ptr<BaseEntity> Clone() const override;
        std::string Describe() const override;
        std::string GetTypeName() const override { return "Босс"; }
        std::string GetAttackMessage() const override { return "Босс атакует!"; }

        void SetTarget(std::shared_ptr<Player> target);
        void AttackTarget();
    };

} // namespace game