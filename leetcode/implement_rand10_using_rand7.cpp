/*
Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().
*/
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int i=1, b=1;
        for(int j=0; j<9; ++j){
            i += (rand7()-1)*b;
            b *= 7;
        }
        return i*10/b + 1;
    }
};
