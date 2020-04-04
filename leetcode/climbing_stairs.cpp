class Solution {
public:
    map<int, int> dict;
    int climbStairs(int n) {
        if(n<3){
            return n;
        }
        if(!dict[n]){
            dict[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        return dict[n];
    }
};
