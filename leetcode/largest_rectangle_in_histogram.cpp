class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> stk;
        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), heights.size());
        int res=0;
        for(int i=0; i<heights.size();++i){
            while(!stk.empty() && heights[i]<=heights[stk.back()]){
                stk.pop_back();
            }
            if(!stk.empty()) left[i] = stk.back();
            stk.push_back(i);
        }
        stk = vector<int>();
        for(int i=heights.size()-1; i>=0;--i){
            while(!stk.empty() && heights[i]<=heights[stk.back()]){
                stk.pop_back();
            }
            if(!stk.empty()) right[i] = stk.back();
            stk.push_back(i);
        }
        for(int i=0;i<heights.size();++i){
            res = max(res, heights[i]*(right[i]-left[i]-1));
        }
        return res;
    }
};
/* testcases
[2,1,5,6,2,3]
[]
[1]
[1,2,4,7,5,3,4,6,8,9,6,4,2,4,5]
[1,1,1,1,1]
[1,2,3,4,5,6,7,8,9]
[9,8,7,6,5,4,3,2,1]
[1,2,34,7,76,23,5,67,68,56,7,85,1,6,43,5]
*/
