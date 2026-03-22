#include<iostream>
#include<ctime>
#include"IssueRecord.h"
#include"Member.h"
using namespace std;

class Payment{
      private:
            int id;
            int member_id;
            float amount;
            string type;
            time_t transaction_time;
            time_t nextpayment_duedate;      
      public:
            Payment(){
                  transaction_time=time(0);
            }

            Payment(int id,int member_id,float amount,string type,time_t transaction_time,time_t nextpayment_duedate){
                  this->id=id;
                  this->member_id=member_id;
                  this->amount=amount;
                  this->type = type;
                  this->transaction_time = transaction_time;
                  this->nextpayment_duedate = nextpayment_duedate;
            }
            Payment(int member_id, float amount, string type, time_t transaction_time, time_t nextpayment_duedate)
            {
                  this->member_id = member_id;
                  this->amount = amount;
                  this->type=type;
                  this->transaction_time=transaction_time;
                  this->nextpayment_duedate=nextpayment_duedate;
            }
            int returnBook(int memberId, vector<IssueRecord *> &recordList, vector<Member *> &memberList, vector<Payment *> &paymentList);

};
