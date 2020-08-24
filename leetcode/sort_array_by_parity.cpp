/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l=0, r=A.size()-1, t=0
;
        while(r>l){
            if(A[l]%2){
                t = A[r];
                A[r] = A[l];
                A[l] = t;
                r--;
            }
            else l++;
        }
        return A;
    }
};
