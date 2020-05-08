class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        if(A.empty()) return res;
        int r=0;
        int l;
        while(r<A.size() && A[r]<0) r++;
        l=r-1;
        while(r<A.size() && l>=0){
            if(A[r]<-A[l]){
                res.push_back(A[r]*A[r]);
                r++;
            }
            else{
                res.push_back(A[l]*A[l]);
                l--;
            }
        }
        while(l>=0){
            res.push_back(A[l]*A[l]);
            l--;
        }
        while(r<A.size()){
            res.push_back(A[r]*A[r]);
            r++;
        }
        return res;
    }
};
