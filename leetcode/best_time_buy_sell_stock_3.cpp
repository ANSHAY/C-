/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len<=1) return 0;
        if(len==2) return max(0, (prices[1]-prices[0]));

        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] -  prices[1]);

        for(int i=2; i<len; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        }
        return dp[len-1][0];
    }
};
