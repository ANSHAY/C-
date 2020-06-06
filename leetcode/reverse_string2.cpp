class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = s.size();
        for(int i=0, j=l-1; i<j; ++i, --j){
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }
};
