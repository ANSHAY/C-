
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include"Roman_int.h"
using namespace std;
inline void keep_window_open(){
  cout<<"\nExiting the program!\n";
  char ch;
  cin>>ch;
}
void error(string err, string s=""){
	cerr<<s<<endl;
	throw runtime_error(err);
}
//#include "std_lib_facilities.h"
//------------------------------------------------------------------------------
// define input and output streams
ostream& os = cout;
istream& is = cin;

//------------------------------------------------------------------------------
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string s) :kind(ch), name(s) {}
};
//------------------------------------------------------------------------------

struct Variable {
	string name;
	double value;
  bool isConst;
	Variable(string n, double v) :name(n), value(v), isConst(false) { }
  Variable(string s, double v, bool c): name(s), value(v), isConst(c) { }
};
//------------------------------------------------------------------------------

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};
//------------------------------------------------------------------------------

class SymbolTable{
private:
  vector<Variable> var_table;
public:
  double set(string s, double v);
  double get(string s);
  bool is_declared(string s);
  bool declare(string s, double v, bool c);
  bool addDefaultSymbols();
  SymbolTable(){
    addDefaultSymbols();
  }
};
//------------------------------------------------------------------------------

//--- constant characters for Tokens for internal use
const char let = 'L';
const char quit = 'Q';
const char help = 'h';
const char print = ';';
const char number = '8';
const char name = 'a';
const char sqroot = 's';
const char power = 'p';
const char constant = 'c';
const char from = 'f';
const char to = 't';
const string prompt = "> ";
const string result = "= ";


//--- declaration keywords that are input by user for corresponding feature
const char dec_let = '#';
const string dec_quit = "q";
const string dec_help_h = "h";
const string dec_help_H = "H";
const string dec_pow = "pow";
const string dec_sqrt = "sqrt";
const string dec_const = "const";

//--- command keywords for I/O operations from/to a file
const string com_from = "from";
const string com_to = "to";

//--- default variable
const string k = "k";
const string pi = "pi";
const string e = "e";
const double k_val = 1000;
const double pi_val = 3.14;
const double e_val = 2.73;
vector<Variable> defaultSymbols = {Variable("k", 1000),
                                   Variable("pi", 3.14),
                                   Variable("e", 2.73)};

//--- member function declarations----------------------------------------------

//--- Token_stream--------------------------------------------------------------
Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	while(is.get(ch)){
  	switch (ch) {
    case ' ':
      break;
    case '\n':
    case print:
      return Token(print);
  	case '(':
  	case ')':
  	case '+':
  	case '-':
  	case '*':
  	case '/':
  	case '%':
  	case '=':
  	case ',':
  		return Token(ch);
  	case '.':
  	case '0':
  	case '1':
  	case '2':
  	case '3':
  	case '4':
  	case '5':
  	case '6':
  	case '7':
  	case '8':
  	case '9':
  	{
      is.unget();
  		double val;
  		is >> val;
  		return Token(number,val);
  	}
    case 'I':
  	case 'V':
    case 'X':
  	case 'L':
  	case 'C':
  	case 'D':
  	case 'M':
  	{
        is.unget();
        Roman_int r;
        is>>r;
        return Token(number, r.as_int());
    }
  	case dec_let:
  		return Token(let);
  	default:
  		if (isalpha(ch)) {
  			string s;
  			s += ch;
  			while(is.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s+=ch; //err1
  			is.unget();
  			if (s == dec_quit) return Token(quit);											         //err2
  			if (s == dec_sqrt) return Token(sqroot);
  			if (s == dec_pow) return Token(power);
        if (s == dec_const) return Token(constant);
        if (s == dec_help_h || s == dec_help_H) return Token(help);
        if (s == com_from) return Token(from);
        if (s == com_to) return Token(to);
  			return Token(name,s);
  		}
  		error("Bad token");
  	}
  }
}

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (is.get(ch))
		if (ch==c || ch=='\n') return;
	error("\nBad statement");
}

