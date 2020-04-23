class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int best=0;
        int cur=0;
        for(int n:nums){
            if(n) cur++;
            else{
                best = cur>best?cur:best;
                cur = 0;
            }
        }
        return max(best, cur);
    }
};
