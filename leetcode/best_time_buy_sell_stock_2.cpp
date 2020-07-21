/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int res = 0;
        int sp=INT_MIN, bp=INT_MAX, si, bi, i=prices.size()-1;
        while(i>0){
            while(i>0 && prices[i-1]>=prices[i]) i--;
            if(i>0){
                sp = max(sp, prices[i]);
            }
            else break;
            while(i>0 && prices[i-1]<=prices[i]) i--;
            if(res<=sp-prices[i]){
                bp = prices[i];
                res=sp-prices[i];
            }
        }
        return res;
    }
};
