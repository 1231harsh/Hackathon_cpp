#include<iostream>
#include<vector>
using namespace std;
class Book{
      private:
            int id;
            string title;
            string author;
            string subject;
            string isbn;
            float price;
      public:
            Book(){}
            Book(int id,string title,string author,string subject,string isbn,float price){
                  this->title=title;
                  this->author=author;
                  this->subject=subject;
                  this->isbn=isbn;
                  this->price=price;
            }

            bool addBook(vector<Book*> &bookList);
            bool editBook(vector<Book*> &bookList);

            int getid(){return id;}
            void setid(int bid){id=bid;}

            string getTitle() { return title; }
            void setTitle(string bTitle) { title=bTitle; }

            string getAuthor() { return author; }
            void setAuthor(string bAuthor) { author = bAuthor; }

            string getSubject() { return subject; }
            void setSubject(string bSubject) { subject=bSubject; }

            string getIsbn() { return isbn; }
            void setIsbn(string bIsbn) { isbn = bIsbn; }

            float getPrice(){return price;}
            void setPrice(float bPrice){price=bPrice;}
};