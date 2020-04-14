class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty()) return res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int r=0, c=0, dir=1;
        while(r<rows && c<cols){
            while(r>=0 && c>=0 && r<rows && c<cols){
                res.push_back(matrix[r][c]);
                r-=dir;
                c+=dir;
            }
            if(r==rows){
                r--;
                c+=2;
            }
            if(c==cols){
                c--;
                r+=2;
            }
            if(r==-1){
                r=0;
            }
            if(c==-1){
                c=0;
            }
            dir*=-1;
        }
        return res;
    }
};
