#include"Book.h"
#include"Patron.h"
//#include"Chrono.h"
using namespace Chrono;

struct Transaction{
  Book book;
  Patron patron;
  Date date;
};

class Library{
  vector<Book> books;
  vector<Patron> patrons;
public:
  bool add_book(Book b);
  bool add_Patron(Patron p);
  bool is_valid(Book b);
  bool is_valid(Patron p);
  bool check_out_book(Book b, Patron p, Date d);
  bool defaulters(vector<Patron>& defs);
};

vector<Transaction> transactions;
