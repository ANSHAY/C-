/*
Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:

    You may assume the interval's end point is always bigger than its start point.
    You may assume none of these intervals have the same start point.

*/
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<vector<int>, int>> d(n);
        vector<int> res(n, -1);
        for(int j=0; j<n; j++){
            d[j] = {intervals[j], j};
        }
        sort(d.begin(), d.end());
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(d[j].first[0]>=d[i].first[1]){
                    res[d[i].second] = d[j].second;
                    break;
                }
            }
        }
        return res;
    }
};
