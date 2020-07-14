/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.
*/
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s = countAndSay(n-1);
        string res = "";
        int c = 0;
        char t = s[0];
        for(int i=0; i<s.size(); ++i){
            if(s[i]==t){
                c++;
            }
            else{
                res += to_string(c) + t;
                c = 1;
                t = s[i];
            }
        }
        res += to_string(c) + t;
        return res;
    }
};
