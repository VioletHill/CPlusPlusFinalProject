//
//  GoldenPrice.h
//  FinalProject
//
//  Created by 邱峰 on 6/15/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__GoldenPrice__
#define __FinalProject__GoldenPrice__

#include <iostream>
#include "ProductsPrice.h"

class GoldenPrice : public ProductsPrice
{
public:
    virtual double getPrice(vector<Product*> products, vector<int> count);
    virtual double getPointByPrice(double price);
};

#endif /* defined(__FinalProject__GoldenPrice__) */
