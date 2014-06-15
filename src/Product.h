//
//  ProductInstance.h
//  FinalProject
//
//  Created by 邱峰 on 6/10/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__Product__
#define __FinalProject__Product__

#include <iostream>
#include <string>

using namespace std;

class Product{

public:                                     //getter & setter
    void setProductId(string productId);
    void setName(string name);
    void setAddress(string address);
    void setPrice(double price);
    
    string getProductId();
    string getName();
    string getAddress();
    double getPrice();
    
public:
    void showProductInfo();
    
private:
    string productId;
    string name;
    string address;
    double price;

};

#endif /* defined(__FinalProject__Product__) */
