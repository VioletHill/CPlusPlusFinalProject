//
//  ShoppingCard.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/10/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "ShoppingCard.h"
#include <iomanip>

void ShoppingCard::setRemain(double remain)
{
    this->remain=remain;
}

void ShoppingCard::setShoppingCardId(string shoppingCardId)
{
    this->shoppingCardId=shoppingCardId;
}

double ShoppingCard::getRemain()
{
    return remain;
}

string ShoppingCard::getShoppingCardId()
{
    return shoppingCardId;
}

void ShoppingCard::showInfo()
{
    cout<<setiosflags(ios::left)<<setw(20)<<shoppingCardId;
    cout<<setiosflags(ios::left)<<setw(20)<<remain<<endl;
}
