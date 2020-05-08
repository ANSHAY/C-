class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st{nums.begin(), nums.end()};
        int m1=INT_MIN;
        int m2=m1;
        int m3=m1;
        for(int n:nums){
            if(n>m1){
                m3=m2;
                m2=m1;
                m1=n;
            }
            else if(n>m2 && n!=m1){
                m3=m2;
                m2=n;
            }
            else if(n>=m3 && n!=m2 && n!=m1){
                m3=n;
            }
        }
        if(st.size()<3) return m1;
        return m3;
    }
};
