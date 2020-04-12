class Solution {
public:
    vector<vector<int>> res;
    bool isValid(vector<int> cur, int cand){
        for(int i:cur){
            if(i==cand) return false;
        }
        return true;
    }
    void backtrack(vector<int>& cur, int n, int k){
        if(n<k) return;
        if(k==0){
            res.push_back(cur);
            return;
        }
        for(int i=n; i>=1; --i){
            if(isValid(cur, i)){
                cur.push_back(i);
                backtrack(cur, i-1, k-1);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        backtrack(cur, n, k);
        return res;
    }
};
