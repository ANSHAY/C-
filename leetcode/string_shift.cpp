class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shifts) {
        if(s=="") return s;
        if(shifts.empty()) return s;
        int shift=0;
        for(vector<int> v:shifts){
            if(v[0]==1) shift+=v[1];
            else shift-=v[1];
        }
        string res;
        int pivot;
        if(shift<0){
            shift = -shift%s.size();
            pivot = shift;
        }
        else{
            shift = shift%s.size();
            pivot = s.size()-shift;
        }
        for(int i=pivot; i<s.size(); ++i){
            res+=s[i];
        }
        for(int i=0; i<pivot;++i){
            res+=s[i];
        }
        return res;
    }
};
