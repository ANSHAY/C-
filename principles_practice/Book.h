#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include"Chrono.h"
using namespace std;
using namespace Chrono;

enum class Genre{
  fiction=1, nonfiction, periodical, biography, children
};

class Book{
  string isbn;
  string title;
  string author;
  Date copyright_date;
  bool checked_out;
  Genre genre;
public:
  string get_isbn() const {return isbn;}
  string get_title() const {return title;}
  string get_author() const {return author;}
  Date get_copyright_date() const {return copyright_date;}
  bool get_checked_out() const {return checked_out;}
  Genre get_genre() const {return genre;}
  bool check_in();
  bool check_out();
  bool is_valid();
  Book(string i, string t, string a, Date c, bool k, Genre g);
};

bool operator==(const Book& book1, const Book& book2);
bool operator!=(const Book& book1, const Book& book2);
ostream& operator<<(ostream& os, const Book& book);
