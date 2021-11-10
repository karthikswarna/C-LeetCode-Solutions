class Solution
{
    int m;
    int n;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        m = matrix.size();
        n = matrix[0].size();
        int maxLen = 0;
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                maxLen = std::max(maxLen, dfs(i, j, -1, matrix, memo, 1));

        return maxLen;
    }

    // Memoization logic: If the maxLen path starting at a node is already found, and another path has this node in the way, the previously known aswer can be used.
    int dfs(int i, int j, int prevVal, vector<vector<int>>& matrix, vector<vector<int>>& memo, int currLen)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= prevVal) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        memo[i][j] = 1 + std::max( {dfs(i + 1, j, matrix[i][j], matrix, memo, currLen + 1),
                                    dfs(i - 1, j, matrix[i][j], matrix, memo, currLen + 1),
                                    dfs(i, j + 1, matrix[i][j], matrix, memo, currLen + 1),
                                    dfs(i, j - 1, matrix[i][j], matrix, memo, currLen + 1)} );

        return memo[i][j];
    }
};