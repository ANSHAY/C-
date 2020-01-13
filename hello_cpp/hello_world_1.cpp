// #include "std_lib_facilities.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() { char ch; cin>>ch; }

int main(){
  cout<<"\nHello World!\n";
  int num;
  string name;
  string type;
  string name2;
  cout<<"\nEnter a number:\n";
  cin>>num;

  cout<<"\nEnter Name and type:";
  cin>>name;
  cin>>type;

  cout<<"\nHello, programming!";
  cout<<"\nHere we go! "<<num;
  cout<<"\nname: "<<name;
  cout<<"\nType: "<<type;

  keep_window_open();
  return 0;
}
