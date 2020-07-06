/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31. 
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        x = x^y;
        while(x>0){
            if(x&1 == 1) count++;
            x = x>>1;
        }
        return count;
    }
};
