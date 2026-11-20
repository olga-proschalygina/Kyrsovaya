#pragma once
#include "player.hpp"
#include "boss.hpp"
#include <memory>

namespace game {
    class GameWorld {
    private:
        std::shared_ptr<Player> m_player;
        std::unique_ptr<Boss> m_boss;
    public:
        GameWorld(std::shared_ptr<Player> player, std::unique_ptr<Boss> boss);
        void StartCombat();
    };
}