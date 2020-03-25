#include<iostream>
#include<vector>
#include<string>
using namespace std;

// class Roman_int that keeps roman symbols and their values
class Roman_int{
  string symbol;
  int value;
public:
  int as_int();
  void set_value(int);
  string get_symbol();
  void set_symbol(string sym);
};

// defining roman symbols
const vector<char> roman_symbols = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

// defining symbol values
const vector<int> roman_values = {1, 5, 10, 50, 100, 500, 1000};

int sym_to_val(char);

ostream& operator<<(ostream&, Roman_int&);
istream& operator>>(istream&, Roman_int&);
