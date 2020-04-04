#include<iostream>
#include<vector>
#include<string>
#include<algortihm>
using namespace std;

class Problems {
public:
    int num_row;
    int num_col;
    bool is_land(vector<vector<char>>& grid, int row, int col);
    void BFS(vector<vector<char>>& grid, queue<pair<int, int>>& que);
    void DFS(vector<vector<char>>& grid, int row, int col);
    int numIslands(vector<vector<char>>& grid);
};
