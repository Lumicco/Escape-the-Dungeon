#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED

#include "Player.h"
#include "Map.h"
#include "Event.h"


class Session
{
    public:

    Session();
    ~Session();

    void menu();
    void event();

    void moveNorth();
    void moveSouth();
    void moveWest();
    void moveEast();
    void movePlayer(int x, int y);
    char getPlayerPosition();

    private:

    Player m_player;
    Map m_map;
    Event m_event;
};


#endif // SESSION_H_INCLUDED
