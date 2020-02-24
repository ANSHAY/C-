#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#include"Year.h"

namespace Chrono{
  enum class Month{
    jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
  };

  class Date{
    int day;
    Month month;
    Year year;
  public:
    bool add_day();
    bool add_month();
    bool add_year();

    int get_day() const {return day;}
    Month get_month() const {return month;}
    Year get_year() const {return year;}

    bool is_valid();
    int days_in_month(Month m);
    const Date& default_date();
    Date();
    Date(int d, Month m, Year y):day{d}, month{m}, year{y}{
      if(!is_valid()) throw runtime_error("\nInvalid Date");
    }
  };

  ostream& operator<<(ostream& os, const Date& d);
  bool leapyear(int y);
}
