/*
Implement the StreamChecker class as follows:

    StreamChecker(words): Constructor, init the data structure with the given words.
    query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.

*/
class Trie {
    public:
    vector<Trie*> children{26, NULL};
    bool end=false;

    void insert(string word){
        Trie* node = this;
        int s = word.size()-1;
        for(int i=s; i>=0; i--){
            if(!node->children[word[i]-'a']){
                node->children[word[i]-'a'] = new Trie();
            }
            node = node->children[word[i]-'a'];
        }
        node->end=true;
    }

    bool check(string& word, int len){
        int n = word.size()-1;
        Trie* node = this;
        for(int i=n; i>n-len; --i){
            node = node->children[word[i]-'a'];
            if(node){
                if(node->end) return true;
            }
            else return false;
        }
        return false;
    }
};

class StreamChecker {
public:
    Trie tree;
    string word;
    int minlen = INT_MAX, maxlen=0;

    StreamChecker(vector<string>& words) {
        for(auto& w:words){
            tree.insert(w);
            minlen = min(minlen, (int)w.size());
            maxlen = max(maxlen, (int)w.size());
        }
        word = "";
    }

    bool query(char letter) {
        word+=letter;
        if(word.size()<minlen) return false;
        int len = min(maxlen, (int)word.size());
        return tree.check(word, len);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
