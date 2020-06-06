class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res=0;
        vector<int> extra(costs.size());
        for(int i=0; i<costs.size(); ++i){
            res += costs[i][0];
            extra[i] = costs[i][1] - costs[i][0];
        }
        sort(extra.begin(), extra.end());
        for(int i=0; i<extra.size()/2; ++i){
            res+=extra[i];
        }
        return res;
    }
};
