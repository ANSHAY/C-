/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/
class Solution {
public:
    bool match_word(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int j, int k){
        if(k>=word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        if(visited[i][j]) return false;
        if(board[i][j]==word[k]){
            visited[i][j] = true;
            visited[i][j] = match_word(board, visited, word, i+1, j, k+1) ||
                            match_word(board, visited, word, i-1, j, k+1) ||
                            match_word(board, visited, word, i, j+1, k+1) ||
                            match_word(board, visited, word, i, j-1, k+1);
            return visited[i][j];
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(match_word(board, visited, word, i, j, 0)) return true;
                visited[i][j] = false;
            }
        }
        return false;
    }
};
