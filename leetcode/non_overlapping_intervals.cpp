/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(), intervals.end());
        int p=intervals[0][0]-1, v=0;
        for(auto& i:intervals){
            if(i[0]<p){
                v++;
                p = min(i[1], p);
            }
            else p = i[1];
        }
        return v;
    }
};
