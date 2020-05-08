class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty()) return -1;
        map<char, int> mmp;
        for (char c:s){
            mmp[c]++;
        }
        int res=0;
        for(char c:s){
            if(mmp[c]==1) return res;
            res++;
        }
        return -1;
    }
};
