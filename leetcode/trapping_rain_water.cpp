/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r = height.size()-1, ans=0;
        if(r<2) return 0;
        int tl=height[0], tr=height[r];
        while(l<r){
            if(height[l]<=height[r]){
                l++;
                tl = max(tl, height[l]);
                ans+=max(0, min(tl, tr)-height[l]);
            }
            else{
                r--;
                tr = max(tr, height[r]);
                ans+=max(0, min(tl, tr)-height[r]);
            }
        }
        return ans;
    }
};
