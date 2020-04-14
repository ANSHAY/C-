class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> P(nums.size()+1);
        for(int i=0;i<nums.size();++i){
            P[i+1] = P[i]+nums[i];
        }
        for(int i=0;i<nums.size();++i){
            if(P[i] == P[P.size()-1]-P[i+1]) return i;
        }
        return -1;
    }
};
