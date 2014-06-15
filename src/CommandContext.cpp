//
//  CommandContext.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/14/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "CommandContext.h"
#include "ShoppingCommand.h"
#include <iostream>
#include <fstream>
#include "MemberManager.h"
#include "ShoppingCardManager.h"
#include "ProductManager.h"

CommandContext* CommandContext::_sharedContext=NULL;

CommandContext* CommandContext::sharedContext()
{
    if (_sharedContext==NULL)
    {
        _sharedContext=new CommandContext();
    }
    return _sharedContext;
}

CommandContext::CommandContext()
{
    command=new ShoppingCommand();
}

void saveAll()
{
    MemberManager::sharedMemberManager()->save();
    ShoppingCardManager::sharedShoppingManager()->save();
    cout<<"文件member.txt 和 shoppingCard.txt已经被更新"<<endl;
}

void CommandContext::run()
{
    while (true)
    {
        string commandStr;
        command->printStateCommand();
        getline(cin, commandStr);
        if (commandStr=="exit") return ;
        else if (commandStr=="change") changeState();
        else if (commandStr=="save") saveAll();
        else command->runWithCommand(commandStr);
    }
}

void CommandContext::changeState()
{
    command=command->changeState();
}
