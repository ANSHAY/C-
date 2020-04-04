class Solution {
public:
    string cur;
    int n;
    vector<pair<string, int>> stack;
    string decodeString(string s) {
        if(s==""){
            return s;
        }
        string cur = "";
        n = 0;
        for(char ch:s){
            if(ch=='['){
                stack.push_back(make_pair(cur, n));
                cur = "";
                n = 0;
            }
            else if(ch==']'){
                pair p = stack.back();
                stack.pop_back();
                string prev = p.first;
                n = p.second;
                while(n>0){
                    prev += cur;
                    n--;
                }
                cur = prev;
            }
            else if(isdigit(ch)){
                n = 10*n + ch - '0';
            }
            else{
                cur+=ch;
            }
        }
        return cur;
    }
};
