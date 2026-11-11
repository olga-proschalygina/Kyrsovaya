#pragma once

#include "entity.hpp"
#include "player.hpp"

namespace game
{

    class Boss : public BaseEntity
    {
    private:
        int m_damage;
        std::weak_ptr<Player> m_target;

    public:
        Boss(const std::string& name, int health, int damage, std::shared_ptr<Player> target);

        void TakeDamage(int damage) override;
        std::unique_ptr<BaseEntity> Clone() const override;

        // Переопределяем БЕЗ вызова базового метода (полностью меняем)
        std::string Describe() const override;

        void SetTarget(std::shared_ptr<Player> target) { m_target = target; }
        bool AttackTarget();
    };

} // namespace game





