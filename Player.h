#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    public:

    Player();
    ~Player();

    //member functions
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

    bool isAlive() const;

    private:

    //attributes
    int m_health;
    int m_x;
    int m_y;
};

#endif // PLAYER_H_INCLUDED
