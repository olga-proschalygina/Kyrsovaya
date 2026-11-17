#pragma once

#include <stdexcept>
#include <string>

namespace game
{

    class GameRuleException : public std::runtime_error
    {
    public:
        explicit GameRuleException(const std::string& message)
            : std::runtime_error(message)
        {}
    };

} // namespace game