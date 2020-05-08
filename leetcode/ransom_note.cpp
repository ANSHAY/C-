class Solution {
public:
    map<char, int> mmp;
    bool canConstruct(string ransomNote, string magazine) {
        for(char m : magazine){
            mmp[m]++;
        }
        for(char r:ransomNote){
            if(mmp[r]) mmp[r]--;
            else return false;
        }
        return true;
    }
};
