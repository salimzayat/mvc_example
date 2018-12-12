//
//  UIEvents.h
//  MVCTest
//
//  Created by Salim Zayat on 12/10/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#ifndef UIEvents_h
#define UIEvents_h


#include "Events.h"
#include "UIElements.h"

class TextFieldUpdateEvent : public Event
{
public:
    TextFieldUpdateEvent(std::string text)
    : Event(EventType::TEXT_FIELD_UPDATED)
    , m_text(text)
    {
        //
    }
    
    std::string GetText() { return m_text; }
    
private:
    std::string m_text;
};

class SubmitEvent : public Event
{
public:
    SubmitEvent(Form* pForm)
    : Event(EventType::SUBMIT)
    , m_pForm(pForm)
    {
        //
    }
    
    Form* GetForm() { return m_pForm; }
    
private:
    Form* m_pForm;
};


#endif /* UIEvents_h */
