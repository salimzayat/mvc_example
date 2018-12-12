//
//  ModelEvents.h
//  MVCTest
//
//  Created by Salim Zayat on 12/10/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#ifndef ModelEvents_h
#define ModelEvents_h
#include "Events.h"

class UserDataInvalidEvent : public Event
{
public:
    UserDataInvalidEvent(EventType t, std::string message)
    : Event(t)
    , m_message(message)
    {
        //
    }
    
private:
    std::string m_message;
    
};

#endif /* ModelEvents_h */
