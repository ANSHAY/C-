class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1F(26);
        vector<int> s2F(26);
        if(s2.size()<s1.size()) return false;
        int i;
        for(i=0; i<s1.size(); ++i){
            s1F[s1[i]-'a']++;
            s2F[s2[i]-'a']++;
        }
        if(s1F==s2F) return true;
        while(i<s2.size()){
            s2F[s2[i]-'a']++;
            s2F[s2[i-s1.size()]-'a']--;
            if(s1F==s2F) return true;
            ++i;
        }
        return false;
    }
};
