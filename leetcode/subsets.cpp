class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> t;
        res.push_back(t);
        for(int n:nums){
            int s = res.size();
            for(int i=0; i<s; ++i){
                t = res[i];
                t.push_back(n);
                res.push_back(t);
            }
        }
        return res;
    }
};
