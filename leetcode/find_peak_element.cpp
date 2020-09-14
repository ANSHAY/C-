/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=n-1, m;
        if(n<=1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        while(l<r){
            m = (r-l)/2 + l;
            if(m==l) return nums[l]>nums[r]?l:r;
            if(nums[m]<nums[m+1]) l=m;
            else r=m;
        }
        return l;
    }
};
