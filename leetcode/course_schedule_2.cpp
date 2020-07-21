/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array
*/
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& res, int i){
        for (auto& ch:graph[i]){
            if(visited[ch]==1) return false;
            if(visited[ch]==0){
                visited[ch] = 1;
                if(!dfs(graph, visited, res, ch)) return false;
            }
        }
        visited[i] = 2;
        res.push_back(i);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);
        for(auto p:prerequisites){
            graph[p[0]].push_back(p[1]);
        }
        vector<int> res;
        int res_ind=0;
        for(int i=0; i<numCourses; ++i){
            if(visited[i]==1) return vector<int>();
            if(visited[i]==0){
                visited[i] = 1;
                if(!dfs(graph, visited, res, i)) return vector<int>();
            }
        }
        return res;
    }
};
