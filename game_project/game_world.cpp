#include "game_world.hpp"
#include <iostream>

namespace game {
    GameWorld::GameWorld(std::shared_ptr<Player> player, std::unique_ptr<Boss> boss)
        : m_player(player), m_boss(std::move(boss)) {}

    void GameWorld::StartCombat() {
        if (!m_player || !m_boss) return;

        std::cout << "--- Бой начался! ---\n";

        // Босс атакует игрока (передаем ссылку)
        m_boss->AttackTarget(*m_player);

        // Игрок атакует босса
        int dmg = m_player->Attack();
        m_boss->TakeDamage(dmg);

        std::cout << "--------------------\n";
    }

    void GameWorld::PrintState() const {
        if (m_player) std::cout << "Игрок: " << m_player->GetName() << " (ОЗ: " << m_player->GetHealth() << ")\n";
        if (m_boss) std::cout << "Босс: " << m_boss->GetName() << " (ОЗ: " << m_boss->GetHealth() << ")\n";
    }
}