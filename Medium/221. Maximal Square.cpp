class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int maxSideLen = 0;
        vector<vector<int>> memo(m + 2, vector<int>(n + 2, 0));
        // memo[i][j] represents the side length of the maximum square that can be formed with (i,j)th cell as the bottom-right corner.
        
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(matrix[i - 1][j - 1] == '1')
                {
                    memo[i][j] = min({ memo[i - 1][j], memo[i - 1][j - 1], memo[i][j - 1] }) + 1;
                    maxSideLen = max(memo[i][j], maxSideLen);
                }
            }
        }
        
        return maxSideLen * maxSideLen;
    }
};