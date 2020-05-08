class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int s=A.size();
        int l=0, r=s-1;
        while(l<r){
            while(l<s && A[l]%2==0) l++;
            while(r>=0 && A[r]%2==1) r--;
            if(l<r){
                int temp = A[l];
                A[l] = A[r];
                A[r] = temp;
                l++; r--;
            }
        }
        return A;
    }
};
/* testcases
[3,1,2,4]
[2,1,4,5,2,0,3,6,5,8,7,4,59,6,8,5,2,3,6,9,8,54,1,2,0,5,8,9,65,4,1,2,3]
[1]
[2]
[2,4]
[1,3]
[1,1,1,1,1,1]
[2,2,2,2,2,2]
[2,4,6,8,0,1,3,5,7,9]
[1,3,5,7,9,2,4,6,8,0]
[1,2]
[2,1]
*/
