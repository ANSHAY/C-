#include<iostream>
using namespace std;

enum class Month{
  jan=3, feb, mar
};

int main(){
  Month m = Month(3);
  cout<<int(Month::feb)<<endl;

  return 0;
}
