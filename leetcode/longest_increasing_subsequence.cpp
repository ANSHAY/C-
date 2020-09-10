/*
Given an unsorted array of integers, find the length of longest increasing subsequence.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=0) return 0;
        vector<int> lenths(nums.size(), 1);
        int res=1;
        for(int i=0; i<nums.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(nums[j]<nums[i]){
                    lenths[i] = max(lenths[j]+1, lenths[i]);
                    res = max(res, lenths[i]);
                }
            }
        }
        return res;
    }
};
