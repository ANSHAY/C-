/*
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows.

Please note that both secret number and friend's guess may contain duplicate digits.
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> vs(10);
        vector<int> vg(10);
        int bulls=0, cows=0;
        for(int i=0; i<secret.size(); i++){
            vs[secret[i]-'0']++;
            vg[guess[i]-'0']++;
            if(secret[i]==guess[i]) bulls++;
        }
        for(int i=0; i<vs.size(); i++){
            if(vs[i]>0 && vg[i]>0) cows+=min(vs[i], vg[i]);
        }
        string res = to_string(bulls)+"A"+to_string(cows-bulls)+"B";
        return res;
    }
};
