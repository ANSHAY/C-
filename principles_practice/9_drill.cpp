#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

//#include"Year.h"
#include"Chrono.h"
using Chrono::Date;
using Chrono::Month;

int main(){
  Date today{25, Month::jun, Year{1978}};
  Date tomorrow{today};
  tomorrow.add_day();
  cout<<today<<endl;
  cout<<tomorrow<<endl;
  return 0;
}
