#pragma once

#include <utility>
#include "SnakeInterface.hpp"
namespace Snake
{

class World
{
public:
    World(std::pair<int, int> dimension, Position p);

    void setFoodPosition(Position p);
    Position getFoodPosition() const;

    bool contains(Position p) const;

private:
    Position m_foodPosition;
    std::pair<int, int> m_dimension;
};

} // namespace Snake
