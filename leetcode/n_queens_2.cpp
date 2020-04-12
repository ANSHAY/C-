class Solution {
public:
    int size;
    vector<vector<bool>> board;

    bool isValid(int row, int col){
        for(int i=0; i<row; ++i){
            if(board[i][col]) return false;
        }
        for(int i=row-1, j=col-1; i>=0 && j>=0; --i, --j){
            if(board[i][j]) return false;
        }
        for(int i=row-1, j=col+1; i>=0 && j<size; --i, ++j){
            if(board[i][j]) return false;
        }
        return true;
    }

    int backtrack(int row=0, int count=0){
        for(int col=0; col<size; ++col){
            if(isValid(row,col)){
                board[row][col] = true;
                if(row+1 == size){
                    count++;
                }
                else{
                    count = backtrack(row+1, count);
                }
                board[row][col] = false;
            }
        }
        return count;
    }

    int totalNQueens(int n) {
        if(n==0) return 0;
        size = n;
        board.resize(n, vector<bool>(n));
        return backtrack();
    }
};
