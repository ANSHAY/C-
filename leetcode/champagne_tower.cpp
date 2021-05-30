// champane tower

class Solution {
public:
    double dp[101][101];
    double drop(double p, int i, int j){
        if(j<0 || j>i) return 0;
        if(i==0) return p>1?(p-1)/2:0;
        if(dp[i][j]>-1) return dp[i][j];
        dp[i][j] = drop(p, i-1, j-1)+drop(p, i-1, j);
        dp[i][j] = dp[i][j]>1?(dp[i][j]-1)/2:0;
        return dp[i][j];
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        if(query_row==0){
            return min(poured, 1);
        }
        for(int i=0;i<101;i++) for(int j=0;j<101;j++) dp[i][j]=-1.0;
        double d = drop(poured, query_row-1, query_glass-1)+drop(poured, query_row-1, query_glass);
        return d>1?1:d;
    }
};