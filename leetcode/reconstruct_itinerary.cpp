class Solution {
public:
    unordered_map<string, multiset<string>> mmp;
    vector<string> path;

    void dfs(string &dep){
        if(mmp.count(dep)<=0){
            path.push_back(dep);
            return;
        }
        auto &arr = mmp[dep];
        while(!arr.empty()){
            string s = *(arr.begin());
            arr.erase(arr.begin());
            dfs(s);
        }
        path.push_back(dep);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto t : tickets){
            mmp[t[0]].insert(t[1]);
        }
        string start="JFK";
        dfs(start);
        reverse(path.begin(), path.end());
        return path;
    }
};
/* testcases
[["JFK","b"],["b","c"],["b","e"],["b","d"],["c","b"],["d","b"]]
[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
*/
