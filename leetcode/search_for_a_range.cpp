/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].
*/
class Solution {
public:
    int bins(vector<int>& nums, int l, int r, int t){
        int m;
        while(l<=r){
            m = l + (r-l)/2;
            if(nums[m]==t) return m;
            else if(nums[m]<t) l = m+1;
            else if(nums[m]>t) r = m-1;
        }
        return -1;
    }
    int ledge(vector<int>& nums, int l, int r, int t){
        int m;
        while(l<r){
            m = l + (r-l)/2;
            if(nums[m]==t) r = m;
            else l = m+1;
            if(nums[l]==t) return l;
        }
        return l;
    }
    int redge(vector<int>& nums, int l, int r, int t){
        int m;
        while(l<=r){
            m = l + (r-l)/2;
            if(nums[m]==t) l = m+1;
            else r = m-1;
            if(nums[r]==t) return r;
        }
        return r;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int ind = bins(nums, l, r, target);
        if(ind==-1) return {-1, -1};
        l = ledge(nums, l, ind, target);
        r = redge(nums, ind, r, target);
        return {l, r};
    }
};
