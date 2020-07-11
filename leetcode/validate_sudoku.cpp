/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> ctoi;
        int m=0;
        for(char c='1'; c<='9'; c++){
            ctoi[c] = m;
            m++;
        }
        // check rows
        for(int i=0; i<9; ++i){
            vector<bool> seen(9);
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    if(seen[ctoi[board[i][j]]]) return false;
                    else seen[ctoi[board[i][j]]] = true;
                }
            }
        }
        // check columns
        for(int j=0; j<9; ++j){
            vector<bool> seen(9);
            for(int i=0; i<9; i++){
                if(board[i][j]!='.'){
                    if(seen[ctoi[board[i][j]]]) return false;
                    else seen[ctoi[board[i][j]]] = true;
                }
            }
        }
        // check boxes
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                vector<bool> seen(9);
                for(int k=0; k<3; ++k){
                    int p = i+k;
                    for(int l=0; l<3; ++l){
                        int q=j+l;
                        if(board[p][q]!='.'){
                            if(seen[ctoi[board[p][q]]]) return false;
                            else seen[ctoi[board[p][q]]] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
