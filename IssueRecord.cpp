#include <iostream>
#include "IssueRecord.h"
#include "Copy.h"

bool IssueRecord::assignCopy(int member_id,int copyId,vector<Copy*> &copyList,vector<IssueRecord *> &recordList){
      int id;
      IssueRecord* ir=new IssueRecord();

      cout<<"Enter CopyId"<<endl;
      cin>>id;
      
      ir->setCopyId(id);
      ir->setMember_id(member_id);
      ir->setIssue_date();
      ir->setReturndue_date();

      Copy* c;
      for(int i=0;i<copyList.size();i++){
            if(copyList[i]->getId()==copyId){
                  c = copyList[i];
                  copyList.erase(copyList.begin()+i);
            }
      }
      c->setStatus("Not Available");
      copyList.push_back(c);
}