// #include "std_lib_facilities.h"

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
inline void keep_window_open(){ char ch; cin>>ch;}

int main(){
  vector<int> v = {1,3,5,7,9};
  vector<string> s = {};
  s = {"asdcvf","acds","sdvfd","sdvfd"};
  cout<<"\nv[0] is "<<v[0];
  cout<<"\ns[1] is "<<s[1];
  v.push_back(6);
  //v.push_back(vector<int>(7,8,9));
  //v.push_back(10,11,12);
  s.push_back("egrthyhg");
  //s.push_back({"fdxg","ewrbgf","rbdvs"});
  //s.push_back("bdf","vdd","svf");
  cout<<"\nsize of v is "<<v.size();
  cout<<"\nsize of s is "<<s.size();
  cout<<"\nv is-- ";
  for (int i : v){
    cout<<i<<"\t";
  }
  cout<<"\ns is-- ";
  for (string x : s){
    cout<<x<<"\t";
  }
  cout<<endl;
  //keep_window_open();
}
