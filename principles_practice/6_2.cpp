#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Token{
public:
  char kind;
  char kind2;
  double value;
};

Token get_token();

Token get_token(){
  char kind, kind2;
  double value;
  cout<<"\nEnter values-+5: ";
  cin>>kind>>kind2>>value;
  return Token{kind, kind2, value};
}

int main(){
  Token t = get_token();
  cout<<t.kind<<t.value<<endl;
  vector<Token> tv;
  tv.push_back(t);
  cout<<tv[0].kind<<tv[0].value<<endl;
}
