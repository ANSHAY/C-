// #include "std_lib_facilities.h"
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void ex2(){
  vector<double> temps;
  cout<<"\nEnter temperatures";
  for(double temp; cin>>temp;){
    temps.push_back(temp);
  }
  double sum=0;
  for (double x:temps) sum+=x;
  cout<<"\nAverage Temperature: "<<sum/temps.size();
  sort(temps.begin(), temps.end());
  int t_size = temps.size();
  double med = (t_size%2)?temps[t_size/2]:(temps[t_size/2]+temps[t_size/2+1])/2;
  cout<<"\nMedian temperature: "<<med<<"\n";
}

void ex3(){
  vector<double> dist;
  double sum=0, smallest=999999.9, largest=-1;
  cout<<"\nEnter distances: ";
  for (double dis; cin>>dis;){
    if (dis<=0){
      break;
    }
    dist.push_back(dis);
    sum+=dis;
    if(dis>largest){
      largest = dis;
    }
    if(dis<smallest){
      smallest = dis;
    }
  }
  cout<<"\nTotal distance: "<<sum;
  cout<<"\nsmallest distance: "<<smallest;
  cout<<"\nlargest distance: "<<largest;
  cout<<"\nMean distance: "<<sum/dist.size();
}

void ex4(){
  cout<<"\nGuess a number between 1 and 100!\n";
  char resp;
  int mean, min=1, max=101;
  do{
    mean = (min+max)/2;
    if(min==mean){
      cout<<"\nYou guessed: "<<min;
      return;
    }
    cout<<"\nIs your guess less than "<<mean;
    cin>>resp;
    if(resp=='y'){
      max=mean;
    }
    else if(resp=='n'){
      min=mean;
    }
    else{
      cout<<"\n wrong response";
      exit(0);
    }
  }while(max>=min);
}

int main(){
  int ex_num;
  while(true){
    cout<<"\n\nEnter the exercise number: ";
    cin>>ex_num;
    try{
      switch (ex_num){
        case 2:
          ex2();
          break;
        case 3:
          ex3();
          break;
        case 4:
          ex4();
          break;
        case 0:
          cout<<"\nBye Bye!!!\n";
          exit(0);
        default:
          cout<<"\nWrong Entry.. Try again.";
      }
    }
    catch(...){
      cout<<"\nError. Exiting!";
      exit(0);
    }
  }
}