//--- SymbolTable---------------------------------------------------------------
double SymbolTable::set(string s, double v){
  for (int i=0; i<var_table.size(); ++i){
    if (var_table[i].name==s){
      if (var_table[i].isConst) error("\nset: cant change a constant");
      var_table[i].value = v;
      return v;
    }
  }
  error("\nset: undefined variable");
}

double SymbolTable::get(string s){
  for (int i=0; i<var_table.size(); ++i){
    if (var_table[i].name==s){
      return var_table[i].value;
    }
  }
  error("\nget: undefined variable");
}

bool SymbolTable::is_declared(string s){
  for (int i=0; i<var_table.size(); ++i){
    if (var_table[i].name==s){
      return true;
    }
  }
  return false;
}

bool SymbolTable::declare(string s, double v, bool c){
  if (is_declared(s)) error("\ndeclare: variable already exists");
  var_table.push_back(Variable(s, v, c));
  return true;
}

bool SymbolTable::addDefaultSymbols(){
	declare(k, k_val, true);
  declare(pi, pi_val, true);
  declare(e, e_val, true);
  return true;
}
//------------------------------------------------------------------------------
Token_stream ts;
SymbolTable symbols;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
    double d = expression();
		t = ts.get();
		if (t.kind != ')') {
			ts.unget(t);
			error("')' expected");														//err3
		}
		return d;
	}
	case '-':
		return - primary();
	case number:
		return t.value;
	case name:
		return symbols.get(t.name);
	case sqroot:
	{
		Token t = ts.get();
		if (t.kind != '(') {
			ts.unget(t);
			error("'(' expected");
		}
		double d = expression();
		if (d<0) error("\nRoot of negative number not available");
		t = ts.get();
		if (t.kind != ')') {
			ts.unget(t);
			error("')' expected");
		}
		return sqrt(d);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '('){
			ts.unget(t);
			error("\npower: ( expected");
		}
		double x = expression();
		t = ts.get();
		if (t.kind != ','){
			ts.unget(t);
			error("\npower: improper arguments");
		}
		int i = int(expression());
		t = ts.get();
		if (t.kind != ')'){
			ts.unget(t);
			error("\npower: ')' expected");
		}
		return pow(x,i);
	}
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{
      double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case name:
			left *= symbols.get(t.name);
			break;
		case '%':
		{
			double d = primary();
			if (d==0) error("\ndivide by zero");
			left = fmod(left, d);
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
  bool isConst = false;
	Token t = ts.get();
  if (t.kind==constant){
    isConst = true;
    t = ts.get();
  }
	if (t.kind != name) error ("name expected in declaration");
	string var_name = t.name;
	//if (is_declared(var_name)) error(var_name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,var_name);
	double d = expression();
	symbols.declare(var_name,d,isConst);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	case name:
	{
		char ch;
    while(is.get(ch)){
      switch(ch){
      case ' ':
        continue;
  		case '=':
      {
  			double d = expression();
  			symbols.set(t.name, d);
  			return d;
  		}
  		default:
      {
  			is.unget();
  			ts.unget(t);
  			return expression();
  		}
      }
    }
	}
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

void displayHelpMenu(){
  os<<"\nHelp is on the way!!";
}

void calculate()
{
	while(true)
  try {
		os << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
    if (t.kind == help){
      displayHelpMenu();
      continue;
    }
    if (t.kind == to){
      string filename;
      is>>filename;
      filebuf fout;
      fout.open(filename, ios::out);
      os.rdbuf(&fout);
      os<<"this went to file?";
      continue;
    }
    if (t.kind == from){
      string filename;
      is>>filename;
      filebuf fin;
      fin.open(filename, ios::in);
      is.rdbuf(&fin);
      continue;
    }
		ts.unget(t);
		os << result << statement() << endl;
	}
	catch(runtime_error& e) {
		clean_up_mess();
		cerr << e.what() << endl;
	}
}

int main()
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (is >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (is>>c && c!=';');
		return 2;
	}
