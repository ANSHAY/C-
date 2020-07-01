class Solution {
public:
    int comb(int m, int n){
        vector<int> com(n+1);
        n = min(m-n, n);
        com[0]=1;
        for(int i=1; i<=m; i++){
            for(int j=min(i, n); j>0; j--){
                com[j] += com[j-1];
            }
        }
        return com[n];
    }
    int uniquePaths(int m, int n) {
        return comb(m+n-2, m-1);
    }
};
/*testcases
51
9
5
4
7
8
5
1
2
3
6
5
4
7
8
9
6
5
4
1
2
3
6
6
5
7
8
9
9
8
7
4
5
1
2
3
6
5
4
7
8
9
6
5
2
3
*/
