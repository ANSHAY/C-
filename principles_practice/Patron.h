#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Patron{
  string name;
  string lib_card_num;
  int fees;
public:
  string get_name() {return name;}
  string get_card_num() {return lib_card_num;}
  int get_fees() {return fees;}
  int set_fees(int f);
  bool ows_fees() {return fees?true:false;}
};

bool operator==(Patron& p1, Patron& p2);
