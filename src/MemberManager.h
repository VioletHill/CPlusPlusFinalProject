//
//  MemberManager.h
//  FinalProject
//
//  Created by 邱峰 on 6/14/14.
//  Copyright (c) 2014 TongjiUniversity. All rights reserved.
//

#ifndef __FinalProject__MemberManager__
#define __FinalProject__MemberManager__

#include <iostream>
#include <string>
#include <vector>
#include "Member.h"

using namespace std;

class MemberManager
{
public:
    static MemberManager* sharedMemberManager();
    
    void readAllMember();
    void showAllMember();
    
    Member* findMemberById(string memberId);
    void save();
    
private:
    
    static MemberManager* _sharedMemberManager;
    
    vector<Member*> allMember;
};

#endif /* defined(__FinalProject__MemberManager__) */
