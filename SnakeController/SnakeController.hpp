#pragma once

#include <list>
#include <memory>
#include <stdexcept>
#include <functional>

#include "IEventHandler.hpp"
#include "SnakeInterface.hpp"

class Event;
class IPort;

namespace Snake
{
class Segments;
class World;

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
    ~Controller();

    Controller(Controller const& p_rhs) = delete;
    Controller& operator=(Controller const& p_rhs) = delete;

    void receive(std::unique_ptr<Event> e) override;

private:
    IPort& m_displayPort;
    IPort& m_foodPort;
    IPort& m_scorePort;

    std::unique_ptr<World> m_world;
    std::unique_ptr<Segments> m_segments;

    void handleTimeoutInd();
    void handleDirectionInd(std::unique_ptr<Event>);
    void handleFoodInd(std::unique_ptr<Event>);
    void handleFoodResp(std::unique_ptr<Event>);
    void handlePauseInd(std::unique_ptr<Event>);

    void updateSegmentsIfSuccessfullMove(Position p);
    void addHeadSegment(Position p);
    void removeTailSegmentIfNotScored(Position p);
    void removeTailSegment();

    void updateFoodPosition(Position p, std::function<void()> clearPolicy);
    void sendClearOldFood();
    void sendPlaceNewFood(Position p);

    bool m_paused;
};

} // namespace Snake
