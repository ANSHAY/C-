class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = INT_MIN;
        int index;
        for(int i=0; i<nums.size();++i){
            if(nums[i]>max){ max=nums[i]; index=i;}
        }
        for(int i=0; i<nums.size(); ++i){
            if(i!=index && max<2*nums[i]) return -1;
        }
        return index;
    }
};
