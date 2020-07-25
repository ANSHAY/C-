/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        if(r==0) return;
        int c=matrix[0].size();
        int flag=1;
        for(int j=0; j<c; ++j){
            if(matrix[0][j]==0) flag=0;
        }
        for(int i=1; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1; i<r; ++i){
            if(matrix[i][0]==0){
                matrix[i] = vector<int>(c, 0);
            }
        }
        for(int j=0; j<c; j++){
            if(matrix[0][j]==0){
                for(int i=1; i<r; ++i){
                    matrix[i][j]=0;
                }
            }
        }
        if(flag==0) matrix[0] = vector<int>(c, 0);
    }
};
