class Solution {
public:
    int romanToInt(string s) {
        char p='a';
        int res=0;
        unordered_map<char, int> mmp{{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        for(char c:s){
            res += mmp[c];
            if((c=='V'||c=='X')&&(p=='I')) res-=2;
            if((c=='L'||c=='C')&&(p=='X')) res-=20;
            if((c=='D'||c=='M')&&(p=='C')) res-=200;
            p = c;
        }
        return res;
    }
};
