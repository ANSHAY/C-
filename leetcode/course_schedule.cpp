class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& visited, int i){
        for(int ch:adj[i]){
            if(visited[ch] == 1) return false;
            if(visited[ch] == 0){
                visited[ch] = 1;
                if(!dfs(adj, visited, ch)) return false;
            }
        }
        visited[i] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        for(vector<int> p:prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        for(int i=0; i<numCourses; ++i){
            if(visited[i] == 0){
                visited[i] = 1;
                if(!dfs(adj, visited, i)) return false;
            }
        }
        return true;
    }
};
