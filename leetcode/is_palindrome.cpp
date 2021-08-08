/**
 * Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

 
 **/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int> vec;
        while(x>0){
            vec.push_back(x%10);
            x /= 10;
        }
        int l = vec.size();
        for(int i=0; i < l; i++){
            if(vec[i] != vec[l-i-1]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int num = x;
        int new=0;
\       while(num>0){
            new = new*10 + num % 10;
            num /= 10;
        }
        if(new == x) return true;
        return false;
    }
};