class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> mmp;
        vector<int> sum(nums.size()+1);
        int res=0;
        mmp[0] = -1;
        sum[0] = 0;
        for(int& n:nums){
            if(n==0) n=-1;
        }
        for(int i = 0; i<nums.size();++i){
            sum[i+1] = sum[i]+nums[i];
            if(mmp.count(sum[i+1])){
                res = max(res, i-mmp[sum[i+1]]);
            }
            else{
                mmp[sum[i+1]] = i;
            }
        }
        return res;
    }
};
