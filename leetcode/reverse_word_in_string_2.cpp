class Solution {
public:
    string reverseWords(string s) {
        if(s=="") return "";
        string res="", temp="";
        for(int i=s.size()-1; i>=0; --i){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else{
                if(res=="") res = temp;
                else{
                    res = temp + " " + res;
                }
                temp="";
            }
        }
        if(res=="") res = temp;
        else{
            res = temp + " " + res;
        }
        return res;
    }
};
/* testcases
"Let's take LeetCode contest"
"ervrvd"
""
"dvae adva"
"v fvae"
"avd f"
"f f f"
"d f g"
*/
