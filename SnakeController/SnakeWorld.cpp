#include "SnakeWorld.hpp"

namespace Snake
{

World::World(std::pair<int, int> dimension, Position p)
    : m_foodPosition(p),
      m_dimension(dimension)
{}

void World::setFoodPosition(Position p)
{
    m_foodPosition = p;
}

Position World::getFoodPosition() const
{
    return m_foodPosition;
}

bool World::contains(Position p) const
{
    return p.x>= 0 and p.x < m_dimension.first and p.y >= 0 and p.y < m_dimension.second;
}

} // namespace Snake
