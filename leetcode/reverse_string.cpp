class Solution {
public:
    int i;
    char temp;
    void reverseString(vector<char>& s) {
        if(s.empty()){
            return;
        }
        if(i>=s.size()-i-1){
            return;
        }
        temp = s[i];
        s[i] = s[s.size()-i-1];
        s[s.size()-i-1] = temp;
        i++;
        reverseString(s);
    }
};
