#include"bfs_dfs.h"

// define a function that checks if a cell is land or not
bool Problems::is_land(vector<vector<char>>& grid, int row, int col){
    if(row>=num_row || col>=num_col || row<0 || col<0){
        return false;
    }
    if(grid[row][col]=='1'){
        return true;
    }
    return false;
}

void Problems::BFS(vector<vector<char>>& grid, queue<pair<int, int>>& que){
    // define two arrays that define neighbouring cells
    static int rows[] = {-1, 1, 0, 0};
    static int cols[] = {0, 0, -1, 1};
    int i = que.front().first;
    int j = que.front().second;
    que.pop();

    grid[i][j] = '2';

    // check if neighbor is land and not visited
    // if true, add it to queue
    for(int k=0; k<4; ++k){
        int r = i + rows[k];
        int c = j + cols[k];
        if(is_land(grid, r, c)){
            que.push(make_pair(r,c));
        }
    }
}

void Problems::DFS(vector<vector<char>>& grid, int row, int col){
    if(!is_land(grid, row, col)){
        return;
    }
    grid[row][col] = '2';
    DFS(grid, row-1, col);
    DFS(grid, row+1, col);
    DFS(grid, row, col-1);
    DFS(grid, row, col+1);
}

// Given a 2d grid map of '1's (land) and '0's (water),
// count the number of islands. An island is surrounded
// by water and is formed by connecting adjacent lands
// horizontally or vertically. You may assume all four
// edges of the grid are all surrounded by water.
int Problems::numIslands(vector<vector<char>>& grid) {
    int count = 0;
    num_row = grid.size();
    if(!num_row) return 0;
    num_col = grid[0].size();
    if(!num_col) return 0;

    // make a queue that holds current connected cells to be visited (for BFS)
    // queue<pair<int, int>> que;

    // for every unvisited cell, check if it's neighbours are land and visited.
    // if land and not visited then add them to queue.
    // repeat this while queue is not empty.
    // above step will be followed once for every island.
    // so num of islands is the number of times this step is run.
    for(int i=0; i<num_row; ++i){
        for(int j=0; j<num_col; ++j){
            if(grid[i][j]=='1'){
                DFS(grid, i, j);          // DFS approach
                /*
                // code for BFS
                que.push(make_pair(i,j));
                while(!que.empty()){
                    BFS(grid, que);
                }*/
                count++;
            }
        }
    }
    return count;
}
