#include <iostream>
#include <ctime>
#include "IssueRecord.h"
#include "Member.h"
#include "Payment.h"
using namespace std;

int Payment::returnBook(int memberId, vector<IssueRecord *> &recordList, vector<Member *> &memberList,vector<Payment* > &paymentList){
      Member *m;
      IssueRecord* ir;
      for (Member *val : memberList){
            if (val->getId() == memberId){
                  m = val;
                  break;
            }
      }
      for (IssueRecord* val : recordList){
            if (val->getId() == memberId){
                  ir = val;
                  break;
            }
      }

      int fine=m->calculateFine(ir);

      m->setPaid_status("Paid");
      m->setNextpayment_duedate(NULL);

      Payment* p=new Payment(m->getId(),fine,"Online",time(0),NULL);

      paymentList.push_back(p);
      
      return fine;
}
