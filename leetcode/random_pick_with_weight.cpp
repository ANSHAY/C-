class Solution {
public:
    vector<int> cum;
    Solution(vector<int>& w) {
        cum.push_back(w[0]);
        for(int i=1; i<w.size(); ++i){
            cum.push_back(w[i]+cum[i-1]);
        }
    }

    int pickIndex() {
        int r = rand() % cum[cum.size()-1];
        for(int i=0; i<cum.size(); ++i){
            if(r<cum[i]) return i;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
