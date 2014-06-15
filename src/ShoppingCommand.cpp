//
//  ShoppingCommand.cpp
//  FinalProject
//
//  Created by ��� on 6/14/14.
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
    printf("------------------------------------��ӭ���빺��ģʽ--------------------------------------------\n");
    printf("help:                  ��ʾ������Ϣ\n");
    printf("product:               ��ʾ������Ʒ��Ϣ\n");
    printf("shopping:              ��ʾ���ﳵ��Ϣ\n");
    printf("add pruductId count:   ��idΪproductId����Ʒ���빺�ﳵ,countΪ��ѡ,��ʾ����count����Ʒ,Ĭ��Ϊһ��\n");
    printf("remove productId count:��idΪproductId����Ʒ�Ƴ����ﳵ,countΪ��ѡ,��ʾ����count����Ʒ,Ĭ��Ϊһ��\n");
    printf("chane:                 �������ģʽ\n");
    printf("exit:                  �˳�����\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("\n");
}

void ShoppingCommand::addProductList(string productId, int count)
{
    Product* product=ProductManager::sharedProductManager()->findProductById(productId);
    if (product==NULL)
    {
        printf("�޷��ҵ�����Ʒ\n");
    }
    else
    {
        ShoppingList* list=getCurrentShoppingList();
        list->addProduct(product,count);
        printf("��Ʒ��ӳɹ�  ����shopping���Բ������ﳵ��Ϣ\n");
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
        printf("�޷��ҵ�����Ʒ\n");
    }
    else
    {
        ShoppingList* list=getCurrentShoppingList();
        list->removeProduct(product, count);
        printf("��Ʒ�Ƴ��ɹ�  ����shopping���Բ������ﳵ��Ϣ\n");
    }

}

void ShoppingCommand::removeProductList(string productId, string countStr)
{
    int count=atoi(countStr.c_str());
    removeProductList(productId,count);
}

