//
//  SilverPrice.h
//  FinalProject
//
//  Created by 邱峰 on 6/15/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__SilverPrice__
#define __FinalProject__SilverPrice__

#include <iostream>
#include "ProductsPrice.h"

class SilverPrice : public ProductsPrice
{
    
public:
    virtual double getPrice(vector<Product*> products, vector<int> count);
    virtual double getPointByPrice(double price);
};

#endif /* defined(__FinalProject__SilverPrice__) */
