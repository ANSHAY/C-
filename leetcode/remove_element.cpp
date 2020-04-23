class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pivot=0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]!=val){
                nums[pivot++] = nums[i];
            }
        }
        return pivot;
    }
};
