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
            bool calculateFine(int id,vector<Member*> &memberList,vector<IssueRecord> recordList);

            
};