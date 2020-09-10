/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
*/
class Solution {
public:
    bool cmp(string& s, int j, int l){
        for(int i=0; i<l; i++){
            if(s[j+i] != s[i]) return false;
        }
        return true;
    }
    bool isRepeat(string& s, int l){
        for(int i=l; i<=s.size()-l; i+=l){
            if(!cmp(s, i, l)) return false;
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        int l=1, n=s.size();
        for(; l<=n/2; l++){
            if(n%l==0){
                if(isRepeat(s, l)) return true;
            }
        }
        return false;
    }
};
/* testcases
"abab"
"aba"
"abcabcabcabc"
""
"a"
"aa"
"aaa"
"asdasdasdasdasdasdasd"
"asasasas"
"asasasasas"
"abac"
*/
