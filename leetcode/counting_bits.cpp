class Solution {
public:
    vector<int> countBits(int num) {
        int pow2=1, p=2;
        vector<int> res;
        res.push_back(0);
        for(int i=1; i<=num; ++i){
            res.push_back(res[i%pow2]+1);
            if(i==p){
                pow2 = (pow2<<1);
                p = (p<<1);
            }
        }
        return res;
    }
};
