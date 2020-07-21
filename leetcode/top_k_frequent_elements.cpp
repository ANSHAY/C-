/*
Given a non-empty array of integers, return the k most frequent elements.
*/
class Solution {
public:
    /*bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }*/
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        vector<pair<int, int>> vec;
        unordered_map<int, int> mmp;
        for(int n:nums) mmp[n]++;
        for(auto& p : mmp) vec.push_back(p);
        sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b){return a.second > b.second;});
        for(int i=0; i<k; ++i){
            res.push_back(vec[i].first);
        }
        return res;
    }
};
