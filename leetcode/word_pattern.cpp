/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> ptos;
        unordered_map<string, char> stop;
        string w="";
        int i=0, len=pattern.size();
        str += ' ';
        for(char c:str){
            if(c!=' ') w+=c;
            else{
                if(i>=len) return false;
                if(ptos.count(pattern[i])>0 && stop.count(w)>0){
                    if(ptos[pattern[i]] != w || stop[w]!=pattern[i]) return false;
                }
                else if(ptos.count(pattern[i])>0 || stop.count(w)>0){
                    return false;
                }
                else{
                    ptos[pattern[i]] = w;
                    stop[w] = pattern[i];
                }
                i++;
                w = "";
            }
        }
        return i==len;
    }
};
