class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<1) return -1;
        vector<int> sp(n+1);
        int i2=0, i3=0, i5=0, j=0;
        int k2, k3, k5, t;
        sp[0] = 1;
        while(j<n){
            k2 = sp[i2]*2; k3=sp[i3]*3; k5=sp[i5]*5;
            if(k2<k3){
                if(k2<k5){
                    i2++;
                    t = k2;
                }
                else{
                    i5++;
                    t = k5;
                }
            }
            else{
                if(k3<k5){
                    i3++;
                    t = k3;
                }
                else{
                    i5++;
                    t = k5;
                }
            }
            if(t>sp[j]){
                ++j;
                sp[j] = t;
            }
        }
        return sp[n-1];
    }
};
