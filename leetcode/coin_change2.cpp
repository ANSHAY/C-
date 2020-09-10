/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
*/
class Solution {
public:
    unordered_map<int, int> dp;
    int l;
    int cc(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(amount<0) return -1;
        if(dp[amount]!=0) return dp[amount];
        int res=INT_MAX;
        for(int c:coins){
            int n = cc(coins, amount-c);
            if(n>=0) res = min(res, n+1);
        }
        dp[amount] = res==INT_MAX?-1:res;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        l = coins.size();
        if(amount<1 || l<=0) return 0;
        //sort(coins.rbegin(), coins.rend());
        return cc(coins, amount);
    }
};
/* testcases
[419, 408, 83, 156]
6439
*/
