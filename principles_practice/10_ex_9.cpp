#include<iostream>
#include<fstream>
using namespace std;

int main(){
  string file1, file2, fileout;
  ifstream fin{"testcases.txt"};
  fin>>file1;
  fin>>file2;
  fin>>fileout;
  ifstream fin1{file1};
  ifstream fin2{file2};
  ofstream fout{fileout};
  string word1, word2;
  fin1>>word1;
  fin2>>word2;
  while(fin1 && fin2){
    if(word1 < word2){
      fout<<word1;
      fin1>>word1;
    }
    else{
      fout<<word2;
      fin2>>word2;
    }
    fout<<' ';
  }
  while(fin1){
    fout<<word1<<' ';
    fin1>>word1;
  }
  while(fin2){
    fout<<word2<<' ';
    fin2>>word2;
  }
  return 0;
}
