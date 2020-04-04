class Solution {
public:
    int startColor;
    int newC;
    vector<vector<bool>> visited;
    void fill(vector<vector<int>>& img, int r, int c){
        if(r<0 || c<0 || r>=img.size() || c>=img[0].size()){
            return;
        }
        if(visited[r][c]) return;
        visited[r][c] = true;
        if(img[r][c] != startColor){
            return;
        }
        img[r][c] = newC;
        fill(img, r+1, c);
        fill(img, r-1, c);
        fill(img, r, c+1);
        fill(img, r, c-1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size()<=0 || image[0].size()<=0){
            return image;
        }
        visited.resize(image.size());
        int i=0; int s=image[0].size();
        for(vector<int> v:image){
            visited[i++].resize(s);
        }
        startColor = image[sr][sc];
        newC = newColor;
        fill(image, sr, sc);
        return image;
    }
};
