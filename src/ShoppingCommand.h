//
//  ShoppingCommand.h
//  FinalProject
//
//  Created by 邱峰 on 6/14/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__ShoppingCommand__
#define __FinalProject__ShoppingCommand__

#include <iostream>
#include "Command.h"
#include "ShoppingList.h"

typedef enum ShoppingCommandLine{
    kShoppingShowProduct,
    kShoppingShowShopping,
    kShoppingHelp,
    kShoppingNone,
    kShoppingRemove,
    kShoppingAdd,
}ShoppingCommandLine;

class ShoppingCommand: public Command
{
    
public:
    
    ShoppingCommand();
    
    virtual void runWithCommand(string commandLineStr);
    virtual void runWithCommand(ShoppingCommandLine commandLine,string secondPara="", string thirdPara="1");
    
private:                            //command function
    
    virtual void showHelp();
    
    virtual void addProductList(string productId, int count);
    virtual void addProductList(string productId, string count="1");
    
    virtual void removeProductList(string productId, int count);
    virtual void removeProductList(string productId, string count="1");
    
    
public:
    
    virtual void printStateCommand();
    virtual Command* changeState();
    
private:
    
    ShoppingCommandLine stringToShoppingCommand(string str);
    
};

#endif /* defined(__FinalProject__ShoppingCommand__) */
