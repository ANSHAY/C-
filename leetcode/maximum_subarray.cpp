class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int best_sum = INT_MIN;
        for(int i:nums){
            sum+=i;
            if(sum>best_sum){
                best_sum = sum;
            }
            if(sum<0)
                sum=0;
        }
        return best_sum;
    }
};
