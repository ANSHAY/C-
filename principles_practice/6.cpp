#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  double num;
  char ch;
  char prompt = 'n';
  try{
    do{
      cout<<"\nEnter a floating point number and a character: ";
      cin>>num>>ch;
      cout<<"\nNum: "<<num<<" Char: "<<ch;
      cout<<"\nRepeat?(y/n): ";
      cin.clear();
      cin>>prompt;
      cout<<"\nResponse received: "<<prompt<<endl;
    }while(prompt=='y'||prompt=='Y');
  }
  catch(...){
    cerr<<"\nSome kind of error!!";
  }
}
