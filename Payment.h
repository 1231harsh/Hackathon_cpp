#include<iostream>
#include<ctime>
using namespace std;

class Payment{
      private:
            int id;
            int member_id;
            float amount;
            string type;
            time_t transaction_time;
            time_t nextpayment_duedate;            
};
