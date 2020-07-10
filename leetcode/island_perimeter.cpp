/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
*/
class Solution {
public:
    int count;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            count++;
            return;
        }
        if(grid[i][j]==2) return;
        if(grid[i][j]==0){
            count++;
            return;
        }
        grid[i][j]=2;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size() <= 0 || grid[0].size() <= 0) return 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    break;
                }
            }
        }
        return count;
    }
};
