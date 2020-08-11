/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

    Return true if there exists i, j, k
    such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.

Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return false;
        int b=INT_MIN, s=INT_MIN, i;
        for(i=1; i<n; ++i){
            if(nums[i]<=nums[i-1]) continue;
            b = nums[i];
            s = nums[i-1];
            break;
        }
        if(i>=n) return false;
        for(int j=i; j<n; ++j){
            if(nums[j]>b) return true;
            if(nums[j]<=s) s=nums[j];
            else b=nums[j];
        }
        return false;
    }
};
