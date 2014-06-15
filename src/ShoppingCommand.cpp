//
//  ShoppingCommand.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/14/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "ShoppingCommand.h"
#include "CheckoutCommand.h"
#include "ProductManager.h"



ShoppingCommand::ShoppingCommand()
{
    showHelp();
    ShoppingList* newList=new ShoppingList();
    shoppingList.push_back(newList);
}

void ShoppingCommand::printStateCommand()
{
    cout<<"shopping=>";
}

Command* ShoppingCommand::changeState()
{
    delete this;
    return new CheckoutCommand();
}

void ShoppingCommand::runWithCommand(ShoppingCommandLine commandLine,string secondPara, string thirdPara)
{
    switch (commandLine) {
        case kShoppingShowProduct:
            ProductManager::sharedProductManager()->showAllProduct();
            break;
        case kShoppingHelp:
            showHelp();
            break ;
        case kShoppingAdd:
            addProductList(secondPara,thirdPara);
            break;
        case kShoppingRemove:
            removeProductList(secondPara, thirdPara);
            break;
        case kShoppingShowShopping:
            showShoppingList();
            break;
        case kShoppingNone:
            showNotFoundCommand();
            break;
        default:
            break;
    }
}


void ShoppingCommand::runWithCommand(string commandLineStr)
{
    vector<string> splitStr;
    string delim=" ";
    split(commandLineStr, delim, &splitStr);
    
    if (splitStr.size()==3) runWithCommand(stringToShoppingCommand(splitStr[0]),splitStr[1],splitStr[2]);
    else if (splitStr.size()==2) runWithCommand(stringToShoppingCommand(splitStr[0]),splitStr[1]);
    else if (splitStr.size()==1) runWithCommand(stringToShoppingCommand(splitStr[0]));
    else runWithCommand(kShoppingNone);
}

ShoppingCommandLine ShoppingCommand::stringToShoppingCommand(string str)
{
    if (str=="help") return kShoppingHelp;
    else if (str=="product") return kShoppingShowProduct;
    else if (str=="shopping") return kShoppingShowShopping;
    else if (str=="add") return kShoppingAdd;
    else if (str=="remove") return kShoppingRemove;
    else return kShoppingNone;
}


void ShoppingCommand::showHelp()
{
    printf("------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------欢迎进入购物模式--------------------------------------------\n");
    printf("help:                  显示帮助信息\n");
    printf("product:               显示所有商品信息\n");
    printf("shopping:              显示购物车信息\n");
    printf("add pruductId count:   将id为productId的商品加入购物车,count为可选,表示加入count个商品,默认为一个\n");
    printf("remove productId count:将id为productId的商品移除购物车,count为可选,表示加入count个商品,默认为一个\n");
    printf("chane:                 进入结账模式\n");
    printf("exit:                  退出程序\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("\n");
}

void ShoppingCommand::addProductList(string productId, int count)
{
    Product* product=ProductManager::sharedProductManager()->findProductById(productId);
    if (product==NULL)
    {
        printf("无法找到该商品\n");
    }
    else
    {
        ShoppingList* list=getCurrentShoppingList();
        list->addProduct(product,count);
        printf("商品添加成功  输入shopping可以产看购物车信息\n");
    }
}

void ShoppingCommand::addProductList(string productId, string countStr)
{
    int count=atoi(countStr.c_str());
    addProductList(productId, count);
}



void ShoppingCommand::removeProductList(string productId, int count)
{
    Product* product=ProductManager::sharedProductManager()->findProductById(productId);
    if (product==NULL)
    {
        printf("无法找到该商品\n");
    }
    else
    {
        ShoppingList* list=getCurrentShoppingList();
        list->removeProduct(product, count);
        printf("商品移除成功  输入shopping可以产看购物车信息\n");
    }

}

void ShoppingCommand::removeProductList(string productId, string countStr)
{
    int count=atoi(countStr.c_str());
    removeProductList(productId,count);
}

