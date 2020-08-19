/*
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.
*/
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        int v=0, d=0, n=1, nodes;
        deque<int> que;
        for(int i=1; i<10; ++i){
            que.push_back(i);
        }
        while(n<N){
            nodes = que.size();
            while(nodes){
                v = que.front();
                d = v%10;
                que.pop_front();
                if(d-K>=0) que.push_back(10*v+d-K);
                if(d+K<10 && K>0) que.push_back(10*v+d+K);
                nodes--;
            }
            n++;
        }
        vector<int> res(que.begin(), que.end());
        if(N==1) res.push_back(0);
        return res;
    }
};
