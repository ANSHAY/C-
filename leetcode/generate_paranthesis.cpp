class Solution {
public:
    vector<string> res;

    void backtrack(string str, int op, int cl, int n){
        if(str.size()==2*n){
            res.push_back(str);
            return;
        }
        if(op<n){
            backtrack(str+'(', op+1, cl, n);
        }
        if(cl<op){
            backtrack(str+')', op, cl+1, n);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        if(n==0) return res;
        string str;
        backtrack(str, 0, 0, n);
        return res;
    }
};
