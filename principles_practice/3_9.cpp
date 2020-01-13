// #include "std_lib_facilities.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() { char ch; cin>>ch; }

int main(){
  char c = 'x';
  int i = c;
  char v = i;

  cout<<'<<5'<<"\n";

  double x;
  int y = x;
  int a = 256;
  char b = a;
  cout<<x<<' '<<y<<' '<<a<<' '<<b<<endl;

  double c1{2.7};
  int u{c1};
  int s{123};
  char n{s};
  cout<<c1<<' '<<u<<' '<<s<<' '<<n<<endl;

  keep_window_open();
  return 0;
}
