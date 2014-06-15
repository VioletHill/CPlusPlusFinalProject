//
//  ProductsPrice.h
//  FinalProject
//
//  Created by 邱峰 on 6/15/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__ProductsPrice__
#define __FinalProject__ProductsPrice__

#include <iostream>
#include "Product.h"
#include <vector>

using namespace std;

class ProductsPrice
{
    
public:
    virtual double getPrice(vector<Product*> products, vector<int> count)=0;
    virtual double getPointByPrice(double price)=0;

};

#endif /* defined(__FinalProject__ProductsPrice__) */
