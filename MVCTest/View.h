//
//  View.h
//  MVCTest
//
//  Created by Salim Zayat on 12/10/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#ifndef View_h
#define View_h

#include "UIElements.h"
#include <string>
#include "Events.h"
#include "UIEvents.h"

class UserView : public EventDispatcher, public EventListener
{
public:
    UserView()
    {
        // This is just for proving purposes
        Button* pButton = new Button("Submit");
        pButton->AddListener(EventType::PRESS, this);
        
        m_pForm = new Form(pButton);
        m_pForm->AddElement("firstName", new TextField("John"));
        m_pForm->AddElement("lastName", new TextField("Smith"));
        m_pForm->AddElement("birthDate", new TextField("01/23/1973"));
    }
    
    std::string GetFirstName()  { return m_pForm->GetElement("firstName")->GetText(); }
    std::string GetLastName()   { return m_pForm->GetElement("lastName")->GetText(); }
    std::string GetBirthDate()  { return m_pForm->GetElement("birthDate")->GetText(); }
    
    
    void AddSubmitListener(EventListener* pListener)
    {
        AddListener(EventType::SUBMIT, pListener);
    }
    
    void OnEvent(Event* pEvent)
    {
        switch (pEvent->GetType())
        {
            case EventType::PRESS:
                Dispatch(new SubmitEvent(m_pForm));
                break;
            case EventType::USER_DATA_VALID:
                // awesome!  the user data validated.  Let's pop an alert saying as much.  Or go to the next page
                // or do something
                std::cout << "User data is all good." << std::endl;
                break;
            case EventType::USER_DATA_BIRTH_DATE_INVALID:
            case EventType::USER_DATA_FIRST_NAME_INVALID:
            case EventType::USER_DATA_LAST_NAME_INVALID:
                // highlight the bad element?
                // for now, just print something out as much
                std::cout << "invalid input.  check your values again" << std::endl;
                break;
            default:
                // ignore
                break;
        }
    }
    
    void TEST_PressButton()
    {
        std::cout << "TEST: pressing the button" << std::endl;
        m_pForm->GetButton()->Press();
    }
    
private:
    Form* m_pForm;
    
};

#endif /* View_h */
