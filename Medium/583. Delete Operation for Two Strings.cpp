class Solution {
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        int lcs = LCS(word1, word2, word1.size(), word2.size(), memo);
    
        return (word1.size() - lcs) + (word2.size() - lcs);
    }

    int LCS(string word1, string word2, int i, int j, vector<vector<int>>& memo)
    {
        if(i == 0 || j == 0) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        int maxLen = 0;
        if(word1[i - 1] == word2[j - 1])
            maxLen = 1 + LCS(word1, word2, i - 1, j - 1, memo);
        else
            maxLen = std::max(LCS(word1, word2, i - 1, j, memo), LCS(word1, word2, i, j - 1, memo));

        memo[i][j] = maxLen;
        return maxLen;
    }
};