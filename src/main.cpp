//
//  main.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/10/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include <iostream>

#include "ProductManager.h"
#include "MemberManager.h"
#include "ShoppingCardManager.h"
#include "CommandContext.h"


int main(int argc, const char * argv[])
{

    // insert code here...
    ProductManager::sharedProductManager()->readAllProduct();
    
//    std::cout<<std::endl;
    
    MemberManager::sharedMemberManager()->readAllMember();
    
    ShoppingCardManager::sharedShoppingManager()->readAllShoppingCard();
    
    CommandContext::sharedContext()->run();
    
    return 0;
}

