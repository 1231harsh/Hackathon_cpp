#include<iostream>
#include<vector>
#include "Member.h"

using namespace std;

bool Member::addMember(){
      string name;
      string email;
      string phone;
      time_t nextpayment_duedate;
      bool paid_status;

      Member* m= new Member();


      cout<<"Enter Name: "<<endl;
      cin>>name;
      m->setName(name);

      cout << "Enter Email: " << endl;
      cin >> email;
      m->setEmail(email);

      cout << "Enter Phone: " << endl;
      cin >> phone;
      m->setPhone(phone);

}

bool Member::editMember(int id, vector<Member *> &memberList){

      Member* m;
      for(Member* val :  memberList){
            if(val->getId()==id){
                  m=val;
                  break;
            }
      }

      string name;
      string email;
      string phone;

      cout<<"Enter Name : "<<endl;
      cin>>name;
      m->setName(name);

      cout << "Enter Email : " << endl;
      cin >> email;
      m->setName(email);

      cout << "Enter Phone : " << endl;
      cin >> phone;
      m->setName(phone);

      memberList.push_back(m);

      return true;
}

bool Member::checkMember(int id, vector<Member *> &memberList){
      for (Member *val : memberList)
      {
            if (val->getId() == id)
            {
                  return true;
            }
      }
      return false;
}
bool Member::getStatus(int memberId, vector<Member *> memberList){
      Member* m;
      for(Member* val : memberList){
            if(val->getId()==memberId){
                  m=val;
                  break;
            }
      }     
      return m->getPaid_status();
}

int Member::calculateFine(IssueRecord* ir){
      time_t returnDate=ir->getReturn_date();
      time_t issueDate=ir->getIssue_date();

      int diff=difftime(issueDate,returnDate)/(24*60*60);

      return 5*diff;

}