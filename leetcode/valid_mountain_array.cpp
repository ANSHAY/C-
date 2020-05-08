class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3) return false;
        int i;
        for(i=1; i<A.size(); ++i){
            if(A[i]==A[i-1]) return false;
            if(A[i] < A[i-1]) break;
        }
        if(i==1) return false;
        if(i==A.size()) return false;
        while(i<A.size()){
            if(A[i]>=A[i-1]) return false;
            ++i;
        }
        return true;
    }
};
/*testcases
[2,1]
[1,2,3,4,5,6]
[6,5,4,3,2,1]
[1,1,1,1,1,1]
[5,4,7,8,9,6,5,2,3,6,5,4,1,2,0]
[1,2,3,4,5,3,1]
[1,2,3,4,5,4]
[1,4,3,2,1]
[1,2,1]
[1,1,1]
[2,1,2]
*/
