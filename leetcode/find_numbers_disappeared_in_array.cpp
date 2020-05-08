class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i=0;
        int j;
        int temp = 0;
        while(i<nums.size()){
            if(nums[i]!=0){
                j = nums[i]-1;
                while(nums[j]!=0){
                    temp=nums[j]-1;
                    nums[j] = 0;
                    j = temp;
                }
            }
            ++i;
        }
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]!=0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
