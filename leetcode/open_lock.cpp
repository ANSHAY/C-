#include<iostream>
#include<vector>
#include<string>
#include<algortihm>
using namespace std;

/* You have a lock in front of you with 4 circular wheels.
   Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.
   The wheels can rotate freely and wrap around:
   for example we can turn '9' to be '0', or '0' to be '9'.
   Each move consists of turning one wheel one slot.
*/

class OpenLock {
public:
    int turns=0;
    int num_nodes;
    bool visited[10000] = {false};

    void make_deadends_visited(vector<string>& deadends){
        for(string d:deadends){
            visited[stoi(d)] = true;
        }
    }

    void add_children(queue<int>& que, int i){
        // define 8 children of current string
        // add them to que
        int k = 1;
        int child=0;
        for(int j=0;j<4;j++){
            if((i%(10*k))/k == 9){
                child = i - 9*k;
            }
            else{
                child = i+k;
            }
            if(!visited[child]){
                que.push(child);
                visited[child] = true;
            }
            if(((i%(10*k))/k) == 0){
                child = i + 9*k;
            }
            else{
                child = i-k;
            }
            if(!visited[child]){
                que.push(child);
                visited[child] = true;
            }
            k*=10;
        }
    }

    bool shortest_path(int target){
        queue<int> que;
        que.push(0);
        if(visited[0]){
            return false;
        }
        visited[0] = true;
        while(!que.empty()){
            num_nodes = que.size();
            while(num_nodes>0){
                int s = que.front();
                que.pop();
                if(s == target){
                    return true;
                }
                else{
                    // add children nodes to que if child not in deadends
                    add_children(que, s);
                }
                num_nodes--;
            }
            turns++;
        }
        return false;
    }

    int openLock(vector<string>& deadends, string target) {
        if(target==""){
            return -1;
        }
        int t = stoi(target);
        make_deadends_visited(deadends);
        if(shortest_path(t)){
            return turns;
        }
        return -1;
    }
};
