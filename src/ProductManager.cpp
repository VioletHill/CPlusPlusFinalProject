//
//  ProductManager.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/10/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "ProductManager.h"
#include "Const.h"
#include <iostream>
#include <fstream>


ProductManager* ProductManager::_sharedProductManager=NULL;

ProductManager* ProductManager::sharedProductManager()
{
   
    if (_sharedProductManager==NULL)
    {
        _sharedProductManager=new ProductManager();
    }
    return _sharedProductManager;
}

void ProductManager::purge()
{

}

void ProductManager::readAllProduct()
{
    string url=BASE_URL;
    url=url+"Product.txt";
    ifstream in(url);
    
    string productId;
    string productName;
    string productAddress;
    double price;
    
    while (in>>productId>>productName>>productAddress>>price)
    {
        Product* instance=new Product();
        instance->setProductId(productId);
        instance->setName(productName);
        instance->setPrice(price);
        instance->setAddress(productAddress);
        allProduct.push_back(instance);
    }
    
    in.close();

}

void ProductManager::showAllProduct()
{
    for (vector<Product*>::iterator it=allProduct.begin(); it<allProduct.end(); it++)
    {
        Product* instance=*it;
        instance->showProductInfo();
    }
}

Product* ProductManager::findProductById(string productId)
{
    for (vector<Product*>::iterator it=allProduct.begin(); it<allProduct.end(); it++)
    {
        Product* instance=*it;
        if (instance->getProductId()==productId) return instance;
    }
    return NULL;
}

