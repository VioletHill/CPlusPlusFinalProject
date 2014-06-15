//
//  Product.h
//  FinalProject
//
//  Created by 邱峰 on 6/10/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__ProductManager__
#define __FinalProject__ProductManager__

#include <iostream>
#include <string>
#include <vector>
#include "Product.h"

using namespace std;

class ProductManager
{
public:
    static ProductManager* sharedProductManager();
    static void purge();
    
    void readAllProduct();
    void showAllProduct();
    
    //void save();
    
    Product* findProductById(string productId);
    
private:
    static ProductManager* _sharedProductManager;
    vector<Product*> allProduct;
};


#endif /* defined(__FinalProject__ProductManager__) */
