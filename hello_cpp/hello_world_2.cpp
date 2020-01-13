// #include "std_lib_facilities.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() { char ch; cin>>ch; }

int main(){
  string previous = " ";
  string current;
  while(cin>>current){
    if(current==previous){
      cout<<"\nYour repeated a word dude! "<<current<<endl;
    }
    previous = current;
  }
  cout<<"\nOut of the loop!";
  keep_window_open();
  return 0;
}
