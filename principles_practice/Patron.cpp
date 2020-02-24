#include"Patron.h"

int Patron::set_fees(int f){
  if(f<0) {
    cout<<"\nFees cant be negative. Fees not set!"; return fees;
  }
  fees = f;
  return fees;
}

bool operator==(Patron& p1, Patron& p2){
  return p1.get_card_num() == p2.get_card_num();
}
