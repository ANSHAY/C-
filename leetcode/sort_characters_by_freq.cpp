class Solution {
public:
    map<char, int> mmp;
    string res;
    string frequencySort(string s) {
        for(char c:s){
            mmp[c]++;
        }
        vector<pair<char, int>> pairs(mmp.begin(), mmp.end());
        sort(pairs.begin(), pairs.end(), [](auto p1, auto p2){ return p1.second>p2.second;});
        for(auto p:pairs){
            while(p.second>0){
                res+=p.first;
                p.second--;
            }
        }
        return res;
    }
};
