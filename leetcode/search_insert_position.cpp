class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int l=0, r=nums.size()-1, m;
        if(target<nums[0]) return 0;
        if(target>nums.back()) return nums.size();
        while(l<=r){
            m = l+((r-l)>>1);
            if(nums[m] == target) return m;
            if(nums[m]<target) l = m+1;
            else r = m-1;
        }
        return max(m,l);
    }
};
