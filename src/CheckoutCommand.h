//
//  CheckoutCommand.h
//  FinalProject
//
//  Created by 邱峰 on 6/14/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__CheckoutCommand__
#define __FinalProject__CheckoutCommand__

#include <iostream>
#include "Command.h"

typedef enum CheckoutCommandLine{
    kCheckoutHelp,
    kCheckoutShoppingList,
    kCheckoutProduct,
    kCheckoutNone,
    kCheckoutPay,
}CheckoutCommandLine;

class CheckoutCommand: public Command
{
public:
    
    CheckoutCommand();
    
public:
    
    virtual void runWithCommand(CheckoutCommandLine command,string secondPara="", string thirdPara="1");
    virtual void runWithCommand(string commandStr);

    virtual void pay();
    virtual void showHelp();
    
public:
    virtual void printStateCommand();
    virtual Command* changeState();
    
private:
   CheckoutCommandLine stringToCheckoutCommand(string str);
};

#endif /* defined(__FinalProject__CheckoutCommand__) */
