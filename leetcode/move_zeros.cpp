class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0 && i>j){
                nums[j++] = nums[i];
                nums[i] = 0;
            }
            if(nums[j]!=0) j++;
        }
    }
    void moveZeroes1(vector<int>& nums) {
        for(int i=0; i<nums.size();++i){
            if(nums[i]==0){
                for(int j=i+1; j<nums.size(); ++j){
                    if(nums[j]!=0){
                        nums[i] = nums[j];
                        nums[j] = 0;
                        break;
                    }
                }
            }
        }
    }
    /* test cases
    [0,0,0,0,0,0,0,0]
    [0]
    [0,0]
    [5,4,7,9,6,2,5,8,41,2,0,0,0,0,0,1,44,78,4,5,5,6,5,8]
    [0,0,0,0,2,44,7,85,6,8,7,45,4]
    [2,1,4,56,3,2,5,8,79,0,0,0,0,0]
    [0,1,0]
    [0,0,1]
    [1,0,0]
    [52,1,4,5,6,9,8,74,5,2,1,3,6]
    []
    [1,0]
    [0,1]

    */
};
