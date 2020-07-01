class Trie {
public:
    map<char, Trie*> children;
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
        if(i>=word.size()) return false;
        if(this->children[word[i]]){
            if(i==word.size()-1){
                return this->children[word[i]]->isEnd;
            }
            return this->children[word[i]]->search(word, i+1);
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix, int i=0) {
        if(i>=prefix.size()) return true;
        if(this->children[prefix[i]]){
            return this->children[prefix[i]]->startsWith(prefix, i+1);
        }
        return false;
    }
};

class Solution {
public:
    Trie* trie = new Trie();
    vector<string> result;
    unordered_map<string, bool> found_words;
    void check_word(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int j){
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0) return;
        if(visited[i][j]) return;
        visited[i][j] = true;
        string w=word+board[i][j];
        if(!found_words[w] && trie->search(w)){
            result.push_back(w);
            found_words[w] = true;
        }
        if(trie->startsWith(w)){
            check_word(board, visited, w, i+1, j);
            check_word(board, visited, w, i-1, j);
            check_word(board, visited, w, i, j+1);
            check_word(board, visited, w, i, j-1);
        }
        visited[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string w:words){
            trie->insert(w);
        }
        int r=board.size();
        int c=board[0].size();
        string word="";
        vector<vector<bool>> visited(r, vector<bool>(c));
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                word = "";
                check_word(board, visited, word, i, j);
            }
        }
        return result;
    }
};
