class Solution {
public:
/*
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=1;
        int i=0, j=0;
        while(true){
            while(i<nums.size() && nums[i]==nums[j]){
                i++;
            }
            if(i==nums.size()) return res;
            j++;
            nums[j]=nums[i];
            res = j+1;
        }
        return res;
    }
*/
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int i=1, p=0;
        while(i<nums.size()){
            if(nums[i] != nums[p]){
                p++;
                nums[p] = nums[i];
            }
            i++;
        }
        return p+1;
    }
};
/* testcases
[1,1,2]
[]
[2,1,4,7,8,5,6,98,5,2,3,6,5,4,1,2,5,8,9,6,5,4]
[1,1,1,1,1,1,1,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,8,8,8,8,8]
[4,4,4,4,4,4,4,4,4,4,4,4]
[1]
[1,2,2,2,7]
[1,1,2,2,2]
*/
