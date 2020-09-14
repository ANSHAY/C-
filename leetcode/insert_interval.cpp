/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        if(n==0){
            res.push_back(newInterval);
            return res;
        }
        if(intervals[n-1][1]<newInterval[0]){
            res=intervals;
            res.push_back(newInterval);
            return res;
        }
        vector<int> t(2);
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        if(intervals[i][0]>newInterval[1]) res.push_back(newInterval);
        else{
            t[0] = min(intervals[i][0], newInterval[0]);
            while(i<n && intervals[i][0]<=newInterval[1]) i++;
            t[1] = max(newInterval[1], intervals[i-1][1]);
            res.push_back(t);
        }
        while(i<n) res.push_back(intervals[i++]);
        return res;
    }
};
