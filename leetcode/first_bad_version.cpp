// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int fbv(int l, int r){
        if(l>=r) return r;
        int mid = l+(r-l)/2; //(l>>1 + r>>1) + (l%2 && r%2)?1:0;
        if(isBadVersion(mid)) return fbv(l, mid);
        else return fbv(mid+1, r);
    }
    int firstBadVersion(int n) {
        return fbv(1, n);
    }
};
