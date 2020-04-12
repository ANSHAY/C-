class Solution {
public:
    bool anagrams(string s1, string s2){
        if(s1.size() != s2.size()) return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1==s2;
    }
/*
//Solution 1: Time limit exceeded
    void add_to_group(vector<vector<string>>& group, string str){
        for(vector<string>& v:group){
            if(anagrams(str, v[0])){
                v.push_back(str);
                return;
            }
        }
        group.push_back(vector<string>{str});
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;
        for(string s:strs){
            add_to_group(group, s);
        }
        return group;
    }
*/
/*
// Solution 2: Divide and conquer : time limit exceeded
    vector<vector<string>> divide_and_merge(vector<string>& strs, int start, int end){
        vector<vector<string>> left;
        if(start>=end) {
            left.push_back(vector<string>{strs[start]});
            return left;
        }
        vector<vector<string>> right;
        // divide
        int mid = (end+start)/2;
        left = divide_and_merge(strs, start, mid);
        right = divide_and_merge(strs, mid+1, end);
        // merge
        bool found;
        int left_len = left.size();
        while(!right.empty()){
            vector<string> v_r = right.back();
            right.pop_back();
            found = false;
            for(int i=0; i<left_len; ++i){
                if(anagrams(left[i][0],v_r[0])){
                    for(string s:v_r){
                        left[i].push_back(s);
                    }
                    found = true;
                    break;
                }
            }
            if (!found){
                left.push_back(v_r);
            }
        }
        return left;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==0) return vector<vector<string>>();
        return divide_and_merge(strs, 0, strs.size()-1);
    }
*/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> myMap;
        vector<vector<string>> group;
        string ss;
        for(string s:strs){
            ss = s;
            sort(ss.begin(), ss.end());
            if(myMap.count(ss)){
                myMap[ss].push_back(s);
            }
            else{
                myMap[ss] = vector<string>{s};
            }
        }
        for(const auto & x:myMap){
            group.push_back(x.second);
        }
        return group;
    }
};

/* testcases
["eat","tea","tan","ate","nat","bat"]
["avef","afberb","thnsftn","sbfaerb","aebaet"]
[]
["aaaaa","bbbbb","ccccc","ccccc","ccccc","bbbbb"]
["fevaaer"]
["avdawv","avrv"]
["avwrrb","afvrar"]
["sdfgh","sfdgh"]

*/
