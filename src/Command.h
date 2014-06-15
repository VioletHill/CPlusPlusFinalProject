//
//  Command.h
//  FinalProject
//
//  Created by 邱峰 on 6/10/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__Command__
#define __FinalProject__Command__

#include <iostream>
#include <string>
#include <vector>
#include "ShoppingList.h"

using namespace std;

class Command
{
    
public:
    
    virtual void runWithCommand(string commandLineStr)=0;
    
public:
    
    virtual void showHelp()=0;
    
public:

    virtual void printStateCommand()=0;
    virtual Command* changeState()=0;          //state designer pattern
    
    void showShoppingList();
    void showNotFoundCommand();
    
public:
    
    void split(std::string& s, std::string& delim,std::vector< std::string >* ret);
    
protected:
    
    ShoppingList* getCurrentShoppingList();
    
protected:
    
    static vector<ShoppingList*> shoppingList;
    
};

#endif /* defined(__FinalProject__Command__) */
