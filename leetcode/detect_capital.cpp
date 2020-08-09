/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.
*?
class Solution {
public:
    bool all(string& word, bool caps){
        for(int i=1; i<word.size(); ++i){
            if(caps && 'a'<=word[i] && word[i]<='z') return false;
            if(!caps && 'A'<=word[i] && word[i]<='Z') return false;
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        if('A'<=word[0] && word[0]<='Z') return all(word, true)||all(word, false);
        if('a'<=word[0] && word[0]<='z') return all(word, false);
        return false;
    }
};
