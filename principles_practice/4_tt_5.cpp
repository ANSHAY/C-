// #include "std_lib_facilities.h"

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
inline void keep_window_open(){ char ch; cin>>ch;}

int square(int num){
  int sqr = 0;
  for (int i=0; i<num; ++i){
    sqr += num;
  }
  return sqr;
}

int main(){
  int i;
  cout<<"\nEnter a number: ";
  cin>>i;
  cout<<"\nSquare of "<<i<<" is: "<<square(i)<<endl;
  //keep_window_open();
}
