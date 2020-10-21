#include <iostream>


#include "Player.h"

using namespace std;

//Creates player pawn at 100hp
Player::Player() : m_health(100), m_x(0), m_y(0)
{

    cout << "Creating player (" << m_health << " HP)..." << endl << endl;

}

//Default destructor
Player::~Player()
{

}

int Player::getX()
{
    return m_x;
}

int Player::getY()
{
    return m_y;
}

void Player::setX(int x)
{
    m_x = x;
    //cout << "X is set to " << m_x << endl;
}

void Player::setY(int y)
{
    m_y = y;
    //cout << "Y is set to " << m_y << endl;
}

bool Player::isAlive() const
{
    if (m_health > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
