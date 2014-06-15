//
//  ShoppingCardManager.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/15/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "ShoppingCardManager.h"
#include "Const.h"
#include <fstream>

ShoppingCardManager* ShoppingCardManager::_sharedShoppingCardManager=NULL;

ShoppingCardManager* ShoppingCardManager::sharedShoppingManager()
{
    if (_sharedShoppingCardManager==NULL)
    {
        _sharedShoppingCardManager=new ShoppingCardManager();
    }
    return _sharedShoppingCardManager;
}

void ShoppingCardManager::readAllShoppingCard()
{
    string url=BASE_URL;
    url=url+"shoppingcard.txt";
    
    ifstream in(url);
    
    string shoppingCardId;
    double shoppingCardRemain;
    
    while (in>>shoppingCardId>>shoppingCardRemain)
    {
        ShoppingCard* shoppingCard=new ShoppingCard();
        shoppingCard->setShoppingCardId(shoppingCardId);
        shoppingCard->setRemain(shoppingCardRemain);
        allShoppingCard.push_back(shoppingCard);
    }
    
    in.close();
}

void ShoppingCardManager::showAllShoppingCard()
{
    for (vector<ShoppingCard*>::iterator it=allShoppingCard.begin(); it<allShoppingCard.end(); it++)
    {
        ShoppingCard* shoppingCard=*it;
        shoppingCard->showInfo();
    }
}

ShoppingCard* ShoppingCardManager::findShoppingCardById(string id)
{
    for (vector<ShoppingCard*>::iterator it=allShoppingCard.begin(); it<allShoppingCard.end(); it++)
    {
        ShoppingCard* shoppingCard=*it;
        if (shoppingCard->getShoppingCardId()==id) return shoppingCard;
    }
    return NULL;
}

void ShoppingCardManager::save()
{
    string url=BASE_URL;
    url=url+"shoppingcard.txt";
    ofstream out(url);
    
    for (vector<ShoppingCard*>::iterator it=allShoppingCard.begin(); it<allShoppingCard.end(); it++)
    {
        ShoppingCard* shoppingCard=*it;
        out<<shoppingCard->getShoppingCardId()<<' '<<shoppingCard->getRemain()<<endl;
    }
    
    out.close();
}