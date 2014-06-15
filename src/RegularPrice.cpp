//
//  RegularPrice.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/15/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "RegularPrice.h"

double RegularPrice::getPrice(vector<Product*> products, vector<int> count)
{
    double result=0;
    for (int i=0; i<products.size(); i++)
    {
        Product* product=products[i];
        int countOfProduct=count[i];
        result+=countOfProduct*product->getPrice();
    }

    if (result>5000)
    {
        result=result-(result-5000)*0.1-(5000-2000)*0.05;
    }
    else if (result>2000)
    {
        result=result-(result-2000)*0.05;
    }
    
    return result;
}

double RegularPrice::getPointByPrice(double price)
{
    double point=0.5;
    return point*int(price);
}