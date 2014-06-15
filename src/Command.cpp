//
//  Command.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/10/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "Command.h"
#include "ProductManager.h"

 vector<ShoppingList*> Command::shoppingList;

void Command::split(std::string& s, std::string& delim,std::vector< std::string >* ret)
{
	size_t last = 0;
	size_t index=s.find_first_of(delim,last);
	while (index!=std::string::npos)
	{
		ret->push_back(s.substr(last,index-last));
		last=index+1;
		index=s.find_first_of(delim,last);
	}
	if (index-last>0)
	{
		ret->push_back(s.substr(last,index-last));
	}
}

void Command::showNotFoundCommand()
{
	cout<<"没有找到该命令"<<endl;
}

void Command::showShoppingList()
{
    ShoppingList* currentList=getCurrentShoppingList();
    currentList->showAllProdcutList();
}


ShoppingList* Command::getCurrentShoppingList()
{
    return shoppingList[shoppingList.size()-1];
}