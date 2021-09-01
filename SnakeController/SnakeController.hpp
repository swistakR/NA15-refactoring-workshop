#pragma once

#include <list>
#include <memory>
#include <stdexcept>

#include "IEventHandler.hpp"
#include "SnakeInterface.hpp"

class Event;
class IPort;

namespace Snake
{
struct ConfigurationError : std::logic_error
{
    ConfigurationError();
};

struct UnexpectedEventException : std::runtime_error
{
    UnexpectedEventException();
};

class Controller : public IEventHandler
{
public:
    Controller(IPort& p_displayPort, IPort& p_foodPort, IPort& p_scorePort, std::string const& p_config);

    Controller(Controller const& p_rhs) = delete;
    Controller& operator=(Controller const& p_rhs) = delete;

    void receive(std::unique_ptr<Event> e) override;
    void direction(char d);
    void constructorIf(std::string const& p_config);
    void functionIF2(bool requestedFoodCollidedWithSnake, int a,int b);
    bool autoChoose(int x, int y);
private:
    struct Segment
    {
        int x;
        int y;
        int ttl;
    };
    void functionIF2(Segment newHead);
    void functionIF(Segment newHead);
    //void if1(Segment newHead);
    void segmentttl(Segment &segment);
    IPort& m_displayPort;
    IPort& m_foodPort;
    IPort& m_scorePort;
    bool lost = false;
    std::pair<int, int> m_mapDimension;
    std::pair<int, int> m_foodPosition;

    Direction m_currentDirection;
    std::list<Segment> m_segments;
};

} // namespace Snake
