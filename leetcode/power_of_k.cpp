class Solution {
public:
    bool isPowerOfK(int n, int k) {
        int i=1;
        while(i<=(INT_MAX-i)/2){
            i*=k;
        }
        return n > 0 && i % n == 0;
    }
};
