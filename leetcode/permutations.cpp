class Solution {
public:
    vector<vector<int>> res;

    bool isValid(vector<int>& cur, int cand){
        for(int i:cur){
            if(i==cand) return false;
        }
        return true;
    }

    void backtrack(vector<int>& nums, vector<int>& cur, int k){
        if(k==0){
            res.push_back(cur);
        }
        for(int i:nums){
            if(isValid(cur, i)){
                cur.push_back(i);
                backtrack(nums, cur, k-1);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return res;
        vector<int> cur;
        backtrack(nums, cur, nums.size());
        return res;
    }
};
/* testcases
[1,2,3]
[]
[1]
[1,2]
[1,2,3,4,5]
[1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99,00]
*/
