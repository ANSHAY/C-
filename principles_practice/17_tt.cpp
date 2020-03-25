#include<iostream>
#include<vector>
using namespace std;

void sizes(char ch, int i, int* p){
  cout << "the size of char is " << sizeof(char)<< '\n';
  cout << "the size of char* is " << sizeof(char*)<< '\n';
  cout << "the size of int is " << sizeof(int)<< '\n';
  cout << "the size of int* is " << sizeof(int*)<< '\n';
  cout << "the size of bool is " << sizeof(bool)<< '\n';
  cout << "the size of bool* is " << sizeof(bool*)<< '\n';
  cout << "the size of double is " << sizeof(double)<< '\n';
  cout << "the size of double* is " << sizeof(double*)<< '\n';
  cout << "the size of vector int is " << sizeof(vector<int>)<< '\n';
  cout << "the size of vector* is " << sizeof(vector<int>*)<< '\n';
  cout << "the size of vector char is " << sizeof(vector<char>)<< '\n';
  cout << "the size of vector bool is " << sizeof(vector<bool>)<< '\n';
  cout << "the size of vector double is " << sizeof(vector<double>)<< '\n';
}

int main(){
  int* p;
  sizes('a', 5, p);
  return 0;
}
