//
//  MemberManager.cpp
//  FinalProject
//
//  Created by 邱峰 on 6/14/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#include "MemberManager.h"
#include "Const.h"
#include <iostream>
#include <fstream>

MemberManager* MemberManager::_sharedMemberManager=NULL;

MemberManager* MemberManager::sharedMemberManager()
{
    if (_sharedMemberManager==NULL)
    {
        _sharedMemberManager=new MemberManager();
    }
    return _sharedMemberManager;
}

void MemberManager::readAllMember()
{
    string url=BASE_URL;
    url=url+"member.txt";
    
    ifstream in(url);

    string memberId;
    string memberName;
    string memberSex;
    string memberPhoneNumber;
    string memberLevel;
   
    while (in>>memberId>>memberName>>memberSex>>memberPhoneNumber>>memberLevel)
    {
        Member* member=new Member();
        member->setMemberId(memberId);
        member->setName(memberName);
        member->setSex(memberSex);
        member->setPhoneNumber(memberPhoneNumber);
        member->setMemberLevel(memberLevel);
        allMember.push_back(member);
    }
    
    in.close();
}

void MemberManager::showAllMember()
{
    for (vector<Member*>::iterator it=allMember.begin(); it<allMember.end(); it++)
    {
        Member* member=*it;
        member->showMemberInfo();
    }
}

Member* MemberManager::findMemberById(string memberId)
{
    for (vector<Member*>::iterator it=allMember.begin(); it<allMember.end(); it++)
    {
        Member* member=*it;
        if (member->getMemberId()==memberId) return member;
    }
    return NULL;
}

void MemberManager::save()
{
    string url=BASE_URL;
    url=url+"member.txt";
    ofstream out(url);
    
    for (vector<Member*>::iterator it=allMember.begin(); it<allMember.end(); it++)
    {
        Member* member=*it;
        out<<member->getMemberId()<<member->getName()<<member->sexToString()<<member->getPhoneNumber()<<member->memberLevelToString()<<endl;
    }
    
    out.close();
}