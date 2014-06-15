//
//  Member.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/10/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "Member.h"
#include <iomanip>

void Member::setMemberId(string memberId)
{
    this->memberId=memberId;
}

void Member::setName(string name)
{
    this->name=name;
}

void Member::setSex(Sex sex)
{
    this->sex=sex;
}

void Member::setSex(string sex)
{
    if (sex=="woman")   this->sex=kMan;
    else this->sex=kWoman;
}

void Member::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber=phoneNumber;
}

void Member::setMemberLevel(MemberLevel memberLevel)
{
    this->memberLevel=memberLevel;
}

void Member::setMemberLevel(string memberLevel)
{
    if (memberLevel=="golden") this->memberLevel=kGolden;
    else if (memberLevel=="silver") this->memberLevel=kSilver;
    else this->memberLevel=kRegular;
}

string Member::getMemberId()
{
    return memberId;
}

string Member::getName()
{
    return name;
}

Sex Member::getSex()
{
    return sex;
}

MemberLevel Member::getMemberLevel()
{
    return memberLevel;
}

string Member::getPhoneNumber()
{
    return phoneNumber;
}

string Member::sexToString()
{
    if (sex==kMan) return "man";
    else return "woman";
}

string Member::memberLevelToString()
{
    if (memberLevel==kGolden) return "golden";
    else if (memberLevel==kSilver) return "silver";
    else return "regular";
}

void Member::showMemberInfo()
{
    cout<<setiosflags(ios::left)<<setw(20)<<memberId;
    cout<<setiosflags(ios::left)<<setw(20)<<name;
    cout<<setiosflags(ios::left)<<setw(20)<<sexToString();
    cout<<setiosflags(ios::left)<<setw(20)<<phoneNumber;
    cout<<setiosflags(ios::left)<<setw(20)<<memberLevelToString()<<endl;
}
