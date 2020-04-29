class Solution {
public:
    int bit_and(int m, int n){
        if(m==0) return 0;
        int i = 1;
        while(i>=0 && i<=n){
            if(i>m) return 0;
            i = i<<1;
        }
        if(i<0){
            i = (INT_MAX>>1) + 1;
        }
        else{
            i = i>>1;
        }
        return i + bit_and(m-i, n-i);
    }

    int rangeBitwiseAnd(int m, int n) {
        return bit_and(m, n);
    }
};
