/*
In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

    a 1-day pass is sold for costs[0] dollars;
    a 7-day pass is sold for costs[1] dollars;
    a 30-day pass is sold for costs[2] dollars.

The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days
*/
class Solution {
public:
    int next_cost(vector<int>& min_costs, vector<int>& days, int i, int day){
        for(;i<min_costs.size(); ++i){
            if(days[i]>=day) return min_costs[i];
        }
        return 0;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> min_costs(n);
        for(int i=n-1;i>=0;i--){
            int c=0;
            c = costs[0]+next_cost(min_costs, days, i+1, days[i]+1);
            c = min(c, costs[1]+next_cost(min_costs, days, i+1, days[i]+7));
            c = min(c, costs[2]+next_cost(min_costs, days, i+1, days[i]+30));
            min_costs[i] = c;
        }
        return min_costs[0];
    }
};
