/*

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0; --i){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            else digits[i] = 0;
        }
        digits[0]=1;
        digits.push_back(0);
        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        while( i>=0 && digits[i]==9){
            digits[i] = 0;
            i--;
        }
        if(i<0){
            digits.push_back(0);
            digits[0] = 1;
        }
        else{
            digits[i]++;
        }
        return digits;
    }
};
/* testcases
[1]
[9]
[0,0]
[9,9]
[1,4]
[9,8,7,6,5,4,5,6,7,8,9,9,9]
[9,9,9,9,9,9,9,9,9,9,9]
*/
