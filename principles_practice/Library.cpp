#include"Library.h"

bool Library::add_book(Book b){
  if(is_valid(b)){
    cout<<"\nBook already present in library. Not added again";
    return false;
  }
  books.push_back(b);
  return true;
}

bool Library::add_Patron(Patron p){
  if(is_valid(p)){
    cout<<"\nPatron already exists in library. Not added again";
    return false;
  }
  patrons.push_back(p);
  return true;
}

bool Library::is_valid(Book b){
  for (Book book:books){
    if(b==book){
      return true;
    }
  }
  return false;
}

bool Library::is_valid(Patron p){
  for (Patron pat:patrons){
    if(p==pat){
      return true;
    }
  }
  return false;
}

bool Library::check_out_book(Book b, Patron p, Date d){
  if(!is_valid(b)) runtime_error("\nBook not in library");
  if(!is_valid(p)) runtime_error("\nPatron not registered");
  if(!d.is_valid()) runtime_error("\nInvalid date");
  if(p.ows_fees()){
    cout<<"\nFees pending. Please clear dues first.";
    return false;
  }
  transactions.push_back(Transaction{b, p, d});
  b.check_out();
  return true;
}

bool Library::defaulters(vector<Patron>& defs){
  for(Patron p:patrons){
    if(p.ows_fees()) defs.push_back(p);
  }
  return true;
}
