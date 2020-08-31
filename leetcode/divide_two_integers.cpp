/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        if(dividend==divisor) return 1;
        if(divisor==1) return dividend;
        if(divisor<0){
            if(divisor==INT_MIN) return 0;
            int ans = divide(dividend, -divisor);
            if(ans==INT_MIN) return INT_MAX;
            return -ans;
        }
        if(dividend<0){
            int b=0;
            if(dividend==INT_MIN) b=divisor;
            int Q = divide(-(dividend + b), divisor);
            if(b) return -Q-1;
            return -Q;
        }
        int Q = 0;
        while(dividend>=divisor){
            dividend-=divisor;
            Q+=1;
        }
        return Q;
    }
};
