#include<iostream>
using namespace std;

void one(){
  // dec hex oct manipulators
  int a,b,c,d;

  cout<<"\nintegers as dec hex and oct: \t";
  cout<<1234<<"\t"<<hex<<1234<<"\t"<<oct<<1234;

  cout<<"\ninput integers: ";
  cin>>a>>b>>c>>d;

  cout<<"\nManipulators persist (sticky): \n";
  cout<<dec;
  cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n";
  cout<<a<<"\t"<<hex<<b<<"\t"<<oct<<c<<"\t"<<d<<dec;

  cout<<"\nEnter numbers without prefixes(dec, hex, oct, oct): ";
  cin>>a>>hex>>b>>oct>>c>>d;
  cout<<"\na, b, c, d: With default flags for cin: ";
  cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n";

  cin.clear();
  cout<<"\nwith flags cleared with unsetf(): ";
  cin.unsetf(ios::dec);
  cin.unsetf(ios::hex);
  cin.unsetf(ios::oct);
  cout<<"\nEnter numbers with prefixes: ";
  cin>>a>>b>>c>>d;
  //cout<<dec;
  cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n";
  cin>>dec; //expecting dec
  cout<<"\nExpecting dec: (but enter hex oct too :P) ";
  cin>>a>>b>>c>>d;
  cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n";
}

void two(){
  // floating point manipulators
  cout << 1234.56789 << "\t\t(defaultfloat)\n"    // \t\t to line up columns
       << fixed << 1234.56789 << "\t(fixed)\n"
       << scientific << 1234.56789 << "\t(scientific)\n";

  cout << 1234.56789 << '\n';
  cout << defaultfloat << 1234.56789 << '\t'   // floating format “sticks”
                                               // the default format for
                                               // floating-point output
       << fixed << 1234.56789 << '\t'
       << scientific << 1234.56789 << '\n';
  cout << defaultfloat << 12.3456789 << '\t'
       << fixed << 12.3456789 << '\t'
       << scientific << 12.3456789 << '\n';
  cout << defaultfloat << 12.345678912 << '\t'
      << fixed << 12.345678912 << '\t'
      << scientific << 12.345678912 << '\n';
      cout << defaultfloat << 12.345 << '\t'
           << fixed << 12.345 << '\t'
           << scientific << 12.345 << '\n';
}

int main(){
  one();
  two();

  return 0;
}
