class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> itoi(n, vector<int>(n, -1));
        vector<vector<int>> ktoi(K+1, vector<int>(n));
        int c;
        for(vector<int> f:flights){
            itoi[f[0]][f[1]] = f[2];
        }
        for(int i=0; i<n; ++i){
            itoi[i][i] = 0;
        }
        for(int s=0; s<n; ++s){
            ktoi[0][s] = itoi[s][dst];
        }
        for(int j=1; j<K; ++j){
            for(int i=0; i<n; ++i){
                c = INT_MAX;
                for(int s=0; s<n; ++s){
                    if(ktoi[j-1][s]!=-1 && itoi[i][s]!=-1){
                        c = min(c, ktoi[j-1][s] + itoi[i][s]);
                    }
                }
                ktoi[j][i] = (c==INT_MAX)?-1:c;
            }
        }
        if(K>0){
            c = INT_MAX;
            for(int s=0; s<n; ++s){
                if(ktoi[K-1][s]!=-1 && itoi[src][s]!=-1){
                    c = min(c, ktoi[K-1][s] + itoi[src][s]);
                }
                ktoi[K][src] = c==INT_MAX?-1:c;
            }
        }
        return ktoi[K][src];
    }
};
