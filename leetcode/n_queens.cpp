class Solution {
public:
    int size;
    map<pair<int, int>, int> board;
    void mark_row_col(int row, int col, int sign=1){
        for(int i=col; i<size; ++i){
            board[make_pair(row, i)] += sign;
        }
        for(int i=row; i<size; ++i){
            board[make_pair(i, col)] += sign;
        }
    }
    void mark(int row, int col, int sign=1){
        if(row<0 || col<0 || row>=size || col>=size) return;
        board[make_pair(row, col)] += sign;
    }
    void mark_diagonals(int row, int col, int sign=1){
        for(int i=1; i<size; ++i){
            mark(row+i, col+i, sign);
            //mark(row-i, col+i, sign);
            //mark(row-i, col-i, sign);
            mark(row+i, col-i, sign);
        }
    }
    void place_queen(int row, int col){
        mark_row_col(row, col);
        mark_diagonals(row, col);
        board[make_pair(row, col)] = 1;
    }
    bool isValid(int row, int col){
        return board[make_pair(row, col)]==0;
    }
    void remove_queen(int row, int col){
        mark_row_col(row, col, -1);
        mark_diagonals(row, col, -1);
        board[make_pair(row, col)] = 0;
    }
    int backtrack(int row=0, int count=0){
        for(int col=0; col<size; ++col){
            if(isValid(row,col)){
                place_queen(row, col);
                if(row+1 == size){
                    count++;
                }
                else{
                    count = backtrack(row+1, count);
                }
                remove_queen(row, col);
            }
        }
        return count;
    }

    int totalNQueens(int n) {
        if(n==0) return 0;
        size = n;
        return backtrack();
    }
};
