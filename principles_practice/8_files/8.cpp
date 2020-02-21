#include<iostream>
//using namespace std;

int main(){
  int i = 4;
  int* r = &i;

  cout<<"\ni="<<i;
  cout<<"\nr="<<r;
  cout<<"\n&i="<<&i;
  cout<<"\n&r="<<&r;
  cout<<"\n*r="<<*r;
  //cout<<"*i="<<*i;
  cout<<"\n";
  return 0;
}
