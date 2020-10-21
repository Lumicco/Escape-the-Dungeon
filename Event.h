#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include "Map.h"


class Event
{
    public:

    Event();
    ~Event();

    void triggerEvent();
    void createEvent();
    void setMapPtr(Map* map_ptr);

    private:

    Map* m_map_ptr;
    int m_arr[100]; //stores which events have already been triggered
};

#endif // EVENT_H_INCLUDED
