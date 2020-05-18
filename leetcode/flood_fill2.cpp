class Solution {
public:
    int oc;
    void ff(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int newColor) {
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return;
        if(visited[sr][sc]) return;
        visited[sr][sc] = true;
        if(image[sr][sc] != oc) return;
        image[sr][sc] = newColor;
        ff(image, visited, sr+1, sc, newColor);
        ff(image, visited, sr-1, sc, newColor);
        ff(image, visited, sr, sc+1, newColor);
        ff(image, visited, sr, sc-1, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size()));
        oc = image[sr][sc];
        if(oc==newColor) return image;
        ff(image, visited, sr, sc, newColor);
        return image;
    }
};
