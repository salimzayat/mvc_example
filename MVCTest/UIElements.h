//
//  UIElements.h
//  MVCTest
//
//  Created by Salim Zayat on 12/10/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#ifndef UIElements_h
#define UIElements_h

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <assert.h>
#include "Events.h"

class TextField
{
    // simple text field
public:
    TextField(std::string defaultText)
    : m_text(defaultText)
    {
        //
    }
    // get the current text
    std::string GetText() { return m_text; }
    
private:
    std::string m_text;
};

class Button : public EventDispatcher
{
    // simple button
public:
    Button(std::string label)
    : m_label(label)
    {
        //
    }
    // call on button press
    void Press()
    {
        Dispatch(new Event(EventType::PRESS));
    }
    
private:
    std::string m_label;
};

class Form
{
    // a simple From object
    // forms have some arbitrary number of form elements and a single submit button
public:
    Form(Button* pButton)
    : m_pButton(pButton)
    {
        
    }
    // add a form element with the given name
    void AddElement(std::string name, TextField* pElement)
    {
        assert(m_elements.find(name) == m_elements.end());
        m_elements[name] = pElement;
    }
    
    // get the element with that name
    TextField* GetElement(std::string name)
    {
        return m_elements[name];
    }
    
    // get the button
    Button* GetButton() { return m_pButton; }
    
private:
    std::map<std::string, TextField*> m_elements;
    Button* m_pButton;
};



#endif /* UIElements_h */
