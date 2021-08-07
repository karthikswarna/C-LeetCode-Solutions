class Solution {
public:
    int longestPalindromeSubseq(string s)
    {
        int size = s.size();
        vector<vector<int>> memo(size, vector<int>(size));
        return longestPalindromeSubseqUtil(s, 0, size-1, memo);
    }
    
    int longestPalindromeSubseqUtil(string &s, int i, int j, vector<vector<int>> &memo)
    {
        if(i > j) return 0;
        if(i == j) return 1;
        if(memo[i][j]) return memo[i][j];
        
        if(s[i] == s[j]) 
            memo[i][j] = longestPalindromeSubseqUtil(s, i+1, j-1, memo) + 2;
        
        else
            memo[i][j] = std::max(longestPalindromeSubseqUtil(s, i, j-1, memo), longestPalindromeSubseqUtil(s, i+1, j, memo));
        
        return memo[i][j];
    }
};