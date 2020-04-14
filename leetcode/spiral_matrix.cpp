class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty()) return res;
        int r_min, r_max, c_min, c_max;
        r_min=0; c_min=0;
        r_max=matrix.size();
        c_max=matrix[0].size();
        int r=0, c=0, rd=0, cd=1;
        while(r_max>r_min && c_max>c_min){
            while(r>=r_min && r<r_max && c>=c_min && c<c_max){
                res.push_back(matrix[r][c]);
                r+=rd;
                c+=cd;
            }
            if(c==c_max){
                r++; c--;
                r_min++;
                cd=0;
                rd=1;
            }
            if(r==r_max){
                r--; c--;
                c_max--;
                cd=-1;
                rd=0;
            }
            if(c<c_min){
                r--; c++;
                r_max--;
                cd=0;
                rd=-1;
            }
            if(r<r_min){
                r++; c++;
                c_min++;
                rd=0;
                cd=1;
            }
        }
        return res;
    }
};
