class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mmp;
        for(int i=0; i<numbers.size(); ++i){
            if(mmp[target-numbers[i]]) return vector<int>{mmp[target-numbers[i]], i+1};
            mmp[numbers[i]] = i+1;
        }
        return vector<int>();
    }
};
