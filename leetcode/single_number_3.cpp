/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, bool> mp;
        for(int n:nums){
            mp[n] = !mp[n];
        }
        for(int n:nums){
            if(mp[n]) res.push_back(n);
        }
        return res;
    }
};
