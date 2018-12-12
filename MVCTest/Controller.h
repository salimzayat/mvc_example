//
//  Controller.h
//  MVCTest
//
//  Created by Salim Zayat on 12/10/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#ifndef Controller_h
#define Controller_h

#include "Model.h"
#include "View.h"
#include "Events.h"

class UserController : public EventListener
{
public:
    UserController(UserModel* pModel, UserView* pView)
    : m_pModel(pModel)
    , m_pView(pView)
    {
        // set up your listeners
        m_pView->AddSubmitListener(this);
        m_pModel->AddListener(EventType::USER_DATA_FIRST_NAME_INVALID, m_pView);
        m_pModel->AddListener(EventType::USER_DATA_LAST_NAME_INVALID, m_pView);
        m_pModel->AddListener(EventType::USER_DATA_BIRTH_DATE_INVALID, m_pView);
        m_pModel->AddListener(EventType::USER_DATA_VALID, m_pView);
    }
    
    
    virtual void OnEvent(Event* pEvent) override
    {
        SubmitEvent* pSubmitEvent = (SubmitEvent*)pEvent;
        // get the form
        Form* pForm = pSubmitEvent->GetForm();
        // and update the model
        m_pModel->SetFirstName(pForm->GetElement("firstName")->GetText());
        m_pModel->SetLastName(pForm->GetElement("lastName")->GetText());
        m_pModel->SetBirthDate(pForm->GetElement("birthDate")->GetText());
        m_pModel->Validate();
    }
    
private:
    UserModel* m_pModel;
    UserView* m_pView;
};

#endif /* Controller_h */
