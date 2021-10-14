class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> memo(n + 1, INT_MAX);

        // Memoization Solution - TLE.
        // return numSquaresUtil(n, memo);

        // Tabulation Solution.
        memo[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
                memo[i] = min(memo[i], memo[i - j*j] + 1);
        }
        
        return memo[n];
    }
    
    int numSquaresUtil(int n, vector<int>& memo)
    {
        if(n == 0) return 0;
        if(memo[n] != INT_MAX) return memo[n];

        int sqrt = std::sqrt(n);

        int ans = INT_MAX;
        for(int i = sqrt; i >= 1; --i)
            ans = std::min(ans, numSquares(n - (i * i)) + 1);

        return memo[n] = ans;
    }
};