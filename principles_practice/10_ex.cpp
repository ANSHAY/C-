#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

struct Reading{
  int hour;
  double temp;
  char unit;
};

double median(vector<double>& temps){
  int size = temps.size();
  double med;
  if(size%2){
    med = temps[size/2];
  }
  else{
    med = (temps[size/2]+temps[size/2+1])/2;
  }
  return med;
}

void one(){
  cout<<"\nEnter filename: ";
  string fname;
  cin>>fname;
  ifstream fin{fname};
  int sum=0;
  for(int i; fin>>i;){
    sum+=i;
  }
  cout<<"\nSum of integers in the file is: "<<sum;
}

void two(){
  string filename = "raw_temps.txt";
  Reading r;
  ofstream fout{filename};
  for (int i=0; i<50; ++i){
    r.hour = rand() % 24;
    r.temp = rand() % 200 - 50;
    r.unit = (rand() % 2) ? 'c' : 'f';
    fout<<r.hour<<' '<<r.temp<<' '<<r.unit<<'\n';
  }
}

void three(){
  string filename = "raw_temps.txt";
  ifstream fin{filename};
  vector<double> temps;
  Reading r;
  double sum=0;
  while(fin){
    fin>>r.hour>>r.temp>>r.unit;
    if(r.unit == 'c'){
      r.temp = r.temp*9/5+32;
    }
    sum+=r.temp;
    temps.push_back(r.temp);
  }
  int size = temps.size();
  double med;
  sort(temps.begin(), temps.end());
  med = median(temps);
  cout<<"\nMean of readings: "<<sum/size;
  cout<<"\nMedian of readings: "<<med;
}

int main(){
  //one();
  two();
  three();
  return 0;
}
