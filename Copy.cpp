#include<iostream>
#include<vector>
#include "Copy.h"
#include "Book.h"

bool Copy::addCopy(vector<Copy *> &copyList){
      Copy* c=new Copy();
      int bookId;
      string rack;
      string status;

      cout<<"Enter BookId"<<endl;
      cin>>bookId;
      c->setBook_id(bookId);

      cout << "Enter Rack" << endl;
      cin >> rack;
      c->setRack(rack);

      cout << "Enter Status" << endl;
      cin >> status;
      c->setStatus(status);

      copyList.push_back(c);
}
bool Copy::updateStatus(vector<Copy *> &copyList)
{
      Copy *c;
      int id;
      cout<<"Enter CopyId"<<endl;
      cin>>id;
      for(Copy* val:copyList){
            if(val->getId()==id) {
                  c=val;
                  break;
            }
      }

      string status;

      cout << "Enter Status" << endl;
      cin >> status;
      c->setStatus(status);

      copyList.push_back(c);
}

bool Copy::searchCopy(int copyId, vector<Copy *> &copyList){
      for(Copy* val: copyList){
            if(val->getId()==copyId&&val->getStatus()=="Available") return true;
      }
      return false;
}    
