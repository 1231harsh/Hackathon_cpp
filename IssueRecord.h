#include<iostream>
#include<vector>
#include<ctime>
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
            bool assignCopy(int member_id,vector<IssueRecord*> recordList);
            bool updateStatus(int copy_id, vector<IssueRecord*> recordList);
            time_t rdd(int member_id);

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


};    