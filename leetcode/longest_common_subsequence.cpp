class Solution {
public:
/*
    int LCS(string& s1, string& s2, vector<vector<int>>& dp, int i, int j){
        if(i>=dp.size() || j>=dp[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1.empty() || s2.empty()) dp[i][j] = 0;
        else if(s1[i] == s2[j]){
            dp[i][j] = 1 + LCS(s1, s2, dp, i+1, j+1);
        }
        else{
            dp[i][j] = max(LCS(s1, s2, dp, i+1, j), LCS(s1, s2, dp, i, j+1));
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return LCS(text1, text2, dp, 0, 0);
    }
*/
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size()));
        int i=0,j=0;
        for(int i=0; i<text1.size(); ++i){
            for(int j=0; j<text2.size(); ++j){
                if(text1[i] == text2[j]){
                    if(i>0 && j>0){
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                else{
                    if(i>0 && j>0){
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                    else if(i>0){
                        dp[i][j] = dp[i-1][j];
                    }
                    else if(j>0){
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};
