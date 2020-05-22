class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int count=0;
        vector<vector<int>> squares(matrix.size(), vector<int>(matrix[0].size()));
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                if(matrix[i][j]==1){
                    if(i>0 && j>0){
                        squares[i][j] = min(squares[i-1][j], min(squares[i][j-1], squares[i-1][j-1])) + 1;
                    }
                    else{
                        squares[i][j] = 1;
                    }
                    count+=squares[i][j];
                }
            }
        }
        return count;
    }
};
