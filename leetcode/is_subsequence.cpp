class Solution {
public:
    bool isSub(string& s, string& t, int i, int j){
        if(i>=s.size()) return true;
        if(j>=t.size() || (s.size()-i)>(t.size()-j)) return false;
        if(s[i]==t[j]) return isSub(s, t, i+1, j+1);
        return isSub(s, t, i, j+1);
    }
    bool isSubsequence(string s, string t) {
        return isSub(s, t, 0, 0);
    }
};
