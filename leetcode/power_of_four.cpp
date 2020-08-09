class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && (num&(num-1))==0 && (num& 0x555555555);
    }
};
