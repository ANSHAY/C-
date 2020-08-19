/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
*/
class Solution {
public:
    int mySqrt(int x) {
        int l=0, r=46340, m=0;
        while(l<r){
            m=l+(r-l)/2;
            int n=m*m;
            if(x==n) return m;
            if(x>n) l=m+1;
            else r=m-1;
        }
        return x>=l*l?l:l-1;
    }
};
