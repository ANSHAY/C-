/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1{version1}, s2{version2};
        int n;
        char c;
        vector<int> v1, v2;
        while(s1>>n){
            v1.push_back(n);
            s1>>c;
        }
        while(s2>>n){
            v2.push_back(n);
            s2>>c;
        }
        int i=0;
        while(i<v1.size() && i<v2.size()){
            if(v1[i]>v2[i]) return 1;
            if(v1[i]<v2[i]) return -1;
            i++;
        }
        while(i<v1.size()){
            if(v1[i]>0) return 1;
            i++;
        }
        while(i<v2.size()){
            if(v2[i]>0) return -1;
            i++;
        }
        return 0;
    }
};
