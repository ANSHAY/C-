class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string word, res;
        vector<string> words;
        while(str>>word){
            words.push_back(word);
        }
        for(int i=words.size()-1; i>=0; --i){
            res+=words[i];
            if(i) res+=" ";
        }
        return res;
    }
};
