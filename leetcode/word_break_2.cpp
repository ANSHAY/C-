/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res, lastwords, sents;
        unordered_map<string, bool> words;
        for(string w:wordDict){
            words[w]=true;
        }
        sents.push_back("");
        lastwords.push_back("");
        for(char c:s){
            int n=sents.size();
            for(int i=0; i<n; ++i){
                sents[i] += c;
                lastwords[i] += c;
                if(words[lastwords[i]]){
                    sents.push_back(sents[i]+' ');
                    lastwords.push_back("");
                }
            }
        }
        for(int i=0; i<lastwords.size(); i++){
            if(words[lastwords[i]]){
                res.push_back(sents[i]);
            }
        }
        return res;
    }
};
