//#include"std_lib_facilities.h"
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

inline void keep_window_open(){
  char ch;
  cin>>ch;
}

int main(){
  string name;
  string recipient;
  string friend_name;
  char friend_sex = 0;
  int age = -1;

  cout<<"\nEnter your name:";
  cin>>name;
  cout<<"\nEnter the name of the person you want to write to: ";
  cin>>recipient;
  cout<<"\n\nEnter name of another friend:";
  cin>>friend_name;
  cout<<"\nEnter friend sex as m/f:";
  cin>>friend_sex;
  cout<<"\nEnter age of the recipient:";
  cin>>age;

  cout<<"\nDear "<<recipient<<',';
  cout<<"\nHow are you? I am fine. I miss you.";
  cout<<"\nHave you seen "+friend_name+" lately?";
  if (friend_sex=='m'){
    cout<<"\nIf you see "+friend_name+" please ask him to call me.";
  }
  else{
    cout<<"\nIf you see "+friend_name+" please ask her to call me.";
  }
  if (age<=0 && age>=110){
    perror("\nyou're kidding!");
  }
  else{
    cout<<"\nI hear you just had a birthday and you are "<<age<<" years old.";
  }
  if (age<12){
    cout<<"\nNext year you will be "<<age+1<<" .";
  }
  else if(age==17){
    cout<<"\nNext year you will be able to vote.";
  }
  else if(age>70){
    cout<<"\nIhope you are enjoying retirement.";
  }
  cout<<"\nYours Sincerely,\n\n"<<name;
  cout<<endl;
  return 0;
}
