class Solution {
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        // Memoization.
        // vector<vector<int>> memo(s1.size(), vector<int>(s2.size(), -1));
        // return LCSUtil(s1, s2, 0, 0, memo);
    
        // Tabulation
        int l1 = s1.size();
        int l2 = s2.size();
        vector<vector<int>> memo(l1, vector<int>(l2, 0));
        
        // Base Cases
        memo[0][0] = (s1[0] == s2[0]) ? 1 : 0;
        for(int i = 1; i < l1; ++i)
            if(s1[i] == s2[0] || memo[i - 1][0] == 1)
                memo[i][0] = 1;

        for(int j = 1; j < l2; ++j)
            if(s1[0] == s2[j] || memo[0][j - 1] == 1)
                memo[0][j] = 1;
        
        // Recursive Case
        for(int i = 1; i < l1; ++i)
        {
            for(int j = 1; j < l2; ++j)
            {
                if(s1[i] == s2[j])
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                else
                    memo[i][j] = std::max(memo[i - 1][j], memo[i][j - 1]);
            }
        }

        return memo[l1 - 1][l2 - 1];
    }
    
    int LCSUtil(string& s1, string& s2, int i, int j, vector<vector<int>>& memo)
    {
        if(i >= s1.size() || j >= s2.size()) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        int maxLen;
        if(s1[i] == s2[j])
            maxLen = 1 + LCSUtil(s1, s2, i + 1, j + 1, memo);
        else
            maxLen = std::max(LCSUtil(s1, s2, i + 1, j, memo), 
                              LCSUtil(s1, s2, i, j + 1, memo));
        
        return memo[i][j] = maxLen;
    }

};