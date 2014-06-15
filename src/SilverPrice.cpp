//
//  SilverPrice.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/15/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "SilverPrice.h"

double SilverPrice::getPrice(vector<Product*> products, vector<int> count)
{
    double result=0;
    for (int i=0; i<products.size(); i++)
    {
        Product* product=products[i];
        int countOfProduct=count[i];
        result+=countOfProduct*product->getPrice();
    }
    
    if (result>2000)
    {
        result=result-(result-2000)*0.15-(2000-1000)*0.1-1000*0.05;
    }
    else if (result>1000)
    {
        result=result-(2000-1000)*0.1-1000*0.05;
    }
    else
    {
        result=result-1000*0.5;
    }
    
    return result;
}

double SilverPrice::getPointByPrice(double result)
{
    if (result>5000)
    {
        return 1.8*result;
    }
    else if (result>2000)
    {
        return 1.5*result;
    }
    else
    {
        return 1.2*result;
    }

}