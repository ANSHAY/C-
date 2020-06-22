class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mmp;
        int res=0;
        for(int n:nums){
            if(mmp[n]==0 || mmp[n]==1){
                res = res^n;
                mmp[n]++;
            }
            else{
                mmp[n]++;
            }
        }
        return res;
    }
};
