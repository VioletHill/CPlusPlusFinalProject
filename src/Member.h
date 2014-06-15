//
//  Member.h
//  FinalProject
//
//  Created by 邱峰 on 6/10/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__Member__
#define __FinalProject__Member__

#include <iostream>
#include <string>

using namespace std;

typedef enum Sex{
    kMan=0,
    kWoman=1,
}Sex;

typedef enum MemberLevel{
    kGolden=0,
    kSilver=1,
    kRegular,
}MemberLevel;

class Member
{
public:                                             //getter & setter
    void setMemberId(string memberId);
    void setName(string name);
    void setSex(Sex sex);
    void setSex(string sex);                         //man,woman            and man is default
    void setMemberLevel(MemberLevel memberLevel);
    void setMemberLevel(string string);             //string golden,silver,regular   and regular is default
    void setPhoneNumber(string phoneNumber);
    
    string sexToString();
    string memberLevelToString();
    
    string getMemberId();
    string getName();
    Sex getSex();
    string getPhoneNumber();
    MemberLevel getMemberLevel();
    
public:
    void showMemberInfo();
      
    
private:
    string memberId;
    string name;
    Sex sex;
    string phoneNumber;
    MemberLevel memberLevel;
};

#endif /* defined(__FinalProject__Member__) */
