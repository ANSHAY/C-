/*
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

    If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
    For example, the word 'apple' becomes 'applema'.

    If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
    For example, the word "goat" becomes "oatgma".

    Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
    For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.

Return the final sentence representing the conversion from S to Goat Latin.
*/
class Solution {
public:
    vector<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
    bool isVowel(char c){
        for(auto& v:vowels){
            if(v==c) return true;
        }
        return false;
    }
    string toGoatLatin(string S) {
        stringstream ss(S);
        string w;
        string res = "";
        int c=1;
        bool start=true;
        while(ss>>w){
            if(!start){
                res+=' ';
            }
            else start=false;
            if(isVowel(w[0])){
                for(int i=0; i<w.size(); ++i){
                    res+=w[i];
                }
            }
            else{
                for(int i=1; i<w.size(); ++i){
                    res+=w[i];
                }
                res+=w[0];
            }
            res+="ma";
            for(int i=0; i<c; ++i){
                res+='a';
            }
            c++;
        }
        return res;
    }
};
