/*
Given an input string, reverse the string word by word.
*/
class Solution {
public:
    string revWords(string s, int l, int r) {
        if(l>r) return "";
        string t="";
        while(l<=r && s[l]==' ') l++;
        while(l<=r && s[l]!=' '){
            t+=s[l];
            l++;
        }
        return l>r? t: revWords(s, l, r) + ' ' + t;
    }
    string reverseWords(string s) {
        int l=0, r = s.size()-1;
        if(l>r) return "";
        while(l<=r && s[l]==' ') l++;
        while(l<=r && s[r]==' ') r--;
        return revWords(s, l, r);
    }
};
/* testcases
"the sky is blue"
""
"a"
"dfcec"
"vefv erfr"
"    e   efcve   ercer     "
*/
