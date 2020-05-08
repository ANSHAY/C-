class Solution {
public:
    bool isEvenDigit(int n){
        if(n<=10) return false;
        else if(n<100) return true;
        else if(n<1000) return false;
        else if(n<10000) return true;
        else if(n<100000) return false;
        else return true;
    }

    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int n:nums){
            if(isEvenDigit(n)) count++;
        }
        return count;
    }
};
