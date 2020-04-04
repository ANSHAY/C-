class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.size()<=0 || rooms.size()<=0){
            return true;
        }
        queue<int> que;
        vector<bool> visited(rooms.size());
        que.push(0);
        visited[0] = true;
        while(!que.empty()){
            int i=que.front();
            que.pop();
            for(int r: rooms[i]){
                if(!visited[r]){
                    que.push(r);
                    visited[r] = true;
                }
            }
        }
        for (bool v : visited){
            if(!v){
                return false;
            }
        }
        return true;
    }
};
