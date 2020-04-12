class Solution {
public:
    vector<int> merge(vector<int>& left, vector<int>& right){
        vector<int> res;
        int l=0,r=0;
        while(l<left.size() && r<right.size()){
            if(left[l]<=right[r]){
                res.push_back(left[l++]);
            }
            else{
                res.push_back(right[r++]);
            }
        }
        while(l<left.size()){
            res.push_back(left[l++]);
        }
        while(r<right.size()){
            res.push_back(right[r++]);
        }
        return res;
    }

    vector<int> merge_sort(vector<int>& nums, int start, int end){
        if(start>=end) return vector<int>{nums[start]};
        int mid = (start+end)/2;
        vector<int> left = merge_sort(nums, start, mid);
        vector<int> right = merge_sort(nums, mid+1, end);
        return merge(left, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.empty()) return vector<int>();
        return merge_sort(nums, 0, nums.size()-1);
    }
};
/* testcases
[5,2,3,1]
[5,1,1,2,0,0]
[2,1,4,5,8,7,5,6,9,8,56,3,2,0,1,2,6,54,8,9,5]
[0,0,0,0,0,0,0,0,0,0]
[5]
[5,8,7,9,6,5,8]
[0,1,2,3,4,5,6,7,8,9]
[6,6,6,6,6,6,6]
*/
