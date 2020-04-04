class Solution {
public:
    map<int, bool> visited;
    bool happy(int n) {
        if(n==1) return true;
        if(visited[n]){
            return false;
        }
        visited[n] = true;
        int s=0;
        while(n>0){
            s+=pow(n%10, 2);
            n/=10;
        }
        return isHappy(s);
    }
    bool isHappy(int n){
        if(n==0) return false;
        //visited.resize();
        return happy(n);
    }
};
