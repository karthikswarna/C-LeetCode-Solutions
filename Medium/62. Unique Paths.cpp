class Solution {
public:
    // Tabulation
    int uniquePaths(int m, int n)
    {
        int** memo = new int*[m + 1];
        for(int i = 0; i <= m; ++i)
            memo[i] = new int[n + 1];
        
        for(int i = 0; i <= m; ++i)
            for(int j = 0; j <= n; ++j)
                memo[i][j] = -1;

        // Base Case
        for(int i = 1; i <= m; ++i)
            memo[i][1] = 1;
        for(int j = 1; j <= n; ++j)
            memo[1][j] = 1;
        
        // Recursive Case
        for(int i = 2; i <= m; ++i)
            for(int j = 2; j <= n; ++j)
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
        
        return memo[m][n];
    }

    // Memoization.
//     int uniquePaths(int m, int n)
//     {
//         int** memo = new int*[m + 1];
//         for(int i = 0; i <= m; ++i)
//             memo[i] = new int[n + 1];
        
//         for(int i = 0; i <= m; ++i)
//             for(int j = 0; j <= n; ++j)
//                 memo[i][j] = -1;

//         return Util(m, n, memo);
//     }
    
//     int Util(int m, int n, int** memo)
//     {
//         if(m == 1 || n == 1) return 1;
//         if(memo[m][n] != -1) return memo[m][n];

//         return memo[m][n] = Util(m - 1, n, memo) + Util(m, n - 1, memo);
//     }
};