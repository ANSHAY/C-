/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
*/

class Trie {
public:
    unordered_map<char, Trie*> children;
    bool isEnd;
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word, int i=0) {
        if(this->children[word[i]]){
            if(i==word.size()-1){
                this->children[word[i]]->isEnd = true;
            }
            else{
                this->children[word[i]]->insert(word, i+1);
            }
            return;
        }
        Trie* n = new Trie();
        if(i==word.size()-1){
            n->isEnd = true;
        }
        else{
            n->insert(word, i+1);
        }
        this->children[word[i]] = n;
    }

    /** Returns if the word is in the trie. */
    bool search(string word, int i=0) {
        if(this->children.count(word[i])>0){
            if(i==word.size()-1){
                return this->children[word[i]]->isEnd;
            }
            return this->children[word[i]]->search(word, i+1);
        }
        if(word[i]=='.'){
            if(i==word.size()-1){
                for(auto& p:this->children){
                    if(p.second->isEnd) return true;
                }
            }
            else{
                for(auto& p:this->children){
                    if(p.second->search(word, i+1)) return true;
                }
            }
        }
        return false;
    }
};

class WordDictionary {
public:
    Trie* data;
    /** Initialize your data structure here. */
    WordDictionary() {
        data = new Trie();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        data->insert(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return data->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
