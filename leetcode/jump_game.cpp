class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        if(nums.size()==1) return true;
        int index = nums.size()-1;
        for(int i=nums.size()-2; i>=0; --i){
            if(i + nums[i] >= index){
                if(i==0) return true;
                index = i;
            }
        }
        return false;
    }
};
