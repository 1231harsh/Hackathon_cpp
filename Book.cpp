#include<iostream>
#include<vector>;
#include "Book.h";

bool addBook(vector<Book *> &bookList){
      Book* b=new Book();
      string title;
      string author;
      string subject;
      string isbn;

      cout<<"Enter Title"<<endl;
      cin>>title;
      b->setTitle(title);

      cout << "Enter Author" << endl;
      cin >> author;
      b->setAuthor(author);

      cout << "Enter Subject" << endl;
      cin >> subject;
      b->setSubject(subject);

      cout << "Enter Isbn" << endl;
      cin >> isbn;
      b->setTitle(isbn);

      bookList.push_back(b);

      return true;
}
