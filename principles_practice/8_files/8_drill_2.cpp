#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void swap_v(int a,int b){
  int temp; temp = a; a=b; b=temp;
}

void swap_r(int& a, int& b){
  int temp; temp = a; a=b; b=temp;
}
/*
void swap_cr(const int& a,const int& b){
  int temp; temp = a; a=b; b=temp;            //compile time error changing constant values
}
*/
int main(){
  cout<<"\nFor ints:\n";
  int x = 7;
  int y =9;
  swap_v(x,y);                                    // x y should stay same here
  cout<<"\nswap by value variables: "<<x<<"\t"<<y;
  swap_v(7,9);                                    // no effect
  cout<<"\nswap by value literals: "<<x<<"\t"<<y;

  swap_r(x,y);                                    // x y will change here
  cout<<"\nswap by ref variables: "<<x<<"\t"<<y;
  // swap_r(7,9);                                    // error changing literals
  // cout<<"\nswap by ref literals: "<<x<<"\t"<<y;

  // swap_cr(x,y);                                   // error changing constants
  // cout<<"\nswap by constref variables: "<<x<<"\t"<<y;
  // swap_cr(7,9);                                   // error changing constants
  // cout<<"\nswap by constref literals: "<<x<<"\t"<<y;

  cout<<"\nFor const ints:\n";
  const int cx = 7;
  const int cy = 9;
  swap_v(cx,cy);                                  // no effect
  cout<<"\nswap by value variables: "<<cx<<"\t"<<cy;
  swap_v(7.7,9.9);                                // warning truncating value
  cout<<"\nswap by value literals: "<<cx<<"\t"<<cy;

  // swap_r(cx,cy);                                  // error changing constant
  // cout<<"\nswap by ref variables: "<<cx<<"\t"<<cy;
  // swap_r(7.7,9.9);                                // error referring literals
  // cout<<"\nswap by ref literals: "<<cx<<"\t"<<cy;

  // swap_cr(cx,cy);                                 // error changing constant
  // cout<<"\nswap by constref variables: "<<cx<<"\t"<<cy;
  // swap_cr(7.7,9.9);                               // error ref literals
  // cout<<"\nswap by constref literals: "<<cx<<"\t"<<cy;

  cout<<"\nFor doubles:\n";
  double dx = 7.7;
  double dy = 9.9;
  swap_v(dx,dy);                                  // warning truncating value
  cout<<"\nswap by value variables: "<<dx<<"\t"<<dy;
  swap_v(7.7,9.9);                                // warning truncating value
  cout<<"\nswap by value literals: "<<dx<<"\t"<<dy;

  // swap_r(dx,dy);                                  // error int ref req
  // cout<<"\nswap by ref variables: "<<dx<<"\t"<<dy;
  // swap_r(7.7,9.9);                                // error ref literals
  // cout<<"\nswap by ref literals: "<<dx<<"\t"<<dy;

  // swap_cr(dx,dy);                                 // error int ref req
  // cout<<"\nswap by constref variables: "<<dx<<"\t"<<dy;
  // swap_cr(7.7,9.9);                               // error ref literals
  // cout<<"\nswap by constref literals: "<<dx<<"\t"<<dy;
  return 0;
}
