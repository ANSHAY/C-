#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Point{
    int x;
    int y;
  public:
    int getx() {return x;}
    int gety() {return y;}
    void setx(int v) {x=v;}
    void sety(int v) {y=v;}
};

ostream& operator<<(ostream& os, Point& p){
  return os<<'('<<p.getx()<<", "<<p.gety()<<')';
}

istream& operator>>(istream& is, Point& p){
  int x, y;
  char ch1, ch2, ch3;
  is>>ch1;
  if(isdigit(ch1)){
    is.unget();
    is>>x>>y;
  }
  else if(ch1=='('){
    is>>x>>ch2>>y>>ch3;
  }
  else {
    is.clear(ios_base::failbit);
    return is;
  }
  if(!is) return is;
  p.setx(x);
  p.sety(y);

  return is;
}

void input_points(vector<Point>& op){
  for (Point p; cin>>p;){
    op.push_back(p);
  }
}

void output_points(vector<Point>& op){
  for(Point p:op){
    cout<<p<<"\n";
  }
}

bool compare(vector<Point>& op, vector<Point>& pp){
  if(pp.size()==op.size()){
    for(int i=0; i<op.size();i++){
      if(op[i].getx() != pp[i].getx() || op[i].gety()!=pp[i].gety()){
        return false;
      }
    }
    return true;
  }
  return false;
}

int main(){
  vector<Point> original_points;
  cout<<"\nEnter 7 points (x,y):\n";
  input_points(original_points);
  output_points(original_points);

  cout<<"\nWrite to file--";
  ofstream fout {"mydata.txt"};
  for (Point p:original_points){
    fout<<p<<"\n";
  }
  fout.close();

  cout<<"\nRead from file--\n";
  ifstream fin {"mydata.txt"};
  vector<Point> processed_points;
  for (Point p; fin>>p;){
    processed_points.push_back(p);
  }
  output_points(processed_points);
  if(!compare(original_points, processed_points)){
    cout<<"\nSomething's wrong!";
  }

  return 0;
}
