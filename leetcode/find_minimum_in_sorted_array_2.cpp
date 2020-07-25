class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=nums.size()-1;
        while(i>0){
            if(nums[i-1]>nums[i]) return nums[i];
            i--;
        }
        return nums[i];
    }
};
