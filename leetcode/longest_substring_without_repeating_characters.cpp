/*
Given a string, find the length of the longest substring without repeating characters.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j=0, l=0;
        vector<int> mp(128, -1);
        for(int i=0; i<s.size(); ++i){
            if(mp[s[i]]>=j){
                l=max(l,i-j);
                j = mp[s[i]]+1;
                mp[s[i]] = i;
            }
            else{
                mp[s[i]] = i;
            }
        }
        return max(l, int(s.size()-j));
    }
};

////////////////////////////////////////////////////////////

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0, l=0;
        unordered_map<char, bool> mp;
        while(i<s.size()){
            if(mp[s[i]]){
                l=max(l,i-j);
                while(s[j]!=s[i]){
                    mp[s[j]] = false;
                    j++;
                }
                j++;
            }
            else{
                mp[s[i]] = true;
            }
            i++;
        }
        return max(l, i-j);
    }
};
