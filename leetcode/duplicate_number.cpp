class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=nums[0], f=nums[0];
        while (true){
            s = nums[s];
            f = nums[nums[f]];
            if(s==f) break;
        }
        s = nums[0];
        while(s!=f){
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};
