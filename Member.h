#include<iostream>
#include <vector>
#include<ctime>
#include "IssueRecord.h"
using namespace std;
class Member{
      private:
            int id;
            string name;
            string email;
            string phone;
            time_t nextpayment_duedate;
            bool paid_status;
      public:
            bool addMember();
            bool editMember(int id,vector<Member*> &memberList);
            bool checkMember(int id,vector<Member*> &memberList);
            int calculateFine(int cId,vector<Member*> &memberList,vector<IssueRecord*> &recordList);

            int getId(){return id;}

            void setName(string Mname){name=Mname;}
            string getName(){return name;}

            void setEmail(string Memail){email=Memail;}
            string getEmail(){return email;}

            void setPhone(string Mphone){phone=Mphone;}
            string getPhone(){return phone;}
            
            void setNextpayment_duedate(){
                  IssueRecord ir;
                  nextpayment_duedate=ir.rdd(id);
            }
            time_t getNextpayment_duedate(){return nextpayment_duedate;}

            void setPaid_status(bool value){paid_status=value;}
            bool getPaid_status(){return paid_status;}
};