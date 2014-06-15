//
//  GoldenPrice.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/15/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "GoldenPrice.h"


double GoldenPrice::getPrice(vector<Product*> products, vector<int> count)
{
    double result=0;
    for (int i=0; i<products.size(); i++)
    {
        Product* product=products[i];
        int countOfProduct=count[i];
        result+=countOfProduct*product->getPrice();
    }
    
    if (result>20)
    {
        result=result-(result-20)*0.1-(20-10)*0.05;
    }
    else if (result>10)
    {
        result=result-(result-2000)*0.05;
    }
    
    return result;
}

double GoldenPrice::getPointByPrice(double result)
{
    if (result>5000)
    {
        return 2*result;
    }
    else if (result>2000)
    {
        return 1.5*result;
    }
    else
    {
        return 2*result;
    }
}