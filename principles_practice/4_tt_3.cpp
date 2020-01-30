// #include "std_lib_facilities.h"

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
inline void keep_window_open(){ char ch; cin>>ch;}

int main(){
  char e = 'z';//char{9};
  /*
    char c = 'a';
    while(c <= e){
    cout<<c<<"\t"<<int{c}<<endl;
    c++;
  }
  */
  for(char c = 48; c <= 'z'; c++){
    cout<<c<<"\t"<<int(c)<<endl;
  }
  cout<<"\nchkpt 3";
  cout<<('c'<='e');
  //keep_window_open();
}
