#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Session.h"

using namespace std;

//Opens a session, moves player to random starting position, prints map marking position
Session::Session()
{
    cout << "Creating game session..." << endl << endl;

    srand(time(0));
    int startingPositionX = rand() % m_map.m_mapSize;
    int startingPositionY = rand() % m_map.m_mapSize;
    cout << "Player starts at position " << startingPositionX << " " << startingPositionY << " : " << endl << endl;
    movePlayer(startingPositionX,startingPositionY);

    m_event.setMapPtr(&m_map);
    m_event.createEvent();

    cout << "You're trapped in a cave and have to find your way out !" << endl << endl;
}

//Default destructor
Session::~Session()
{

}

//Opens UI
void Session::menu()
{
    string choice;
    while (choice != "quit")
    {
        cout << "What would you like to do ?" << endl
            << "-> move north" << endl
            << "-> move south" << endl
            << "-> move west" << endl
            << "-> move east" << endl
            << "-> view map" << endl
            << endl;


        getline(cin, choice);
        cout << endl;

        if (choice == "move north")
        {
            Session::moveNorth();
        }
        else if (choice == "move south")
        {
            Session::moveSouth();
        }

        else if (choice == "move west")
        {
            Session::moveWest();
        }

        else if (choice == "move east")
        {
            Session::moveEast();
        }

        else if (choice == "view map")
        {
            m_map.printMap();
        }

        else if (choice == "xyzzy")
        {
            cout << "you are in a maze of twisty little passages, all alike" << endl << endl;
        }
    }
}

//Moves player North by one room, marks new position, changes icon of old position
void Session::moveNorth()
{
    //make sure that player doesnt leave the map
    if (m_player.getY() == m_map.getSize()-1)
    {
        cout << "The path is blocked." << endl << endl;
        return;
    }



    m_map.setFloor(m_player.getX(),m_player.getY(),char(24));
    m_player.setY(m_player.getY() + 1);

    //checks room content, creates event if room marked with '!'
    if (Session::getPlayerPosition() == '!')
    {
        m_event.triggerEvent();
    }
    else
    {
        cout << "There's nothing here." << endl << endl;
    }

    m_map.setFloor(m_player.getX(),m_player.getY(),'X');
}


//Moves player South by one room, marks new position, changes icon of old position
void Session::moveSouth()
{
    //make sure that player doesnt leave the map
    if (m_player.getY() == 0)
    {
        cout << "The path is blocked." << endl << endl;
        return;
    }

    m_map.setFloor(m_player.getX(),m_player.getY(),char(25));
    m_player.setY(m_player.getY() - 1);

    //checks room content
    if (Session::getPlayerPosition() == '!')
    {
        m_event.triggerEvent();
    }
    else
    {
        cout << "There's nothing here." << endl << endl;
    }

    m_map.setFloor(m_player.getX(),m_player.getY(),'X');
}

//Moves player West by one room, marks new position, changes icon of old position
void Session::moveWest()
{
    //make sure that player doesnt leave the map
    if (m_player.getX() == 0)
    {
        cout << "The path is blocked." << endl << endl;
        return;
    }

    m_map.setFloor(m_player.getX(),m_player.getY(),char(27));
    m_player.setX(m_player.getX() - 1);

    //checks room content
    if (Session::getPlayerPosition() == '!')
    {
        m_event.triggerEvent();
    }
    else
    {
        cout << "There's nothing here." << endl << endl;
    }

    m_map.setFloor(m_player.getX(),m_player.getY(),'X');
}

//Moves player East by one room, marks new position, changes icon of old position
void Session::moveEast()
{
    //make sure that player doesnt leave the map
    if (m_player.getX() == m_map.getSize()-1)
    {
        cout << "The path is blocked." << endl << endl;
        return;
    }

    m_map.setFloor(m_player.getX(),m_player.getY(),char(26));
    m_player.setX(m_player.getX() + 1);

    //checks room content
    if (Session::getPlayerPosition() == '!')
    {
        m_event.triggerEvent();
    }
    else
    {
        cout << "There's nothing here." << endl << endl;
    }

    m_map.setFloor(m_player.getX(),m_player.getY(),'X');
}

//Moves the player, reprints the map marking new position
void Session::movePlayer(int x, int y)
{
    m_player.setX(x);
    m_player.setY(y);


    m_map.setFloor(x,y,'X');
    //m_map.printMap();

}

char Session::getPlayerPosition()
{
    return m_map.getFloor(m_player.getX(), m_player.getY());
}

