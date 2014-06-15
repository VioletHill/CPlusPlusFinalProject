//
//  Product.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/10/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "Product.h"
#include "stdio.h"
#include <iomanip>


void Product::showProductInfo()
{
    cout<<setiosflags(ios::left)<<setw(20)<<productId;
    cout<<setiosflags(ios::left)<<setw(20)<<name;
    cout<<setiosflags(ios::left)<<setw(20)<<address;
    cout<<setiosflags(ios::left)<<setw(20)<<setprecision(2)<<price<<endl;

}

void Product::setProductId(string productId)
{
    this->productId=productId;
}

void Product::setName(string name)
{
    this->name=name;
}

void Product::setPrice(double price)
{
    this->price=price;
}

void Product::setAddress(string address)
{
    this->address=address;
}

string Product::getProductId()
{
    return this->productId;
}

string Product::getName()
{
    return this->name;
}

string Product::getAddress()
{
    return this->address;
}

double Product::getPrice()
{
    return this->price;
}