class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res=INT_MAX, cur=0;
        int j=0, i=0;
        while(true){
            if(cur>=s && j<i){
                res = min(res, i-j);
                cur-=nums[j];
                j++;
            }
            else if(i<nums.size()){
                cur+=nums[i];
                i++;
            }
            else{
                break;
            }
        }
        if(res==INT_MAX) return 0;
        return res;
    }
};
