/*
Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
*/
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph, int i=0) {
        int n=graph.size();
        vector<vector<int>> subg, res;
        if(i==n) return subg;
        if(graph[i].size()==0){
            if(i==0) return subg;
            subg.push_back(vector<int>{i});
            return subg;
        }
        for(auto p:graph[i]){
            subg = allPathsSourceTarget(graph, p);
            for(auto&v : subg){
                v.insert(v.begin(), i);
                res.push_back(v);
            }
        }
        return res;
    }
};
