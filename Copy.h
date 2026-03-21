#include<iostream>
#include<vector>
using namespace std;

class Copy{
      private:
            int id;
            int book_id;
            string rack;
            string status;
      public:
            Copy(){status="Available";}

            Copy(int id,
                 int book_id,
                 string rack,
                 string status)
            {
                  this->id=id;
                  this->book_id=book_id;
                  this->rack=rack;
                  this->status=status;
            }

            bool addCopy(vector<Copy*> &copyList);
            bool editCopy(vector<Copy*> &copyList); 
            bool updateStatus(vector<Copy *> &copyList);
            bool searchCopy(int copyId,vector<Copy*> &copyList);
            
            int getId(){return id;}
            void setId(int cid){id=cid;}

            int getBook_id(){return book_id;}
            void setBook_id(int bid){book_id=bid;}

            string getRack() {return rack;}
            void setRack(string cRack) {rack=cRack;}

            string getStatus() {return status;}
            void setStatus(string cStatus){status=cStatus;}
};