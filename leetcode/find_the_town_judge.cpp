class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.empty() && N==1) return 1;
        vector<int> itrust(N+1, 0);
        set<int> judges;
        for(int i=0; i<trust.size(); ++i){
            itrust[trust[i][0]] = -1;
            ++itrust[trust[i][1]];
            if(itrust[trust[i][1]] == N-1){
                judges.insert(trust[i][1]);
            }
        }
        for(int j:judges){
            if(itrust[j]==N-1) return j;
        }
        return -1;
    }
};
/*testcases
2
[[1,2]]
2
[[1,2],[2,1]]
1
[]
2
[]
3
[]
3
[[1,2],[1,3]]
3
[[1,2],[2,3],[3,1]]
3
[[1,2],[3,2],[1,3]]
4
[[1,3],[1,4],[2,3],[2,4],[4,3]]
4
[[1,3],[1,4],[2,3],[2,4],[4,3],[3,4]]
*/
