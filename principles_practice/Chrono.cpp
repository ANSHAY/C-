#include"Chrono.h"

namespace Chrono{
  const Date& Date::default_date(){
    static Date dd{1, Month::jan, Year{0001}};
    return dd;
  }

  Date::Date(): day{default_date().get_day()},
                month{default_date().get_month()},
                year{default_date().get_year()}
  {
  }

  bool Date::is_valid(){
    if (!y.is_valid()) return false;
    if (int(m)>12 || int(m)<1) return false;
    int days_max = days_in_month(m);
    if (d>days_max || d<1) return false;
    return true;
  }

  int Date::days_in_month(Month m){
    int days = 31;
    switch(m){
      case Month::feb:
        days = 28;
        break;
      case Month::apr:
      case Month::jun:
      case Month::sep:
      case Month::nov:
        days = 30;
        break;
    }
    return days;
  }

  bool Date::add_year(){
    year = Year{year.get_year()+1};
    if (!is_valid()){
      cout<<"\ninvalid date after increment";
      year = Year{year.get_year()-1};
      return false;
    }
    return true;
  }

  bool Date::add_month(){
    if (month==Month::dec){
      month = Month::jan;
      add_year();
    }
    else {
      month = Month(int(month)+1);
    }
    return true;
  }

  bool Date::add_day(){
    int max_days = days_in_month(month);
    day++;
    if (day > max_days){
      day = 1;
      add_month();
    }
    return true;
  }

  ostream& operator<<(ostream& os, const Date& d){
    return os<<"\nDate: "
             <<d.get_day()<<"/"
             <<int(d.get_month())<<"/"
             <<d.get_year().get_year();
  }

  bool leapyear(int y){
    if(y%400 == 0) return true;
    if(y%100 == 0) return false;
    if(y%4 == 0) return true;
    return false;
  }
}
