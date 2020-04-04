class Solution {
public:
    map<int, int> dict;
    int fib(int N) {
        if(N<2){
            return N;
        }
        if(!dict[N]){
            dict[N] = fib(N-1) + fib(N-2);
        }
        return dict[N];
    }
};
