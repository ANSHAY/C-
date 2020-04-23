class Solution {
public:
    int findPivot(vector<int> nums, int l, int r){
        if(l>=r) return -1;
        int mid=(l+r)/2;
        if(nums[mid]>nums[mid+1]) return mid;
        int res = findPivot(nums, l, mid);
        if(res==-1){
            res = findPivot(nums, mid+1, r);
        }
        return res;
    }
    int findTarget(vector<int>& nums, int l, int r, int target){
        if(l>r) return -1;
        if(l==r) return nums[l]==target?l:-1;
        int mid=(l+r)/2;
        if(target==nums[mid]) return mid;
        if(target<nums[mid]) return findTarget(nums, l, mid-1, target);
        return findTarget(nums, mid+1, r, target);
    }

    int search(vector<int>& nums, int target) {
        int index = findPivot(nums, 0, nums.size()-1);
        int res = findTarget(nums, 0, index, target);
        if(res == -1){
            res = findTarget(nums, index+1, nums.size()-1, target);
        }
        return res;
    }
};
/* testcases
[4,5,6,7,0,1,2]
0
[4,5,6,7,0,1,2]
3
[]
2
[1]
2
[1]
1
[1,2]
1
[1,2]
2
[1,2]
3
[2,1]
1
[2,1]
2
[2,1]
3
[1,2,3]
1
[1,2,3]
2
[1,2,3]
3
[1,2,3]
4
[3,1,2]
1
[3,1,2]
2
[3,1,2]
3
[3,1,2]
4
[2,3,1]
1
[2,3,1]
2
[2,3,1]
3
[2,3,1]
4
[1,2,3,4]
1
[1,2,3,4]
2
[1,2,3,4]
3
[1,2,3,4]
4
[1,2,3,4]
5
[4,1,2,3]
1
[4,1,2,3]
5
[4,1,2,3]
4
[4,1,2,3]
3
[4,1,2,3]
2
[3,4,1,2]
1
[3,4,1,2]
2
[3,4,1,2]
3
[3,4,1,2]
4
[3,4,1,2]
5
[2,3,4,1]
1
[2,3,4,1]
2
[2,3,4,1]
3
[2,3,4,1]
4
[2,3,4,1]
5
*/
