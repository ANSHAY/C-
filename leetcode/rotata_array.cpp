class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty() || k==0) return;
        k = k%nums.size();
        vector<int> res;
        for(int i=nums.size()-k; i<nums.size(); ++i){
            res.push_back(nums[i]);
        }
        for(int i=0; i<nums.size()-k; ++i){
            res.push_back(nums[i]);
        }
        nums = res;
    }
};
