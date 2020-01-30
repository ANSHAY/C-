// #include "std_lib_facilities.h"

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
inline void keep_window_open(){ char ch; cin>>ch;}

bool contains(vector<string> vec, string s){
  for(string str:vec){
    if(str == s){
      return true;
    }
  }
  return false;
}

int main(){
  vector<string> disliked = {"broccoli"};
  vector<string> words;
  cout<<"\nEnter some words:\n";
  for(string temp; cin>>temp;){
    words.push_back(temp);
  }
  cout<<"\nEntered words are:\n";
  for(string s:words){
    if(contains(disliked, s)){
      cout<<"\nBleep";
    }
    else{
      cout<<"\n"<<s;
    }
  }

  cout<<endl;
  //keep_window_open();
}
