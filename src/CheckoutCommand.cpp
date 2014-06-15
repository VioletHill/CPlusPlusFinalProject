//
//  CheckoutCommand.cpp
//  FinalProject
//
//  Created by ��� on 6/14/14.
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
    printf("------------------------------------��ӭ�������ģʽ---------------------------------------\n");
    printf("help:                  ��ʾ������Ϣ\n");
    printf("product:               ��ʾ������Ʒ��Ϣ\n");
    printf("shopping:              ��ʾ���ﳵ��Ϣ\n");
    printf("exit:                  �˳�����\n");
    printf("pay:                   ��ʼ֧��\n");
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
    printf("�������Ա��ID,����all���Բ鿴���еĻ�Ա��\n");
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
                printf("û���ҵ������Ա,����������\n");
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
    
    cout<<"����֧��"<<totalSum<<"Ԫ"<<endl;
    printf("-------------------------------------------------------------\n");
    printf("����cash sum:��ʾʹ���ֽ�֧����֧�����ΪsumԪ\n");
    printf("����bank sum:��ʾʹ������֧����֧�����ΪsumԪ\n");
    printf("����shop sum:��ʾʹ�ó��й��￨֧����֧�����ΪsumԪ\n");
    printf("-------------------------------------------------------------\n");
    while (true)
    {
        string way="";
        float sum;
        cout<<"����֧��"<<totalSum-paySum<<"Ԫ,������֧����ʽ�ͽ��:";
		cin>>way;
		string sumStr;
		getline(cin,sumStr);
		sum=atoi(sumStr.c_str());
	
		if (way=="") continue;

        if (sum-totalSum>10000)
        {
            cout<<"��硣����������ô���������Ҳ���"<<endl;
            continue ;
        }
        
        if (way=="cash")    paySum+=sum;
        else if (way=="bank")
        {
            cout<<"���������п����ź����֡����������ɡ���������ĿûҪ���Ҽ�������������:";
            string bankCardId;
            string name;
            cin>>bankCardId>>name;
            cout<<"�ۿ�ɹ�,�����Ѿ����������п��۳�"<<sum<<"Ԫ"<<endl;
            paySum+=sum;
        }
        else if (way=="shop")
        {
            cout<<"���빺�￨���ţ�����all ���Բ鿴���еĹ��￨��Ϣ��������Ҫ͵͵�ñ��˵ġ�������Ȼ��������Ҳ��֪���� ������"<<endl;
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
                        cout<<"��硣�����Ҷ��ѱ��˵Ĺ��￨�������ˡ�������ô�������ð�"<<endl;
                        break ;
                    }
                    else
                    {
                        if (shoppingCard->getRemain()<sum)
                        {
                            cout<<"����,������ѡ�񸶿ʽ"<<endl;
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
            cout<<"��硣����������С����Ӫ������Ͳ�Ҫ�����˰ɡ�����"<<endl;
            continue ;
        }
        
        if (paySum>=totalSum)
        {
            cout<<"֧����ɣ�����֧��"<<paySum<<"Ԫ������"<<totalSum-paySum<<"Ԫ"<<endl;
            break ;
        }
    }
}


