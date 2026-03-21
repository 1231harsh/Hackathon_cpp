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
            Member(){
                  nextpayment_duedate=NULL;
                  paid_status=true;
            }

            Member(int id,
                   string name,
                   string email,
                   string phone,
                   time_t nextpayment_duedate,
                   bool paid_status)
            {
                  this->id=id;
                  this->email=email;
                  this->phone=phone;
                  this->nextpayment_duedate=nextpayment_duedate;
                  this->paid_status=paid_status;
            }

            bool addMember();
            bool editMember(int id,vector<Member*> &memberList);
            bool checkMember(int id,vector<Member*> &memberList);
            int calculateFine(IssueRecord* ir);
            bool getStatus(int memberId,vector<Member*> memberList);

            int getId(){return id;}

            void setName(string Mname){name=Mname;}
            string getName(){return name;}

            void setEmail(string Memail){email=Memail;}
            string getEmail(){return email;}

            void setPhone(string Mphone){phone=Mphone;}
            string getPhone(){return phone;}
            
            void setNextpayment_duedate(time_t d){nextpayment_duedate=d;}
            time_t getNextpayment_duedate(){return nextpayment_duedate;}

            void setPaid_status(bool value){paid_status=value;}
            bool getPaid_status(){return paid_status;}
};