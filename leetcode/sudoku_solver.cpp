class Solution {
public:
    int rows, cols;
    bool isValid(vector<vector<char>>& board, int row, int col, char cand){
        for(int i=0; i<rows; ++i){
            if(board[i][col] == cand) return false;
        }
        for(int i=0; i<cols; ++i){
            if(board[row][i] == cand) return false;
        }
        int block_r = row/3;
        int block_c = col/3;
        for(int r = 0; r<3; ++r){
            for(int c=0; c<3; ++c){
                if(board[block_r*3 + r][block_c*3 + c] == cand) return false;
            }
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board, int row=0, int col=0){
        if(row>=rows) return true;
        if(board[row][col] != '.'){
            if(col+1 == cols){
                return backtrack(board, row+1, 0);
            }
            return backtrack(board, row, col+1);
        }
        for(char cand='1'; cand<='9'; ++cand){
            if(isValid(board, row, col, cand)){
                // place cand
                board[row][col] = cand;
                // walk further
                if(col+1 == cols){
                    if(backtrack(board, row+1, 0)) return true;
                }
                else{
                    if(backtrack(board, row, col+1)) return true;
                }
                // remove candidate
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        rows = board.size();
        cols = board[0].size();
        backtrack(board);
        return;
    }
};
