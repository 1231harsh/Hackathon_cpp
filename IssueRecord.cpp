#include <iostream>
#include "IssueRecord.h"

bool IssueRecord::assignCopy(int member_id,vector<IssueRecord *> recordList){
      int id;
      IssueRecord* ir=new IssueRecord();

      cout<<"Enter CopyId"<<endl;
      cin>>id;
      
      ir->setCopyId(id);
      ir->setMember_id(member_id);
      ir->setIssue_date();
      ir->setReturndue_date();
}