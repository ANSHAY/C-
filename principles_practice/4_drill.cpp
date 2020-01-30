// #include "std_lib_facilities.h"

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
inline void keep_window_open(){ char ch; cin>>ch;}

bool isValidUnit(string unit, vector<string> units){
  for(string u : units){
    if(unit==u){
      return true;
    }
  }
  return false;
}

double inMeter(double num, string unit){
  double cm_m = 0.01, in_m = 0.0254, ft_m = 0.3048;
  if(unit=="cm"){
    return num*cm_m;
  }
  if(unit=="in"){
    return num*in_m;
  }
  if(unit=="ft"){
    return num*ft_m;
  }
  return num;
}

int main(){
  // int a, b;
  // double a, b;
  double num, sum, smallest=99999.9, largest=-99999.9;
  int size=0;
  string unit, prompt;
  vector<string> units = {"cm","m","ft","in"};
  vector<double> numbers;

  while(true){
    //cout<<"\nEnter 2 numbers: ";
    cout<<"\nEnter a number (with unit - cm,in,ft,m): ";
    //cin>>a>>b;
    while(cin>>num>>unit){
      if(isValidUnit(unit, units)){
        break;
      }
      cout<<"\nUnit not recognised.. Enter again: ";
    }
    cout<<"\nEntered number is: "<<num<<unit;
    num = inMeter(num, unit);
    if(num<smallest){
      smallest = num;
      cout<<" (smallest so far)";
    }
    if(num>largest){
      largest=num;
      cout<<" (largest so far)";
    }
    numbers.push_back(num);
    sum += num;
    size += 1;
    /*
    cout<<"\nEntered numbers are: "<<a<<"\t"<<b;
    if(a==b){
      cout<<"\nThe numbers are equal!";
    }
    else{
      cout<<"\nSmaller value is: "<<(a>b?b:a);
      cout<<"\nLarger value is: "<<(a>b?a:b);
      if(abs(a-b)<0.01){
        cout<<"\nThe numbers are almost equal!";
      }
    }
    */
    cout<<"\n\nContinue?  ('|' for exit): ";
    cin>>prompt;
    if(prompt=="|"){
      cout<<"\nBbye!\n";
      break;
    }
  }
  sort(numbers.begin(), numbers.end());
  cout<<"\n\nEntered numbers are:\n";
  for (double num:numbers){
    cout<<num<<"\t";
  }
  cout<<"\nSmallest number is: "<<smallest;
  cout<<"\nLargest number is: "<<largest;
  cout<<"\nTotal numbers are: "<<size;
  cout<<"\nSum of numbers is: "<<sum<<"m";

  cout<<endl;
  //keep_window_open();
}
