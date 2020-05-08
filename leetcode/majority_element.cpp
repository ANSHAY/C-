class Solution {
public:
    // Moore's voting algo
    int ME(vector<int>& nums, int i){
        int cand = nums[i];
        int que = 1;
        for(int j=i+1; j<nums.size(); ++j){
            que += (nums[j]==cand)? 1:-1;
            if(que==0){
                return ME(nums, j+1);
            }
        }
        return cand;
    }

    int majorityElement(vector<int>& nums) {
        return ME(nums, 0);
    }
};

/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for(int n:nums){
            mp[n]++;
        }
        int l = nums.size()/2;
        for(auto p:mp){
            if(p.second>l) return p.first;
        }
        return 0;
    }
};
*/
