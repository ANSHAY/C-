class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mmp;
        for(int n:nums){
            if(mmp[n]) return true;
            mmp[n] = true;
        }
        return false;
    }
};
