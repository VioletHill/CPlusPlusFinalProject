//
//  ProductList.h
//  FinalProject
//
//  Created by 邱峰 on 6/14/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__ProductList__
#define __FinalProject__ProductList__

#include <iostream>
#include <string>
#include <vector>
#include "Product.h"

using namespace::std;

class ShoppingList
{
    
public:
    
    void addProduct(Product* product, int sum);
    void addProduct(Product* product);
    
    void removeProduct(Product* product, int sum);
    void removeProduct(Product* product);
    
    void showAllProdcutList();
    
    vector<Product*> getProductList();
    vector<int> getCount();
    
private:

    int isExistProduct(Product* product);       //return index of product. if not exist return -1
    
private:
    
    vector<Product*> productList;
    vector<int> count;
    
};

#endif /* defined(__FinalProject__ProductList__) */
