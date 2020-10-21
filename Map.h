#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <vector>

class Map
{
    public:

    Map();
    ~Map();

    char getFloor(int i, int j);
    void setFloor(int i, int j, char n);

    void printMap();

    const static int m_mapSize = 5;
    int getSize();

    private:

    //vector<vector<int>> floor;
    char m_floor[m_mapSize][m_mapSize];

};

#endif // MAP_H_INCLUDED
