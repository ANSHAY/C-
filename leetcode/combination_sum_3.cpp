/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

    All numbers will be positive integers.
    The solution set must not contain duplicate combinations.

*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n, int j=1) {
        vector<vector<int>> res;
        if(k==0 || n<=0 || k>9 || n>45) return res;
        if(k==1){
            if(n<=9 && n>=j) res.push_back(vector<int>{n});
            return res;
        }
        for(int i=j; i<=9; i++){
            vector<vector<int>> temp = combinationSum3(k-1, n-i, i+1);
            if(temp.empty()) continue;
            for(auto v:temp){
                v.push_back(i);
                res.push_back(v);
            }
        }
        return res;
    }
};
