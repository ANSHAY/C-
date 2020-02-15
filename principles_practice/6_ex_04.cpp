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
inline void error(string s){
  throw runtime_error(s);
}
//------------------------------------------------------------------------------

class Name_value{
private:
  string name;
  double value;
}
int main(){

}
