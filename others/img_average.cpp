// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>

using namespace std;
vector<vector<int>> randImage(){
    vector<vector<int>> img(500, vector<int>(500));
    for (int i=0; i<500; i++){
        for(int j=0; j<500; j++){
            img[i][j] = rand()%256;
        }
    }
    return img;
}

float avg(vector<vector<int>>& img){
    float avg=0;
    float s=0;
    cout<<"\n in avg"<<img[0][0];
    for (int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            s+=img[i][j];
        }
    }
    avg = s/(10000);
    return avg;
}

vector<int> histogram(vector<vector<int>>& img){
    vector<int> hist(256, 0);
    for(int i=0; i<256; i++){
        hist[i]=0;
    }
    for(int i=0; i<100; i++){
        for(int j=0;j<100; j++){
            hist[img[i][j]]++;
        }
    }
    return hist;
}

float hist_avg(vector<vector<int>>& img){
    cout<<"cp0";
    float s=0.0;
    float d=0.0;
    cout<<"cp1";
    vector<int> hist;
    hist = histogram(img);
    cout<<"cp2";
    for(int i=0; i<256; i++){
        s += hist[i]*i;
        d += hist[i];
    }
    cout<<"cp3";
    return s/d;
}

int main() {
    // Write C code here
    cout<<"Hello world\n";
    vector<vector<int>> img = randImage();
    cout<<img[100][100]<<endl;
    float av=0 , hav=0;
    av = avg(img);
    cout<<"\navg: "<<av<<endl;
    hav = hist_avg(img);
    cout<<"\nhavg: "<<hav<<"\n";
    return 0;
}
