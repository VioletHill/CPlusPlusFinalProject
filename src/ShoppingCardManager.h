//
//  ShoppingCardManager.h
//  FinalProject
//
//  Created by 邱峰 on 6/15/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__ShoppingCardManager__
#define __FinalProject__ShoppingCardManager__

#include <iostream>
#include <vector>
#include "ShoppingCard.h"

using namespace::std;

class ShoppingCardManager
{
    
public:
    static ShoppingCardManager* sharedShoppingManager();
    
    void readAllShoppingCard();
    void showAllShoppingCard();
    
    void save();
    
    ShoppingCard* findShoppingCardById(string shoppingCardId);
    
private:
    
    static ShoppingCardManager* _sharedShoppingCardManager;
    
    vector<ShoppingCard*> allShoppingCard;
};

#endif /* defined(__FinalProject__ShoppingCardManager__) */
