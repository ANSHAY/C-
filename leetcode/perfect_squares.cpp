#include<iostream>
#include<vector>
#include<string>
#include<algortihm>
using namespace std;

/* Given a positive integer n, find the least number of perfect square
   numbers (for example, 1, 4, 9, 16, ...) which sum to n.
*/
class PerfectSquares {
public:
    int nums=0;
    vector<bool> visited;

    void add_children(queue<int>& q, int n){
        int i=1;
        int s = i*i;
        while(s<=n){
            int a = n-s;
            if(!visited[a]){
                q.push(a);
                visited[a] = true;
            }
            i++;
            s = i*i;
        }
    }
    bool bfs(int target){
        queue<int> q;
        q.push(target);
        visited[target]=true;
        int numnodes;
        while(!q.empty()){
            numnodes = q.size();
            while(numnodes>0){
                int n = q.front();
                q.pop();
                if(n==0){
                    return true;
                }
                add_children(q, n);// add children of n to queue
                numnodes--;
            }
            nums++;
        }
        return false;
    }

    int numSquares(int n) {
        visited.assign(n+1,false);
        bfs(n);
        return nums;
    }
};


class Solution {
public:
    bool isSquare(int n) {
        int sqroot = sqrt(n);
        return (n==(sqroot*sqroot));
    }
    int numSquares(int n) {
        while(n%4==0) n = n/4;
        if(n%8 == 7) return 4;
        if(isSquare(n)) return 1;
        for(int i=1;i*i<=n;i++) if(isSquare(n-i*i)) return 2;
        return 3;
    }
};
