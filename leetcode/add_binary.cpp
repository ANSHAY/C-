class Solution {
public:
    string addBinary(string a, string b){
        int i=a.size()-1, j=b.size()-1;
        string res="";
        int sum=0, c=0;
        while(i>=0 || j>=0){
            sum = c;
            if(i>=0) sum+=(a[i--]-'0');
            if(j>=0) sum+=(b[j--]-'0');
            res.insert(res.begin(), sum%2 + '0');
            c = sum/2;
        }
        if(c) res.insert(res.begin(), '1');
        return res;
    }
}

class Solution {
public:
    map<bool, char> btoc;
    map<char, bool> ctob;
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        char c = '0';
        char s = '0';
        string res;
        btoc[0]='0'; btoc[1]='1';
        ctob['0']=0; ctob['1']=1;
        while(i>=0 && j>=0){
            s = btoc[(ctob[a[i]] ^ ctob[b[j]]) ^ ctob[c]];
            c = btoc[(ctob[a[i]] & ctob[b[j]]) | (ctob[c] & (ctob[a[i]] | ctob[b[j]]))];
            res = s+res;
            i--; j--;
        }
        while(i>=0){
            s = btoc[ctob[a[i]] ^ ctob[c]];
            c = btoc[ctob[a[i]] & ctob[c]];
            res = s+res;
            i--;
        }
        while(j>=0){
            s = btoc[ctob[b[j]] ^ ctob[c]];
            c = btoc[ctob[b[j]] & ctob[c]];
            res = s+res;
            j--;
        }
        if(c=='1'){
            res = c+res;
        }
        return res;
    }
};
/* testcases
"11"
"1"
"111"
"101"
"1"
"1"
"0"
"0"
"101010011001"
"101001"
"10001111101101"
"110001011001010101001"
*/
