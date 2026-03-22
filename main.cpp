#include <iostream>
#include <vector>
#include "Book.h"
// #include "Copy.h"
// #include "Member.h"
#include "Payment.h"
#include<fstream> 
#include<sstream>

using namespace std;

time_t parseDateTime(const char* datetimeString, const char* format)
{
    struct tm tmStruct;
    strptime(datetimeString, format, &tmStruct);
    return mktime(&tmStruct);
}

time_t stringToTime(string s)
{
   char * d;
   strcpy(d,s.c_str());
    char * format = "%a %b %d %H:%M:%S %Y";
    time_t pt = parseDateTime(d,format);
    return pt;
}

bool stb(string s)
{
    if(s=="true")
    {
        return true;
    }
    else{
        return false;
    }
}

// menu functions
int mainMenu()
{
    int choice;
    cout << "1.Books" << endl;
    cout << "2.Members" << endl;
    cout << "3.Issue" << endl;
    cout << "4.Return" << endl;
    cout << "5.Payments" << endl;
    cout << "6.Reports" << endl;
    cout << "0.Exit" << endl;
    cin >> choice;
    return choice;
}

int bookMenu()
{
    int choice;
    cout << "1.Add Book" << endl;
    cout << "2.Edit Book" << endl;
    cout << "3.Add Copy" << endl;
    cout<<"4.Edit Copy"<<endl;
    cout << "0.Exit" << endl;
    cin >> choice;
    return choice;
}

int membersMenu()
{
    int choice;
    cout << "1.Add Member" << endl;
    cout<<"2.Edit Member"<<endl;
    cout<<"0.Exit"<<endl;
    return choice;
}

int issueRecordMenu()
{
    int choice;
    cout<<"1.Check Member"<<endl;
    cout<<"2.Assign Copy"<<endl;
    cout<<"0.Exit"<<endl;
    return choice;
}
// login function

void login(string &user, string &password)
{
    cout << "Please enter your Login details!!" << endl;
    cout << "Enter username: " << endl;
    cin >> user;
    cout << "Enter password: " << endl;
    cin >> password;
}

// menu function handlers

void  handleBookMenu(vector<Book*>& books_list,vector<Copy*> &copy_list)
{
    int bookMenuChoice;
    Book b;
    Copy c;
    while ((bookMenuChoice = ::bookMenu()) != 0)
    {
        switch (bookMenuChoice)
        {
        case 1:
        {
            bool bookAdded = b.addBook(books_list);
            if (bookAdded)
            {
                cout << "Book added successfully" << endl;
                Book * b = books_list.back();
                cout<<b->getTitle()<<endl;
            }
            else
            {
                cout << "Failed to add the book" << endl;
            }
            break;
        }
        case 2:
        {
            // bool bookEdited = editBook(books_list);
            // if (bookEdited)
            // {
            //     cout << "Book edited successfully" << endl;
            // }
            // else
            // {
            //     cout << "Failed to edit " << endl;
            // }
            // break;
        }
        case 3:
        {
            bool copyAdded = c.addCopy(copy_list);
            if (copyAdded)
            {
                cout << "Copy added successfully" << endl;
            }
            else
            {
                cout << "Failed to add copy" << endl;
            }
            break;
        }
        case 4:
        {
            bool statusUpdated = c.updateStatus(copy_list);
            if(statusUpdated)
            {
                cout<<"Status update successfull"<<endl;
            }
            else{
                cout<<"Status update faield"<<endl;
            }
            break;
        }
        default:
            cout<<"Please enter a valid choice"<<endl;
        }
    }
}

void handleMembersMenu(vector<Member*> &members_list)
{
    Member  m;
    int choice;
    while((choice=::membersMenu())!=0)
    {
        switch(choice)
        {
            case 1:
                {
                    bool memberAdded = m.addMember();
                    if(memberAdded)
                    {
                        cout<<"Member added sucessfully"<<endl;
                    }
                    else{
                        cout<<"Failed to add member"<<endl;
                    }
                    break;
                }

            case 2:
                {
                    int memId;
                    cout<<"Please enter member id:"<<endl;
                    bool memberEdited = m.editMember(memId,members_list);
                    if(memberEdited)
                    {
                        cout<<"Member edited successfully"<<endl;
                    }
                    else{
                        cout<<"Failed to edit member"<<endl;
                    }
                    break;
                }

            default:
                cout<<"Please enter a valid choice"<<endl;
            
        }
    }
}

void handleIssueRecordMenu(vector<IssueRecord*>& recordList,vector<Copy*> & copy_list,vector<Member*> & member_list)
{
    int choice;
    IssueRecord ir;
    Member m;
    Copy c;
    while((choice=::issueRecordMenu())!=0)
    {
        switch (choice)
        {
            case 1:
            {
                int memId;
                cout<<"Please enter member id"<<endl;
                cin>>memId;

                bool memberExist = m.checkMember(memId,member_list);
                if(memberExist)
                {
                    cout<<"Member exists"<<endl;
                }
                else{
                    cout<<"Member does not exist"<<endl;
                    break;
                }
                bool paidStatus  = m.getStatus(memId,member_list);
                int cid;
                cout<<"Enter the copy id:"<<endl;
                cin>>cid;
                if(paidStatus)
                {
                    if(c.searchCopy(cid,copy_list))
                    {
                        ir.assignCopy(memId,cid,copy_list,recordList);
                    }

                }
                else{
                    cout<<"Failed to assign copy"<<endl;
                }
            }
            
            default:
                cout<<"Please enter a valid choice"<<endl;
        }
    }

}

