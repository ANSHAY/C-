/*
Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

Note:

    An integer point is a point that has integer coordinates.
    A point on the perimeter of a rectangle is included in the space covered by the rectangles.
    ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
    length and width of each rectangle does not exceed 2000.
    1 <= rects.length <= 100
    pick return a point as an array of integer coordinates [p_x, p_y]
    pick is called at most 10000 times.

*/
class Solution {
public:
    vector<vector<int>> rcts;
    vector<int> weights;

    int area(vector<int>& r){
        return (r[3]-r[1]+1)*(r[2]-r[0]+1);
    }

    Solution(vector<vector<int>>& rects) {
        if(rects.size()==0) return;
        rcts = rects;
        int tot=0;
        for(auto &r:rects){
            tot+=area(r);
            weights.push_back(tot);
        }
    }

    vector<int> pick() {
        double rnd = rand()%weights.back();
        int i = upper_bound(weights.begin(), weights.end(), rnd)-weights.begin();
        vector<int> res(2);
        res[0] = rand()%(rcts[i][2]-rcts[i][0]+1) + rcts[i][0];
        res[1] = rand()%(rcts[i][3]-rcts[i][1]+1) + rcts[i][1];
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
