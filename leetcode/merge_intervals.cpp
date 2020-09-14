/*
Given a collection of intervals, merge all overlapping intervals.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> res;
        if(n==0) return res;
        sort(intervals.begin(), intervals.end());
        vector<int> cur=intervals[0], t(2);
        for(int i=1; i<n; i++){
            if(intervals[i][0]>cur[1]){
                res.push_back(cur);
                cur = intervals[i];
            }
            else{
                t[0] = min(intervals[i][0], cur[0]);
                t[1] = cur[1];
                while(i<n && intervals[i][0]<=t[1]){
                    t[1] = max(t[1], intervals[i][1]);
                    i++;
                }
                cur = t;
                if(i==n) break;
                i--;
            }
        }
        res.push_back(cur);
        return res;
    }
};
/*
[[1,3],[2,6],[8,10],[15,18]]
[[1,4],[4,5]]
[[1,3],[2,6],[8,10],[10,13],[15,18]]
[[1,3],[2,6],[6,7],[8,10],[15,18]]
[[1,3],[2,6],[6,6],[8,10],[15,18]]
[[1,3],[2,6],[6,7],[8,10],[11,11],[11,11],[11,11],[15,18]]
*/
