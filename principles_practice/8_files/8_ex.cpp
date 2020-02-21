#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void ex1();

void print(vector<int>& v, string s){
    cout<<s<<": ";
    for (int i:v){
      cout<<i<<"\t";
    }
    cout<<"\n";
}

void fibonacci(int x, int y, vector<int>& v, int n){
  v.push_back(x);
  v.push_back(y);
  for (int i=2; i<n; ++i){
    v.push_back(v[i-1]+v[i-2]);
  }
}

void ex4(){
  int num=0;
  vector<int> v;

  cout<<"approx. of biggest int: "<<num;
}
vector<int> reverse(vector<int>& v){
  vector<int> rv;
  for (int i=v.size()-1; i>=0; --i){
    rv.push_back(v[i]);
  }
  return rv;
}

void swap(int& a, int& b){
  int temp = a; a=b; b=temp;
}

void reverse_inplace(vector<int>& v){
  int s = v.size();
  for (int i=0; i<s/2; ++i){
    swap(v[i], v[s-i-1]);
  }
}

vector<int> v;
vector<string> vs;

void callChoice(int ch){
  switch(ch){
    case 1:
      //ex1();
      break;
    case 2:
      break;
    case 3:
      fibonacci(0, 1, v, 10);
      print(v, "ex3");
      break;
    case 4:
      ex4();
      break;
    case 5:
      print(v, "ex5 launch");
      fibonacci(0, 1, v, 10);
      print(v, "ex5");
      v = reverse(v);
      print(v, "reverse v");
      reverse_inplace(v);
      print(v, "ex5 result");
      break;
    default:
      runtime_error("\nwrong choice");
  }
  cout<<endl;
}

int main(){
  cout<<"\nEnter ex number: ";
  int ch;
  cin>>ch;
  callChoice(ch);
  return 0;
}
