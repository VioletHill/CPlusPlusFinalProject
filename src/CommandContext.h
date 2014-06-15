//
//  CommandContext.h
//  FinalProject
//
//  Created by 邱峰 on 6/14/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__CommandContext__
#define __FinalProject__CommandContext__

#include <iostream>

#include "Command.h"

class CommandContext
{
public:
    
    CommandContext();
    
    static CommandContext* sharedContext();
    
    void changeState();
    void run();
    
private:
    Command* command;
    static CommandContext* _sharedContext;
};

#endif /* defined(__FinalProject__CommandContext__) */
