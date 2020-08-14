/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.
*/
class Solution {
public:
    unordered_map<char, int> mp;
    int count=0;
    int longestPalindrome(string s) {
        for(char c:s){
            mp[c]++;
        }
        for(auto& p:mp){
            count+=p.second/2;
        }
        return min(count*2+1, (int)s.size());
    }
};
