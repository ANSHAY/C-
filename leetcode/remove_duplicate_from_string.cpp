class Solution {
public:
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
};
/* testcases
[1,1,2]
[]
[2,1,4,7,8,5,6,98,5,2,3,6,5,4,1,2,5,8,9,6,5,4]
[1,1,1,1,1,1,1,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,8,8,8,8,8]
[4,4,4,4,4,4,4,4,4,4,4,4]
[1]
[1,2,2,2,]
[1,1,2,2,2]
*/
