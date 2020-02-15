//------------------------------------------------------------------------------
/*
Requirements:
  1. Input 2 integers
  2. Input the type of operation (permutation or combination)
  3. Output the result of operation operated on the given numbers
  4. Handle errors with relevant error messages
  5. Compute permutation and combination on given numbers
Design:
  Build class with member functions for calculation of permutation and combination
  Build class for input output operations
*/
//------------------------------------------------------------------------------

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void keep_window_open(){
  cout<<"\nExiting the program!\n";
  char ch;
  cin>>ch;
  exit(0);
}
//------------------------------------------------------------------------------
// class for input and output
class Inout{
  // int variables for input numbers
  // char variable for choice of operation
  // double variable to hold the result
public:
  int a, b;
  char ch;
  double result;
  void read();  // inputs the numbers
  void display(); // display result
}io;

void Inout::read(){
  cout<<"\nEnter 2 integers:";
  cin>>a>>b;
  cout<<"\nEnter choice of operation (p/c): ";
  cin>>ch;
}

void Inout::display(){
  cout<<"\nResult: "<<io.result<<endl;
}

//------------------------------------------------------------------------------
// class for operations
class Operations{
public:
  double factorial(int a);
  double permutations(int a, int b);
  double combinations(int a, int b);
}op;

double Operations::factorial(int a){
  if (a==0 || a==1)
    return 1;
  if (a<0)
    throw runtime_error("\nFactorial of negative number. Check expression\n");
  return a*op.factorial(a-1);
}
double Operations::permutations(int a, int b){
  return op.factorial(a)/op.factorial(a-b);
}
double Operations::combinations(int a, int b){
  return op.permutations(a, b)/op.factorial(b);
}

//------------------------------------------------------------------------------
// Main function
int main(){
  // input 2 numbers
  // input choice of operation
  io.read();

  // perform operation
  if (io.ch == 'p' || io.ch == 'P'){
    io.result = op.permutations(io.a, io.b);
  }
  else if(io.ch == 'c' || io.ch=='C'){
    io.result = op.combinations(io.a, io.b);
  }
  // output result
  io.display();
}
