class Solution {
public:
    bool cmpstr(string s1, string s2, int index){
        for(int i=0;i<s2.size();++i){
            if(s1[index+i]!=s2[i]) return false;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        if(haystack=="" || needle.size()>haystack.size()) return -1;
        for(int i=0; i<=haystack.size()-needle.size();++i){
            if(haystack[i]==needle[0]){
                if(cmpstr(haystack, needle, i)) return i;
            }
        }
        return -1;
    }
};
/*testcases
"hello"
"ll"
"aaaaa"
"bba"
""
""
"asdgfddscewds"
""
"dwertvcsdrd"
"vdfed"
"asdfg"
"asdfg"
"sacd"
"ascdvwdsc"
"aaaaa"
"aaa"
"sssss"
"s"
"asasas"
"a"
"asasas"
"s"
"asasas"
"as"
"asasas"
"sa"
*/
