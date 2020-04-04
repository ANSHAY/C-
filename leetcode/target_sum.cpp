class Solution {
public:
    int ways=0;
    int findTargetSumWays(vector<int>& nums, int S, int t=0, int i=0) {
        if (i>=nums.size()){
            if(S==t){
                ways++;
            }
            return ways;
        }
        // base condition
        int n = nums[i];
        // plus case
        findTargetSumWays(nums, S, t+n, i+1);
        // minus case
        findTargetSumWays(nums, S, t-n, i+1);
        return ways;
    }
};
