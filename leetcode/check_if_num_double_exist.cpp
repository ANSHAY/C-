class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, bool> exist;
        for(int n:arr){
            if(exist[2*n]) return true;
            if(n%2==0 && exist[n/2]) return true;
            exist[n] = true;
        }
        return false;
    }
};
