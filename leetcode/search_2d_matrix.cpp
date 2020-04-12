class Solution {
public:
    int rows, cols;
/*
    bool search(vector<vector<int>>& matrix, int target, int row_min, int row_max, int col_min, int col_max){
        if(row_min>row_max || col_min>col_max) return false;
        if(col_min==col_max && row_min==row_max){
            return matrix[row_min][col_min]==target;
        }
        int col_mid = (col_min+col_max)/2;
        int r_pivot;
        for(int r_pivot=row_min; r_pivot<=row_max; ++r_pivot){
            if(matrix[r_pivot][col_mid]>target){
                break;
            }
        }
        if(search(matrix, target, r_pivot, row_max, col_min, col_mid)) return true;
        if(search(matrix, target, row_min, r_pivot-1, col_mid+1, col_max)) return true;
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()<=0 || matrix[0].size()<=0) return false;
        return search(matrix, target, 0, matrix.size()-1, 0, matrix[0].size()-1);
    }
*/
/*
    bool binCol(vector<int>& row, int target, int c_min, int c_max){
        if(c_min>c_max) return false;
        if(c_min == c_max) return target==row[c_min];
        int c_mid = (c_min+c_max)/2;
        if(target==row[c_mid]) return true;
        if(target>row[c_mid]){
            return binCol(row, target, c_mid+1, c_max);
        }
        return binCol(row, target, c_min, c_mid-1);
    }
    bool binRow(vector<vector<int>>& matrix, int target, int r_min, int r_max){
        if(r_min>r_max) return false;
        if(r_min == r_max) return binCol(matrix[r_min], target, 0, cols-1);
        int r_mid = (r_min+r_max)/2;
        if(target==matrix[r_mid][cols-1]) return true;
        if(target>matrix[r_mid][cols-1]){
            return binRow(matrix, target, r_mid+1, r_max);
        }
        return binRow(matrix, target, r_min, r_mid);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.size()<=0 || matrix[0].size()<=0) return false;
        rows = matrix.size();
        cols = matrix[0].size();
        if(target<matrix[0][0] || target>matrix[rows-1][cols-1]) return false;
        return binRow(matrix, target, 0, rows-1);
    }
*/
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.size()<=0 || matrix[0].size()<=0) return false;
        rows = matrix.size();
        cols = matrix[0].size();
        if(target<matrix[0][0] || target>matrix[rows-1][cols-1]) return false;
        int r=0, c=cols-1;
        while (r<rows && c>=0){
            if(target == matrix[r][c]) return true;
            if(target < matrix[r][c]) c--;
            else r++;
        }
        return false;
    }
};
/* testcases
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
5
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
1
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
15
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
18
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
30
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
434
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
10
[]
7
[[4]]
1
[[4]]
4
[[1,2],[3,4]]
0
[[1,2],[3,4]]
1
[[1,2],[3,4]]
2
[[1,2],[3,4]]
3
[[1,2],[3,4]]
4
[[1,2,3],[4,5,6],[7,8,9]]
0
[[1,2,3],[4,5,6],[7,8,9]]
1
[[1,2,3],[4,5,6],[7,8,9]]
9
[[1,2,3],[4,5,6],[7,8,9]]
2
[[1,2,3],[4,5,6],[7,8,9]]
3
[[1,2,3],[4,5,6],[7,8,9]]
4
[[1,2,3],[4,5,6],[7,8,9]]
5
[[1,2,3],[4,5,6],[7,8,9]]
6
[[1,2,3],[4,5,6],[7,8,9]]
7
[[1,2,3],[4,5,6],[7,8,9]]
8
*/
