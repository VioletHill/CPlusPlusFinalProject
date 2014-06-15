//
//  CheckoutCommand.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/14/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "CheckoutCommand.h"
#include "ShoppingCommand.h"
#include "ProductManager.h"
#include "ProductsPrice.h"
#include "MemberManager.h"
#include "RegularPrice.h"
#include "GoldenPrice.h"
#include "SilverPrice.h"
#include "ShoppingCardManager.h"
#include <iostream>
#include <fstream>
#include "CommandContext.h"
#include <stdio.h>

CheckoutCommand::CheckoutCommand()
{
    showHelp();
}

void CheckoutCommand::showHelp()
{
    printf("----------------------------------------------------------------------------------------\n");
    printf("------------------------------------欢迎进入结账模式---------------------------------------\n");
    printf("help:                  显示帮助信息\n");
    printf("product:               显示所有商品信息\n");
    printf("shopping:              显示购物车信息\n");
    printf("exit:                  退出程序\n");
    printf("pay:                   开始支付\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("\n");
}

Command* CheckoutCommand::changeState()
{
    delete this;
    return new ShoppingCommand();
}

void CheckoutCommand::printStateCommand()
{
    cout<<"checkout=>";
}

void CheckoutCommand::runWithCommand(CheckoutCommandLine commandLine,string secondPara, string thirdPara)
{
    switch (commandLine) {
        case kCheckoutHelp:
            showHelp();
            break;
        case kCheckoutNone:
            showNotFoundCommand();
            break;
        case kCheckoutShoppingList:
            showShoppingList();
            break;
        case kCheckoutProduct:
            ProductManager::sharedProductManager()->showAllProduct();
            break;
        case kCheckoutPay:
            pay();
            CommandContext::sharedContext()->changeState();
            break ;
        default:
            break;
    }
}

void CheckoutCommand::runWithCommand(string commandLineStr)
{
    vector<string> splitStr;
    string delim=" ";
    split(commandLineStr, delim, &splitStr);
    
    if (splitStr.size()==3) runWithCommand(stringToCheckoutCommand(splitStr[0]),splitStr[1],splitStr[2]);
    else if (splitStr.size()==2) runWithCommand(stringToCheckoutCommand(splitStr[0]),splitStr[1]);
    else if (splitStr.size()==1 && splitStr[0]!="change") runWithCommand(stringToCheckoutCommand(splitStr[0]));
    else runWithCommand(kCheckoutNone);
}

CheckoutCommandLine CheckoutCommand::stringToCheckoutCommand(string str)
{
    if (str=="help") return kCheckoutHelp;
    else if (str=="shopping") return kCheckoutShoppingList;
    else if (str=="product") return kCheckoutProduct;
    else if (str=="pay") return kCheckoutPay;
    return kCheckoutNone;
}

ProductsPrice* getProductsPrice()
{
    printf("请输入会员卡ID,输入all可以查看所有的会员卡\n");
    while (true)
    {
        string memberID;
        cin>>memberID;
        if (memberID=="all")
        {
            MemberManager::sharedMemberManager()->showAllMember();
            continue;
        }
        else
        {
            Member* member=MemberManager::sharedMemberManager()->findMemberById(memberID);
            if (member==NULL)
            {
                printf("没有找到这个会员,请重新输入\n");
            }
            else
            {
                switch (member->getMemberLevel()) {
                    case kRegular:
                        return new RegularPrice();
                        break;
                    case kGolden:
                        return new GoldenPrice();
                        break;
                    case kSilver:
                        return new SilverPrice();
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

void CheckoutCommand::pay()
{
    float totalSum=0;
    float paySum=0;
    ProductsPrice* productPrice=getProductsPrice();
    ShoppingList* shoppingList=getCurrentShoppingList();
    totalSum=productPrice->getPrice(shoppingList->getProductList(), shoppingList->getCount());
    
    cout<<"共需支付"<<totalSum<<"元"<<endl;
    printf("-------------------------------------------------------------\n");
    printf("输入cash sum:表示使用现金支付，支付金额为sum元\n");
    printf("输入bank sum:表示使用银行支付，支付金额为sum元\n");
    printf("输入shop sum:表示使用超市购物卡支付，支付金额为sum元\n");
    printf("-------------------------------------------------------------\n");
    while (true)
    {
        string way="";
        float sum;
        cout<<"还需支付"<<totalSum-paySum<<"元,请输入支付方式和金额:";
		cin>>way;
		string sumStr;
		getline(cin,sumStr);
		sum=atoi(sumStr.c_str());
	
		if (way=="") continue;

        if (sum-totalSum>10000)
        {
            cout<<"大哥。。你是土豪么。。。我找不起啊"<<endl;
            continue ;
        }
        
        if (way=="cash")    paySum+=sum;
        else if (way=="bank")
        {
            cout<<"请输入银行卡卡号和名字。。。随便输吧。。反正题目没要求我检查这个。。。。:";
            string bankCardId;
            string name;
            cin>>bankCardId>>name;
            cout<<"扣款成功,我们已经从您的银行卡扣除"<<sum<<"元"<<endl;
            paySum+=sum;
        }
        else if (way=="shop")
        {
            cout<<"输入购物卡卡号，输入all 可以查看所有的购物卡信息，。。不要偷偷用别人的。。。虽然你用了我也不知道－ －。。"<<endl;
            while (true)
            {
                string command;
                getline(cin, command);
                if (command=="") continue;
                cout<<command<<endl;
                if (command=="all")
                {
                    ShoppingCardManager::sharedShoppingManager()->showAllShoppingCard();
                    continue;
                }
                else
                {
                    ShoppingCard* shoppingCard=ShoppingCardManager::sharedShoppingManager()->findShoppingCardById(command);
                    if (shoppingCard==NULL)
                    {
                        cout<<"大哥。。。我都把别人的购物卡告诉你了。。你怎么还不会用啊"<<endl;
                        break ;
                    }
                    else
                    {
                        if (shoppingCard->getRemain()<sum)
                        {
                            cout<<"余额不足,请重新选择付款方式"<<endl;
                            break ;
                        }
                        else
                        {
                            shoppingCard->setRemain(shoppingCard->getRemain()-sum);
							 paySum+=sum;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            cout<<"大哥。。。我们是小本经营。。你就不要赊账了吧。。。"<<endl;
            continue ;
        }
        
        if (paySum>=totalSum)
        {
            cout<<"支付完成，本次支付"<<paySum<<"元，找您"<<totalSum-paySum<<"元"<<endl;
            break ;
        }
    }
}


