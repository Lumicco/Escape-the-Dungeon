#include <iostream>
#include "Map.h"

using namespace std;

//Creates the map using number stored in m_mapSize
Map::Map()
{
    cout << "Creating map..." << endl << endl;

    char n = '?';

    for(int i = 0; i < m_mapSize; i++)
    {
        for(int j = 0; j < m_mapSize; j++)
        {
            m_floor[i][j] = n;
        }
    }
}

//Default destructor
Map::~Map()
{

}

//Reads icon of room
char Map::getFloor(int i, int j)
{
    return m_floor[i][j];
}

//Changes icon of room on map
void Map::setFloor(int i, int j, char n)
{
    m_floor[i][j] = n;
}

int Map::getSize()
{
    return m_mapSize;
}

//Prints map to screen
void Map::printMap()
{
   cout << "| ";
   for(int j = m_mapSize-1; j >= 0; j--)
    {
        for(int i = 0; i < m_mapSize; i++)
        {
           cout << " " << m_floor[i][j] << " " << " | ";
        }
        cout << endl << "| ";
    }
    cout << endl << endl;;
}
