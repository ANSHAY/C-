class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<bool> visited(N+1);
        vector<int> color(N+1);
        vector<vector<int>> graph(N+1);
        queue<int> q;
        int j, num;
        for(auto d:dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        for(int i=1; i<=N; ++i){
            if(visited[i]) continue;
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                num = q.size();
                while(num>0){
                    num--;
                    j = q.front();
                    q.pop();
                    visited[j] = true;
                    for(int child:graph[j]){
                        if(color[j] == color[child]) return false;
                        if(visited[child]) continue;
                        color[child] = -color[j];
                        q.push(child);
                    }
                }
            }
        }
        return true;
    }
};
