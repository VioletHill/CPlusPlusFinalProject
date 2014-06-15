//
//  ShoppingCard.h
//  FinalProject
//
//  Created by 邱峰 on 6/10/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__ShoppingCard__
#define __FinalProject__ShoppingCard__

#include <iostream>
#include <string>

using namespace std;
class ShoppingCard
{
public:
    
    double getRemain();
    void setRemain(double remain);
    
    void setShoppingCardId(string shoppingId);
    string getShoppingCardId();
    
public:
    void showInfo();

private:
    string shoppingCardId;
    double remain;              
};

#endif /* defined(__FinalProject__ShoppingCard__) */
