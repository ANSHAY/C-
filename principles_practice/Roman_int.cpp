#include"Roman_int.h"

string Roman_int::get_symbol(){
  return symbol;
}

void Roman_int::set_symbol(string sym){
  symbol = sym;
}

int Roman_int::as_int(){
  return value;
}

void Roman_int::set_value(int val){
  value = val;
}

int sym_to_val(char ch){
  for (int i=0; i<roman_symbols.size();++i){
    if(ch==roman_symbols[i]){
      return roman_values[i];
    }
  }
  return 0;
}

ostream& operator<<(ostream& os, Roman_int& r){
  return os<<r.get_symbol();
}

istream& operator>>(istream& is, Roman_int& r){
  string sym;
  char ch;
  int last_val=10000, val=0;
  while(is>>ch && isalpha(ch)){
    sym+=ch;
    int temp = sym_to_val(ch);
    if(temp > last_val){
      val += temp - 2*last_val;
    }
    else{
      val += temp;
    }
    last_val = temp;
  }
  is.unget();
  r.set_symbol(sym);
  r.set_value(val);
  return is;
  // read the Roman_symbols
  // calculate  value of symbol stored
}
