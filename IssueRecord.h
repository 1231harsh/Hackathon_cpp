#include<iostream>
#include<vector>
#include<ctime>
#include"Copy.h"
using namespace std;

class IssueRecord{
      private:
            int id;
            int copy_id;
            int member_id;
            time_t issue_date;
            time_t return_duedate;
            time_t return_date;
            float fine_amount;
      public:
            IssueRecord();
            IssueRecord(int id,
                        int copy_id,
                        int member_id,
                        time_t issue_date,
                        time_t return_duedate,
                        time_t return_date,
                        float fine_amount)
            {
                  this->id=id;
                  this->copy_id=copy_id;
                  this->member_id=member_id;
                  this->issue_date=issue_date;
                  this->return_duedate=return_duedate;
                  this->return_date=return_date;       
                  this->fine_amount=fine_amount;          
            }
                        
            bool assignCopy(int member_id, int copyId, vector<Copy *> &copyList, vector<IssueRecord *> &recordList);
            // bool updateStatus(int copy_id, vector<IssueRecord*> &recordList);
            time_t rdd(int member_id);

            int getId(){return id;};

            int getCopyId(){return copy_id;}
            void setCopyId(int cId ){copy_id=cId;}

            int getMember_id() { return member_id; }
            void setMember_id(int mId) {member_id=mId ;}

            time_t getIssue_date() { return issue_date; }
            void setIssue_date(){issue_date=time(0);}

            time_t getReturndue_date() { return return_duedate; }
            void setReturndue_date() {return_duedate = time(0)+7*24*60*60; }

            time_t getReturn_date() { return issue_date; }
            void setReturn_date() { return_date = time(0);}

            float getFine_amount(){return fine_amount;}
            void setFine_amount(float amt){fine_amount=amt;}


};    