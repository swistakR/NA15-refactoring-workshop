#pragma once

#include <list>

#include "SnakeInterface.hpp"

namespace Snake
{

class Segments
{
public:
    Segments(Direction direction);

    void addSegment(Position p);
    bool isCollision(Position p) const;
    void addHead(Position p);
    Position nextHead() const;
    std::pair<int, int> removeTail();
    void updateDirection(Direction newDirection);
private:
    Direction m_headDirection;
    std::list<Position> m_segments;
};

} // namespace Snake
