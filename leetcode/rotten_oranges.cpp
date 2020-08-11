/*
In a given grid, each cell can have one of three values:

    the value 0 representing an empty cell;
    the value 1 representing a fresh orange;
    the value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.


*/
class Solution {
public:
    int R,C;
    void dfs(vector<vector<int>>& grid, int r, int c, int t){
        if(grid[r][c] == 0) return;
        if(grid[r][c] == 1) grid[r][c] = t;
        else if(grid[r][c] <= t){
            if(t!=2) return;
        }
        else grid[r][c] = t;
        if(r+1<R) dfs(grid, r+1, c, t+1);
        if(r-1>=0) dfs(grid, r-1, c, t+1);
        if(c+1<C) dfs(grid, r, c+1, t+1);
        if(c-1>=0) dfs(grid, r, c-1, t+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        int res=0;
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(grid[i][j]==2) dfs(grid, i, j, 2);
            }
        }
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(grid[i][j]==1) return -1;
                res = max(res, grid[i][j]);
            }
        }
        return res>0?res-2:0;
    }
};
