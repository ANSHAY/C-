class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int t;
        for(int i=0; i<nums.size(); ++i){
            t = abs(nums[i])-1;
            if(nums[t]<0) res.push_back(t+1);
            else nums[t] = -nums[t];
        }
        return res;
    }
};
