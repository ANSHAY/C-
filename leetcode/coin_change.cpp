class Solution {
public:
    int bt(map<pair<int, int>, int>& dp, int amount, vector<int>& coins, int i){
        if(amount==0) return 1;
        if(amount<0 || i<0) return 0;
        if(dp.count(make_pair(amount, i))>0){
            return dp[make_pair(amount, i)];
        }
        return dp[make_pair(amount, i)] = bt(dp, amount, coins, i-1) + bt(dp, amount-coins[i], coins, i);
    }
    int change(int amount, vector<int>& coins) {
        map<pair<int, int>, int> dp;
        return bt(dp, amount, coins, coins.size()-1);
    }
};
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(int c:coins){
            for(int i=c; i<=amount; ++i){
                dp[i] += dp[i-c];
            }
        }
        return dp[amount];
    }
};
