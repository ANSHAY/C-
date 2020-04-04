#include<iostream>
#include<vector>
#include<string>
#include<algortihm>
using namespace std;

class Solution {
public:
    vector<int> days;
    vector<int> stack;
    vector<int> dailyTemperatures(vector<int>& T) {
        days.assign(T.size(), 0);
        int k = T.size()-1;
        while(k>=0){
            int i = T[k];
            if(stack.empty()){
                days[k] = 0;
                stack.push_back(k);
                k--;
            }
            else if(i < T[stack.back()]){
                days[k] += 1;
                stack.push_back(k);
                k--;
            }
            else{
                days[k] += days[stack.back()];
                stack.pop_back();
            }
        }
        return days;
    }
};
