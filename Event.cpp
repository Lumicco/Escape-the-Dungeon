#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Event.h"

using namespace std;


Event::Event()
{

}

//default destructor
Event::~Event()
{

}

//sets pointer to m_map/session.cpp
void Event::setMapPtr(Map* map_ptr)
{
    m_map_ptr = map_ptr;
}

//creates event at random position
void Event::createEvent()
{
    //to mark which numbers have been generated
    int randX[m_map_ptr->m_mapSize];
    int randY[m_map_ptr->m_mapSize];
    int position(0);

    //set all values to 0
    while (position <= m_map_ptr->m_mapSize)
    {
        randX[position] = 0;
        randY[position] = 0;
        position++;
    }

    //creates fixed number of events on map
    int i = 1;
    while (i <= 3)
    {
        int eventX = rand() % m_map_ptr->m_mapSize;
        int eventY = rand() % m_map_ptr->m_mapSize;

        //mark number as generated
        if (randX[eventX] == 0)
        {
            randX[eventX] = 1;
        }
        else if (randY[eventY] == 0)
        {
            randY[eventY] = 1;
        }

        //does not create event if event = player starting position
        if(m_map_ptr->getFloor(eventX, eventY) != 'X')
        {
            m_map_ptr->setFloor(eventX,eventY,'!');
            i++;
        }
    }
    m_map_ptr->printMap();
}

//creates random event
void Event::triggerEvent()
{
    //generate random number between 1 and 3 (3 = number of possible events)
    srand(time(0));
    int roll = rand() % 3 + 1;
    switch(roll)
    {
        //Exit event
        case 1 :
            {
                cout << "       _________          _________ " << endl
                     << "      |_|_|_|__|_________|__|_|_|_|" << endl
                     << "      |_|_  |               |  _|_|" << endl
                     << "      |_|_|  |  ( )   ( )  |  |_|_|" << endl
                     << "             |             |       " << endl
                     << "             |      |      |       " << endl
                     << "              |_         _|        " << endl
                     << "                |_     _|          " << endl
                     << "                  |_|_|            " << endl << endl;

                cout << "You run into a monster." << endl
                     << "Upon closer inspection you see that it's guarding a door." << endl << endl
                     << "IF YOU WANT TO GET PAST ME YOU'LL HAVE TO DEFEAT ME !" << endl << endl
                     << "The monster seems unlikely to budge without a fight." << endl
                     << "What are you going to do ?" << endl
                     << "-> fight" << endl
                     << "-> flee" << endl << endl;

                string choiceMon;
                getline(cin, choiceMon);
                cout << endl;

                if (choiceMon == "fight")
                {
                    cout << "You don't have a weapon." << endl << endl;
                }
                else
                {
                    return;
                }

                break;
            }

        //Treasure event
        case 2 :
            {
                cout << "         _________________   " << endl
                     << "        /_________________\\  " << endl
                     << "       /___________________\\ " << endl
                     << "      |=======|=| |=|=======|" << endl
                     << "      |_______| |X| |_______|" << endl
                     << "      |________\\___/________|" << endl
                     << "      |_____________________|" << endl
                     << "      |_____________________|" << endl << endl;

                cout << "There's a chest in the corner." << endl << endl;
                cout << "What are you going to do ?" << endl
                     << "-> open it" << endl
                     << "-> leave it" << endl << endl;

                string choiceChest;
                getline(cin, choiceChest);
                cout << endl;

                if (choiceChest == "open it")
                {
                    cout << "It's locked. Use key ?" << endl << endl;

                    string choice2;
                    getline(cin, choice2);
                    cout << endl;

                    if (choice2 == "yes")
                    {
                        cout << "You don't have any keys." << endl << endl;
                    }
                    else
                    {
                        return;
                    }
                    }
                else
                {
                    return;
                }
                break;
            }

        //Key event
        case 3 :
            {
                cout << "        _   _      " << endl
                     << "       | \\_/ |   __" << endl
                     << "      ( o ^ o ) // " << endl
                     << "      (  >F<  )_/  " << endl
                     << "        0---0      " << endl << endl;

                cout << "There's a furry little creature nibbling on a key." << endl
                     << "You try to take the key but it runs away." << endl << endl
                     << "IF YER WANT ME TOY YER'LL 'AVE TER PLAY A GAME WIV ME!" << endl << endl
                     << "What are you going to do ?" << endl
                     << "-> play" << endl
                     << "-> leave" << endl
                     << "-> insult Laura's choice of dialect" << endl << endl;

                string choiceKey;
                getline(cin, choiceKey);
                cout << endl;

                if (choiceKey == "play")
                {
                    cout << "THIS IS GONNA BE FUN! AH DON'T GET MANY VISITORS YA KNOW." << endl
                         << "SORRY MATE. LAURA DIDN'T 'AVE TIME TER THINK OF ANYTHING YET!" << endl << endl;
                }
                else if (choiceKey == "insult Laura's choice of dialect")
                {
                    cout << "Oh no! Laura came to your house and killed you in real life!" << endl
                         << "You shouldn't have done that, that was pretty stupid." << endl << endl;

                    string end;
                    cin >> end;
                }
                else
                {
                    return;
                }

                break;
            }
    }

}