void handleReturn(vector<IssueRecord*>& recordList,vector<Member*>& members_list,vector<Payment*>& payment_list)
{
    Payment p;
    int memId;
    cout<<"Please enter the your member id:"<<endl;
    cin>>memId;
    int fine = p.returnBook(memId,recordList,members_list,payment_list);
    cout<<"Fine Amount: "<<fine<<endl;
    cout<<"Book returned succesfully"<<endl;
}

//
void saveData(vector<Book*> &book_list,vector<Copy *> copys_list,vector<IssueRecord *> record_list,vector<Member *> members_list)
{
    ofstream fout("Book.txt"); 
    for(int i = 0 ; i < book_list.size( ) ; i++)
    {
        Book *b; 
        b = book_list[i]; 
        fout<<b->getid( )<<","<<b->getTitle( )<<","<<b->getAuthor()<<","<<b->getSubject()<<","<<b->getIsbn()<<","<<b->getPrice()<<endl; 
    }
    fout.close( ); 

    ofstream fout("Copy.txt"); 
    for(int i = 0 ; i < copys_list.size( ) ; i++)
    {
        Copy * c;
        c= copys_list[i];
        fout<<c->getId()<<","<<c->getBook_id()<<","<<c->getRack()<<","<<c->getStatus()<<endl; 
    }
    fout.close( );

    ofstream fout("Member.txt"); 
    for(int i = 0 ; i < members_list.size( ) ; i++)
    {
        Member * m;
        m= members_list[i];
        fout<<m->getId()<<","<<m->getName()<<","<<m->getEmail()<<","<<m->getPhone()<<","<<m->getNextpayment_duedate()<<","<<m->getPaid_status()<<endl; 
    }
    fout.close( );

    ofstream fout("IssueRecord.txt"); 
    for(int i = 0 ; i < record_list.size( ) ; i++)
    {
        IssueRecord * ir;
        ir= record_list[i];
        fout<<ir->getMember_id()<<","<<ir->getCopyId()<<","<<ir->getIssue_date()<<","<<ir->getReturndue_date()<<","<<ir->getReturn_date()<<","<<ir->getFine_amount()<<endl; 
    }
    fout.close( );
    
}

void loadData(vector<Book*> &book_list,vector<Copy *> copys_list,vector<IssueRecord *> record_list,vector<Member *> members_list) 
{
    ifstream fin("Book.txt"); 
    string line; 
    while(getline(fin , line))
    {
        stringstream data(line); 
        string id,title , author , subject , isbn,price; 
        getline(data,id,',');
        getline(data,title,',');
        getline(data,author,',');
        getline(data,subject,',');
        getline(data,isbn,',');
        getline(data,price,',');
        book_list.push_back(new Book(stoi(id),title,author,subject,isbn,stof(price)));  
    }
    fin.close( ); 

    
    ifstream fin("Copy.txt"); 
    while(getline(fin , line))
    {
        stringstream data(line); 
        string id , book_id , rack , status; 
        getline(data,id,',');
        getline(data,book_id,',');
        getline(data,rack,',');
        getline(data,status,',');
        copys_list.push_back(new Copy(stoi(id),stoi(book_id),rack,status));  
    }
    fin.close( ); 

    ifstream fin("Member.txt"); 
    while(getline(fin , line))
    {
        stringstream data(line); 
        string id,name , email , phone , nextpayment_duedate,paid_status; 
        getline(data,id,',');
        getline(data,name,',');
        getline(data,email,',');
        getline(data,phone,',');
        getline(data,nextpayment_duedate,',');
        getline(data,paid_status,',');
        members_list.push_back(new Member(stoi(id),name,email,phone,stringToTime(nextpayment_duedate),stb(paid_status)));  
    }

    ifstream fin("IssueRecord.txt"); 
    while(getline(fin , line))
    {
        stringstream data(line); 
        string id , copy_id , member_id , issue_date,return_duedate,return_date,fine_amount; 
        getline(data,id,',');
        getline(data,copy_id,',');
        getline(data,member_id,',');
        getline(data,issue_date,',');
        getline(data,return_duedate,',');
        getline(data,return_duedate,',');
        getline(data,return_date,',');
        getline(data,fine_amount,',');
        record_list.push_back(new IssueRecord(stoi(id),stoi(copy_id),stoi(member_id),stringToTime(issue_date),stringToTime(return_duedate),stringToTime(return_date),stof(fine_amount)));  
    }
    
    fin.close( ); 

    


}


int main()
{
    vector<Book *> books_list;
    vector<Copy *> copys_list;
    vector<IssueRecord *> record_list;
    vector<Member *> members_list;
    vector<Payment*> payment_list;
    string user;
    string password;
    login(user, password) ;
    loadData(books_list,copys_list,record_list,members_list);
    // if (authenticate(user, password))
    if(true)
    {
        // continue workflow
        int mainMenuChoice, bookMenuChoice, memberMenuChoice, issueMenuChoice, returnMenuChoice;
        while ((mainMenuChoice = mainMenu()) != 0)
        {
            switch (mainMenuChoice)
            {
            case 1:
                handleBookMenu(books_list,copys_list);
                break;
            
            case 2:
                handleMembersMenu(members_list);
                break;

            case 3:
            {
                handleIssueRecordMenu(record_list,copys_list,members_list);
                break;
            }
            case 4:
            {
                handleReturn(record_list,members_list,payment_list);
                break;
            }
            case 5:
                //show payments here
                break;
            case 6:
                //  showReports(books_list,copys_list,record_list,members_list);
                 break;
            default:
                cout<<"Please enter a valid choice"<<endl;
            }
        }
    }
    else
    {
        cout << "User authentication failed" << endl;
        login(user,password);
    }

    saveData(books_list,copys_list,record_list,members_list);

    return 0;
}