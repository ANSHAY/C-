/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        int i=n, count=0;
        while(i>=0 && s[i]==' ') i--;
        while(i>=0 && s[i]!=' ') {i--; count++;}
        return count;
    }
};
