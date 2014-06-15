//
//  ProductList.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/14/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "ShoppingList.h"
#include <iomanip>

void ShoppingList::addProduct(Product* product, int countOfProduct)
{
    int index=isExistProduct(product);
    if (index==-1)
    {
        productList.push_back(product);
        count.push_back(countOfProduct);
    }
    else
    {
        count[index]+=countOfProduct;
    }
}

void ShoppingList::addProduct(Product* product)
{
    addProduct(product, 1);
}

int ShoppingList::isExistProduct(Product* product)
{
    for (int i=0; i<productList.size(); i++)
    {
        Product* productInList=productList[i];
        if (productInList->getProductId()==product->getProductId()) return i;
    }
    return -1;
}

void ShoppingList::showAllProdcutList()
{
    if (productList.empty())
    {
        printf("亲～～购物车是空的哦～～\n");
        return ;
    }
    for (int i=0; i<productList.size(); i++)
    {
        if (count[i]==0) continue;
        Product* product=productList[i];
        cout<<setiosflags(ios::left)<<setw(20)<<product->getProductId();
        cout<<setiosflags(ios::left)<<setw(20)<<product->getName();
        cout<<setiosflags(ios::left)<<setw(20)<<count[i]<<endl;
    }
}

void ShoppingList::removeProduct(Product* product, int countOfProduct)
{
    int index=isExistProduct(product);
    if (index==-1)
    {
        return ;
    }
    else
    {
        count[index]-=countOfProduct;
        count[index]=max(0,count[index]);
    }
}

void ShoppingList::removeProduct(Product* product)
{
    removeProduct(product,1);
}

vector<Product*> ShoppingList::getProductList()
{
    return productList;
}

vector<int> ShoppingList::getCount()
{
    return count;
}