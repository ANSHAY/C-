class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> cop{heights};
        int count=0;
        sort(cop.begin(), cop.end());
        for(int i=0; i<heights.size(); ++i){
            if(heights[i]!=cop[i]) count++;
        }
        return count;
    }
};
