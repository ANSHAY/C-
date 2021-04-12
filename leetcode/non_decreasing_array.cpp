class Solution {
public:
    int cp(vector<int>& nums, int l, int r){
        int m = l + (r-l)/2;
        if(m==l) return nums[r]>=nums[l]?0:1;
        int nl, nr, cv=0;
        nl=cp(nums, l, m-1);
        if(nl>1) return 2;
        nr=cp(nums, m+1, r);
        if(nr>1) return 2;
        if(nums[m]<nums[m-1] && nums[m]>nums[m+1]) return 2;
        if(nums[m]>=nums[m-1] && nums[m+1]>=nums[m]) cv=0;
        else if(nums[m]>=nums[m-1] && nums[m+1]<nums[m-1]){
            if(m+2>=nums.size()) cv=1;
            else if(nums[m+2]>=nums[m]) cv=1;
            else return 2;
        }
        else if(nums[m]<nums[m-1] && nums[m+1]>=nums[m] && nums[m+1]<nums[m-1]){
            if(m-2<0) cv=1;
            else if(nums[m-2]<=nums[m]) cv=1;
            else return 2;
        }
        else cv=1;
        return nl+nr+cv;
    }
    
    bool checkPossibility(vector<int>& nums) {
        return cp(nums, 0, nums.size()-1) <=1;
    }
};