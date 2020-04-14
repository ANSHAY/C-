class Solution {
public:
    map<char, vector<char>> mapping{{'2',{'a','b','c'}},{'3',{'d','e','f'}},{'4',{'g','h','i'}},
                                    {'5',{'j','k','l'}},{'6',{'m','n','o'}},{'7',{'p','q','r','s'}},
                                    {'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};
    vector<string> res;

    void backtrack(string digits, string cur, int k){
        if(k==0){
            res.push_back(cur);
        }
        char dig = digits[digits.size()-k];
        for(char c:mapping[dig]){
            backtrack(digits, cur+c, k-1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits=="") return res;
        string cur;
        backtrack(digits, cur, digits.size());
        return res;
    }
};
