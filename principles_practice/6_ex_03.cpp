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

double expression();

class Token{
  public:
    char kind;    // can be +-*/ and '8'(for numbers)
    double value; // the value in case of a number
};

class Token_stream{
  private:
    bool full{false};
    Token buffer;
  public:
    Token get();
    void putback(Token t);
}ts;

class Operations{
  public:
    double factorial(double d);
}op;

Token Token_stream::get(){
  if (full){
    full = false;
    return buffer;
  }
  char ch;
  cin>>ch;
  switch(ch){
    case 'q':
    case ';': //printing stuff
    case '!':
    case '(': case ')': case '{': case '}':
    case '+': case '-': case '*': case '/':
      return Token{ch};
    case '.': case '0': case '1': case '2':
    case '3': case '4': case '5': case '6':
    case '7': case '8': case '9':{
      cin.putback(ch);
      double d;
      cin>>d;
      return Token{'8',d};
    }
    default:
      throw runtime_error("\nBad Token!");
  }
}

void Token_stream::putback(Token t){
  if(full){
    throw runtime_error("\nBuffer limit exceeded!");
  }
  buffer = t;
  full = true;
}

double Operations::factorial(double d){
  if (d==0 || d==1)
    return 1;
  if (int(d)<d)
    throw runtime_error("\nFactorial of floating number. Check expression\n");
  if (d<0)
    throw runtime_error("\nFactorial of negative number. Check expression\n");
  return d*op.factorial(d-1);
}

double primary(){
  //Token_stream ts;
  Token t = ts.get();
  switch(t.kind){
    case '{':{
      double d = expression();
      Token t = ts.get();
      if (t.kind!='}'){
        throw runtime_error("\nexpected paranthesis '}'!");
      }
      return d;
    }
    case '(':{
      double d = expression();
      Token t = ts.get();
      if (t.kind!=')'){
        throw runtime_error("\nexpected paranthesis ')'!");
      }
      return d;
    }
    case '8':{
      Token tok = ts.get();
      if (tok.kind == '!'){
        return op.factorial(t.value);
      }
      ts.putback(tok);
      return t.value;
    }
    default:
      throw runtime_error("\nPrimary Expected!\n");
  }
}

double term(){
  double left = primary();
  //Token_stream ts;
  Token t = ts.get();
  while(true){
    switch(t.kind){
      case '*':
        left *= primary();
        t = ts.get();
        break;
      case '/':{
        double d = primary();
        if(d==0) throw runtime_error("\nDivide by zero");
        left /= d;
        t = ts.get();
        break;
      }
      default:
        ts.putback(t);
        return left;
    }
  }
}

double expression(){
  double left = term();
  //Token_stream ts;
  Token t = ts.get();
  while(true){
    switch(t.kind){
      case '+':
        left += term();
        t = ts.get();
        break;
      case '-':
        left -= term();
        t = ts.get();
        break;
      default:
        ts.putback(t);
        return left;
    }
  }
}

int main(){
  cout<<"\nWelcome to the Calculator...";
  cout<<"\nEnter the expression to compute:";
  cout<<"\n(Allowed operations are: + - * /)\n--->";
  double val = 0;
  try{
    while(cin){
      Token t = ts.get();
      if (t.kind=='q'){
        break;
      }
      if (t.kind==';'){
        cout<<"="<<val<<"\n";
        continue;
      }
      else{
        ts.putback(t);
      }
      val = expression();
    }
    keep_window_open();
  }
  catch(exception& e){
    cout<<"\n"<<e.what();
    keep_window_open();
    return 1;
  }
  catch(...){
    cout<<"\nUnknown Error!";
    keep_window_open();
    return 2;
  }
  return 0;
}
