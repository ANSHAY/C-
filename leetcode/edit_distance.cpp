class Solution {
public:
    int treetrace(string& word1, string& word2, vector<vector<int>>& dp, int l1, int l2){
        if(l1 == 0) return l2;
        if(l2 == 0) return l1;
        if(dp[l1][l2]!=-1) return dp[l1][l2];
        if(word1[l1-1] == word2[l2-1]){
            dp[l1][l2] = treetrace(word1, word2, dp, l1-1, l2-1);
            return dp[l1][l2];
        }
        dp[l1][l2] =  1+ min(min(treetrace(word1, word2, dp, l1-1, l2),
                                 treetrace(word1, word2, dp, l1, l2-1)),
                             treetrace(word1, word2, dp, l1-1, l2-1));
        return dp[l1][l2];
    }
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, -1));
        return treetrace(word1, word2, dp, l1, l2);
    }
};
