//#include"std_lib_facilities.h"
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

inline void keep_window_open(){
  char ch;
  cin>>ch;
}

void merge(int arr[], int start, int pivot, int end){
  int temp_arr[end-start+1];
  int i=start, j=pivot+1, k=0;
  while (i<=pivot && j<=end){
    if(arr[i]<=arr[j]){
      temp_arr[k++] = arr[i++];
    }
    else{
      temp_arr[k++] = arr[j++];
    }
  }
  if(i>pivot){
    while(j<=end){
      temp_arr[k++] = arr[j++];
    }
  }
  else if(j>end){
    while(i<=pivot){
      temp_arr[k++] = arr[i++];
    }
  }
  i=start;
  k=0;
  while(i<=end){
    arr[i++] = temp_arr[k++];
  }
}

void print_arr(int arr[], int size){
  cout<<"\narray: ";
  for(int i=0;i<size;i++){
    cout<<arr[i]<<' ';
  }
  cout<<endl;
}
void merge_sort(int arr[], int size, int start, int end){
  if (start==end){

  }
  else{
    int pivot = (start+end)/2;
    merge_sort(arr, size, start, pivot);
    merge_sort(arr, size, pivot+1, end);
    merge(arr, start, pivot, end);
  }
  //cout<<endl;
}

int main(){
  int size;
  cout<<"\nEnter number of integers:";
  cin>>size;

  int int_arr[size];
  cout<<"\nEnter the "<<size<<" integers:\n";
  for (int i=0;i<size;i++){
    cin>>int_arr[i];
  }
  merge_sort(int_arr, size, 0, size-1);
  cout<<endl;
  cout<<int_arr[0];
  for (int i=1;i<size;i++){
    cout<<','<<int_arr[i];
  }
  cout<<endl;
  return 0;
}
