/*
Given two arrays, write a function to compute their intersection.
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                res.push_back(nums1[i]);
                i++; j++;
            }
            else if(nums1[i]>nums2[j]) j++;
            else i++;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                res.push_back(nums1[i]);
                i++; j++;
                continue;
            }
            while(nums1[i]<nums2[j]){
                i++;
                if(i>=nums1.size()) break;
            }
            while(nums1[i]>nums2[j]){
                j++;
                if(j>=nums2.size()) break;
            }
        }
        return res;
    }
};
