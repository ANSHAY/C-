#include<iostream>
using namespace std;

class Year{
  static const int min = 0001;
  static const int max = 9999;
  int year;
public:
  bool is_valid();
  int get_year() {return year;}
  Year(int y):year{y}{
    if (!is_valid()) throw runtime_error("\nInvalid year");
  }
};
