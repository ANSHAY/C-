/*
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> vec(26);
        vector<int> res;
        vector<int> part(s.size()+1);
        int p=1;
        for(int i=0; i<s.size(); ++i){
            if(vec[s[i]-'a']>0){
                part[vec[s[i]-'a']] = i+1;
                p = vec[s[i]-'a'];
                for(int j=i-1; s[j]!=s[i]; j--){
                    vec[s[j]-'a'] = p;
                }
            }
            else{
                vec[s[i]-'a'] = p;
                part[vec[s[i]-'a']] = i+1;
            }
            p++;
        }
        int ind=0;
        for(int i=1; i<part.size(); i++){
            if(part[i]==0) break;
            if(part[i]<ind) continue;
            res.push_back(part[i]-ind);
            ind = part[i];
        }
        return res;
    }
};
