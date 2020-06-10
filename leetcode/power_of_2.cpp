class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n&(n-1));
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        while(n>1){
            if(n%2) return false;
            n = n>>1;
        }
        return true;
    }
};
