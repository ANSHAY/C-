class Solution {
public:
    void rotate(vector<vector<int>>& matrix, int l=0) {
        if(l>=matrix.size()/2) return;
        int s = matrix.size()-l;
        vector<int> temp(matrix[l].begin()+l, matrix[l].end()-l);
        for(int i=l; i<s; ++i){
            matrix[l][s-1-i+l] = matrix[i][l];
        }
        for(int i=l; i<s; ++i){
            matrix[i][l] = matrix[s-1][i];
        }
        for(int i=l; i<s; ++i){
            matrix[s-1][i] = matrix[s+l-i-1][s-1];
        }
        for(int i=l; i<s; ++i){
            matrix[i][s-1] = temp[i-l];
        }
        rotate(matrix, l+1);
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>j) continue;
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
