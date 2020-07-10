class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        if(n<=2) return res;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; ++i){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int c = nums[i] + nums[l] + nums[r];
                if(c==0){
                    s.insert({nums[i], nums[l], nums[r]});
                    l++; r--;
                }
                else if(c<0) l++;
                else r--;
            }
        }
        for(auto n:s){
            res.push_back(n);
        }
        return res;
    }
};
