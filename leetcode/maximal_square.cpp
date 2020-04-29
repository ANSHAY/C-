class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int>> sizes(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res = 0;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                if(matrix[i][j]=='1'){
                    if(i>0 && j>0 && matrix[i-1][j]=='1' && matrix[i-1][j-1]=='1' && matrix[i][j-1]=='1'){
                        sizes[i][j] = min(sizes[i-1][j-1], min(sizes[i-1][j], sizes[i][j-1]))+1;
                    }
                    else{
                        sizes[i][j] = 1;
                    }
                }
                res = max(res, sizes[i][j]);
            }
        }
        return res*res;
    }
};
/*
testcases
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
[["0"]]
[["1"]]
[["1","1","1","1","1"],["1","1","1","1","1"],["1","1","1","1","1"],["1","1","1","1","1"]]
[["0","0","0","0","0"],["0","0","0","0","0"],["0","0","0","0","0"],["0","0","0","0","0"]]

*/
