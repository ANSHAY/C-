class Trie {
public:
    vector<Trie*> children;
    char val;
    bool isEnd;
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word, int i=0) {
        for(Trie* node:this->children){
            if(node->val == word[i]){
                if(i==word.size()-1){
                    node->isEnd = true;
                }
                else{
                    node->insert(word, i+1);
                }
                return;
            }
        }
        Trie* n = new Trie();
        n->val = word[i];
        if(i==word.size()-1){
            n->isEnd = true;
        }
        else{
            n->insert(word, i+1);
        }
        this->children.push_back(n);
    }

    /** Returns if the word is in the trie. */
    bool search(string word, int i=0) {
        for(Trie* node:this->children){
            if(node->val == word[i]){
                if(i==word.size()-1){
                    return node->isEnd;
                }
                return node->search(word, i+1);
            }
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix, int i=0) {
        if(i>=prefix.size()) return true;
        for(Trie* node:this->children){
            if(node->val == prefix[i]){
                return node->startsWith(prefix, i+1);
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
