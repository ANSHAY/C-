class Solution {
public:
    int kthGrammar(int N, int K) {
        if(K==1) return 0;
        if(K==2) return 1;
        int p = pow(2, N-2);
        int newK = K>p? K-p:K;
        return newK==K? kthGrammar(N-1, newK) : 1-kthGrammar(N-1, newK);
    }
};
