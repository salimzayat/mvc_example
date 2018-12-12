//
//  main.cpp
//  MVCTest
//
//  Created by Salim Zayat on 12/9/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include "View.h"
#include "Model.h"
#include "Controller.h"


int main(int argc, const char * argv[]) {
    // create your view
    UserView* pView = new UserView();
    // create your model
    UserModel* pModel = new UserModel();
    // and the controller, which will wire everything up
    UserController* pController = new UserController(pModel, pView);
    // now, let's force a button press (we will just use the default data that has been provided)
    pView->TEST_PressButton();
    
    // delete
    delete (pView);
    delete (pModel);
    delete (pController);
    
    return 0;
}
