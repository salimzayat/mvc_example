//
//  Events.h
//  MVCTest
//
//  Created by Salim Zayat on 12/10/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#ifndef Events_h
#define Events_h

#include <map>
#include <list>

enum EventType
{
    // form level event
    SUBMIT,
    // view level event
    TEXT_FIELD_UPDATED,
    PRESS,
    // model level event
    USER_DATA_VALID,
    USER_DATA_FIRST_NAME_INVALID,
    USER_DATA_LAST_NAME_INVALID,
    USER_DATA_BIRTH_DATE_INVALID    
};

class Event
{
    // generic Event class with a single GetType method
public:
    Event(EventType t)
    : m_type(t)
    {
        //
    }
    
    EventType GetType() { return m_type; }
    
protected:
    EventType m_type;
};


class EventListener
{
    // an interface to define an event listener
public:
    // event callback
    virtual void OnEvent(Event* pEvent) = 0;
};


class EventDispatcher
{
    // simple event dispatcher class
public:
    // add a listener for the given event type
    void AddListener(EventType t, EventListener* pListener)
    {
        if (m_listeners.find(t) == m_listeners.end())
        {
            std::list<EventListener*> listeners;
            m_listeners[t] = listeners;
        }
        m_listeners[t].push_back(pListener);
    }
    
    // remove the listener for the given event type
    void RemoveListener(EventType t, EventListener* pListener)
    {
        m_listeners[t].remove(pListener);
    }
    
    // dispatch the given event and delete immediately afterward
    void Dispatch(Event* pEvent)
    {
        std::list<EventListener*> listeners = m_listeners[pEvent->GetType()];
        for (EventListener* pListener : listeners)
        {
            pListener->OnEvent(pEvent);
        }
        delete pEvent;
    }
    
private:
    std::map<EventType, std::list<EventListener*>> m_listeners;
    
};


#endif /* Events_h */
