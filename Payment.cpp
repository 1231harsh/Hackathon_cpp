#include <iostream>
#include <ctime>
#include <vector>
#include "Payment.h"
using namespace std;

class IssueRecord;
class Member;
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
            if (val->getMember_id() == memberId){
                  ir = val;
                  break;
            }
      }

      int fine=m->calculateFine(ir);

      m->setPaid_status("Paid");
      m->setNextpayment_duedate(0);

      Payment* p=new Payment(m->getId(),fine,"Online",time(0),0);

      paymentList.push_back(p);
      
      return fine;
}
