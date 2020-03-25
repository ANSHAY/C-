#include<iostream>
#include<fstream>
using namespace std;

int main(){
  string file1, file2, fileout;
  cout<<"\nEnter filename 1: ";
  cin>>file1;
  cout<<"\nEnter filename 2: ";
  cin>>file2;
  cout<<"\nEnteer output file name: ";
  cin>>fileout;
  ifstream fin1{file1};
  ifstream fin2{file2};
  ofstream fout{fileout};
  string line;
  while(getline(fin1,line)){
    fout<<line<<"\n";
  }
  while(getline(fin2,line)){
    fout<<line<<"\n";
  }
  return 0;
}
