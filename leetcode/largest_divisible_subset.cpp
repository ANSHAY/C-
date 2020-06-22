class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ls(nums.size(), nums.size());
        vector<int> set_count(nums.size(), 1);
        int max_size=0, max_index=0;
        sort(nums.begin(), nums.end());
        //set_count[nums.size()-1] = 1;
        for(int i=nums.size()-2; i>=0; --i){
            for(int j=i+1; j<nums.size(); ++j){
                if(nums[j]%nums[i]==0){
                    if(set_count[i] < set_count[j]+1){
                        set_count[i] = set_count[j]+1;
                        ls[i] = j;
                        if(set_count[i] > max_size){
                            max_size = set_count[i];
                            max_index = i;
                        }
                    }
                }
            }
        }
        vector<int> res;
        for(int i=max_index; i<nums.size();){
            res.push_back(nums[i]);
            i = ls[i];
        }
        return res;
    }
};
