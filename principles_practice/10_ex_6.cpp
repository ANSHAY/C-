#include<iostream>
#include<vector>
#include<string>
using namespace std;

// defining roman symbols
const vector<char> roman_symbols = {'I', 'V', 'X', 'C', 'M', 'L'};

// defining symbol values
const vector<int> roman_values = {1, 5, 10, 100, 500, 1000};

// class Roman_int that keeps roman symbols and their values
class Roman_int{
  char symbol;
public:
  int as_int();
  char get_symbol();
  void set_symbol(char sym);
};

char Roman_int::get_symbol(){
  return symbol;
}

void Roman_int::set_symbol(char sym){
  symbol = toupper(sym);
}

int Roman_int::as_int(){
  int value=0;
  for (int i=0; i<roman_symbols.size(); ++i){
    if(roman_symbols[i] == symbol){
      return roman_values[i];
    }
  }
  return value;
}

ostream& operator<<(ostream& os, Roman_int& r){
  return os<<r.get_symbol();
}

istream& operator>>(istream& is, Roman_int& r){
  char sym;
  is>>sym;
  r.set_symbol(sym);
  return is;
}

int main(){
  Roman_int r;
  cout<<"\nEnter Roman Symbol: ";
  cin>>r;
  cout << "Roman " << r << " equals " << r.as_int() << '\n';
  return 0;
}
