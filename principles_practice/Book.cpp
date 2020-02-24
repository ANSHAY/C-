#include"Book.h"

bool Book::check_in(){
  checked_out = false;
  return true;
}

bool Book::check_out(){
  if(checked_out) {
    cout<<"\nAlready checked out";
    return false;
  }
  checked_out = true;
  return true;
}

bool Book::is_valid(){
  // check if the isbn is of the form n-n-n-x where n is integer and x is a digit or letter
  return false;
}

Book::Book(string i, string t, string a, Date c, bool k, Genre g):
     isbn{i}, title{t}, author{a}, copyright_date{c}, checked_out{k}, genre{g}{
  if(!is_valid()) throw runtime_error("\nInvalid data!");
}

bool operator==(const Book& book1, const Book& book2){
  if(book1.get_isbn() != book2.get_isbn()) return false;
  return true;
}

bool operator!=(const Book& book1, const Book& book2){
  if(book1.get_isbn() == book2.get_isbn()) return false;
  return true;
}

ostream& operator<<(ostream& os, const Book& book){
  return os<<"\nTitle: "<<book.get_title()
           <<"\nAuthor: "<<book.get_author()
           <<"\nISBN: "<<book.get_isbn();
}
