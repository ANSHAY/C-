/* Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.
*/

// brute force
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<=i+k; j++){
                if(j<nums.size()){
                    if(abs(nums[j]-nums[i]) <= t) return true;
                }
            }
        }
        return false;
    }
};

// sort first to reduce time 
class Solution {
public:
    struct strc{
        long long val;
        int ind;
    };
    
    static bool comp(strc& s1, strc& s2){
        if(s1.val == s2.val){
            return s1.ind < s2.ind;
        }
        else{
            return s1.val < s2.val;
        }
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<strc> sorted_num;
        for(int i=0; i<nums.size(); i++){
            sorted_num.push_back(strc{nums[i], i});
        }
        // sort the vector
        sort(sorted_num.begin(), sorted_num.end(), comp);
        for(int i=1; i<nums.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(abs(sorted_num[i].val-sorted_num[j].val) <= t){
                    if(abs(sorted_num[i].ind-sorted_num[j].ind)<=k) return true;
                }
                else{
                    break;
                }
            }
        }
        return false;
    }
};