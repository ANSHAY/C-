class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()<=0 || matrix[0].size()<=0){
            return matrix;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> out(rows, vector<int>(cols, 10));

        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(matrix[i][j] == 0){
                    out[i][j] = 0;
                }
                else{
                    if(i>0){
                        out[i][j] = min(out[i][j], out[i-1][j]+1);
                    }
                    if(j>0){
                        out[i][j] = min(out[i][j], out[i][j-1]+1);
                    }
                }
            }
        }
        for(int i=rows-1; i>=0; --i){
            for(int j=cols-1; j>=0; --j){
                if(out[i][j]!=0){
                    if(i<rows-1){
                        out[i][j] = min(out[i][j], out[i+1][j]+1);
                    }
                    if(j<cols-1){
                        out[i][j] = min(out[i][j], out[i][j+1]+1);
                    }
                }
            }
        }
        return out;
    }
};
