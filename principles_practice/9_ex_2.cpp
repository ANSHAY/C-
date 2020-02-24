#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Name_pairs{
  vector<string> name;
  vector<double> age;
public:
  void read_names();
  void read_ages();
  void print();
  void sort();
  vector<string>& get_name(){ return name;}
  vector<double>& get_age(){ return age;}
};

ostream& operator<<(ostream& os, Name_pairs& np);

void Name_pairs::read_names(){
  int n;
  string nm;
  cout<<"\nEnter number of name age pairs: ";
  cin>>n;
  cout<<"\nInput names (comma pr enter seperated):\n";
  for (int i=0;i<n;++i){
    cin>>nm;
    name.push_back(nm);
  }
}

void Name_pairs::read_ages(){
  cout<<"\nEnter ages for each name--";
  double a;
  for (string nm : name){
    cout<<"\n"<<nm<<": ";
    cin>>a;
    age.push_back(a);
  }
}

void Name_pairs::print(){
  cout<<"\nName age pairs are:";
  for (int i=0; i<name.size(); ++i){
    cout<<"\n("<<name[i]<<", "<<age[i];
  }
}

void Name_pairs::sort(){
  vector<string> temp{name};
  vector<double> temp_age{age};
  std::sort(name.begin(), name.end());
  for (int j=0; j<name.size(); ++j){
    for (int i=0; i<name.size(); ++i){
      if(name[j]==temp[i]){
        age[j] = temp_age[i];
      }
    }
  }
}

ostream& operator<<(ostream& os, Name_pairs& np){
  os<<"\nName age pairs are:";
  for (int i=0; i<np.get_name().size(); ++i){
    os<<"\n("<<np.get_name()[i]<<", "<<np.get_age()[i];
  }
  return os;
}

int main(){
  return 0;
}
