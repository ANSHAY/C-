#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void keep_window_open(){
  cin.clear();
  char ch;
  cin>>ch;
}

int main(){
  try{
    // code with issues
    //Cout<<"Success!\n";
    //cout<<"Successz!\n;
    //cout<<"Success"<<!\n'
    //cout<<success<<'\n';
    //string res=7; vector<int> v(10); v[5]=res; cout<<"Success!\n";
    //vector<int> v(10); v(5)=7; if (v(5)!=7) cout<<"Success!\n";
    //if(cond) cout<<"Success!\n"; else cout<<"Fail!\n";
    //bool c=false; if(c) cout<<"Success!\n";else cout<<"Fail!\n";
    //string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
    //string s = "ape"; if (s=="fool") cout << "Success!\n";
    //string s = "ape"; if (s=="fool") cout < "Success!\n";
    //string s = "ape"; if (s+"fool") cout < "Success!\n";
    //vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n";14. vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
    //string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];
    //if (true) then cout << "Success!\n"; else cout << "Fail!\n";
    //int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
    //string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i];
    //vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
    //int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";
    //int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n";
    //string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];
    //int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n";
    //int x = 4; double d = 5/(x–2); if (d=2*x+0.5) cout << "Success!\n";
    //cin << "Success!\n";

    // corrected code
    cout<<"1 Success!\n";
    cout<<"2 Success!\n";
    cout<<"3 Success!"<<'\n';
    cout<<"4 Success"<<'\n';
    int res=7; vector<int> v(10); v[5]=res; cout<<"5 Success!\n";
    vector<int> v2(10); v2[5]=7; if (v2[5]==7) cout<<"6 Success!\n";
    bool cond=true; if(cond) cout<<"7 Success!\n"; else cout<<"7 Fail!\n";
    bool c8=false; if(!c8) cout<<"8 Success!\n";else cout<<"Fail!\n";
    string s9 = "ape"; bool c9 = "fool">s9; if (c9) cout << "9 Success!\n";
    string s10 = "ape"; if (s10!="fool") cout << "10 Success!\n";
    string s11 = "ape"; if (s11!="fool") cout << "11 Success!\n";
    string s12 = "ape"; if (s12<"fool") cout << "12 Success!\n";
    vector<char> v13(5); for (int i=0; i<v13.size(); ++i) ; cout << "13 Success!\n";
    vector<char> v14(5); for (int i=0; i<v14.size(); ++i) ; cout << "14 Success!\n";
    string s15 = "15 Success!\n"; for (int i=0; i<=11; ++i) cout << s15[i];
    if (true) cout << "16 Success!\n"; else cout << "Fail!\n";
    int x17 = 2000; char c17 = x17; if (c17==char(2000)) cout << "17 Success!\n";
    string s = "18 Success!\n"; for (int i=0; i<12; ++i) cout << s[i];
    vector<int>v19(5); for (int i=0; i<=v19.size(); ++i) ; cout << "19 Success!\n";
    int i=0; int j = 9; while (i<10) ++i; if (j<i) cout << "20 Success!\n";
    int x21 = 2; double d21 = 0.5+(x21*2); if (d21==2*x21+0.5) cout << "21 Success!\n";
    string s22 = "22 Success!\n"; for (int i=0; i<=11; ++i) cout << s22[i];
    int i23=0,j23=0; while (i23<10) ++i23; if (j23<i23) cout << "23 Success!\n";
    int x24 = 4; double d24 = 5/(x24-2); if (d24!=2*x24+0.5) cout << "24 Success!\n";
    cout << "25 Success!\n";
    // .............
    keep_window_open();
    return 0;
  }
  catch(exception& e){
    cerr<<"error: "<<e.what()<<'\n';
    keep_window_open();
    return 1;
  }
  catch(...){
    cerr<<"oops! unknown exception!\n";
    keep_window_open();
    return 2;
  }
}
