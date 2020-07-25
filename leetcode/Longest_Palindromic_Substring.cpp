class Solution {
public:
    bool isPal(unordered_map<pair<int, int>, bool>& dp, string& s, int l, int r){
        if(r<=l) return true;
        pair<int, int> p;
        p = make_pair(l, r);
        if(dp.count(p)>0) return dp[p];
        if(s[l]!=s[r]){
            dp[p] = false;
            return false;
        }
        dp[p] = isPal(dp, s, l+1, r-1);
        return dp[p];
    }
    string lpd(unordered_map<pair<int, int>, bool>& dp, string& s, int l, int r){
        if(r<l) return "";
        if(isPal(dp, s, l, r)){
            return s.substr(l, r-l+1);
        }
        string s1 = lpd(dp, s, l+1, r);
        string s2 = lpd(dp, s, l, r-1);
        return s1.size()>=s2.size()?s1:s2;
    }

    string longestPalindrome(string s) {
        unordered_map<pair<int, int>, bool> dp;
        string res;
        return lpd(dp, s, 0, s.size()-1);
    }
};
