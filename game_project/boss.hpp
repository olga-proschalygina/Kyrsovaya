#pragma once
#include "entity.hpp"

namespace game {
    class Player; // Предварительное объявление

    class Boss : public BaseEntity {
    private:
        int m_damage;
    public:
        Boss(const std::string& name, int health, int damage);
        Boss(const Boss& other);
        ~Boss() override;

        void TakeDamage(int damage) override;
        std::unique_ptr<BaseEntity> Clone() const override;
        std::string Describe() const override;

        // Босс атакует того, кого ему передали
        void AttackTarget(Player& target);
    };
}