/*
Given an array of integers A, We need to sort the array performing a series of pancake flips.

In one pancake flip we do the following steps:

    Choose an integer k where 0 <= k < A.length.
    Reverse the sub-array A[0...k].

For example, if A = [3,2,1,4] and we performed a pancake flip choosing k = 2, we reverse the sub-array [3,2,1], so A = [1,2,3,4] after the pancake flip at k = 2.

Return an array of the k-values of the pancake flips that should be performed in order to sort A. Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.
*/
class Solution {
public:
    vector<int> res;
    void psort(vector<int>& A, int p){
        if(p<=1) return;
        // find ind of biggest
        int m=INT_MIN;
        int j=-1;
        for(int i=0; i<p; i++){
            if(A[i]>m){
                m = A[i];
                j=i;
            }
        }
        // push it to the end
        if(j<p-1){
            int l=j, r=p-1;
            while(l<r){
                int t=A[l];
                A[l]=A[r];
                A[r]=t;
                l++;
                r--;
            }
            res.push_back(p);
            res.push_back(p-j);
            res.push_back(p);
        }
        // call rec on the remaining
        psort(A, p-1);
    }
    vector<int> pancakeSort(vector<int>& A) {
        psort(A, A.size());
        return res;
    }
};
