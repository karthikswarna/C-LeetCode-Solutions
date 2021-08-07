class Solution {
public:
    int climbStairs(int n)
    {
        unordered_map<int, int> memo;
        return climbStairs(n, memo);
    }
    
    int climbStairs(int n, unordered_map<int, int> &memo)
    {
        if(memo.find(n) != memo.end()) return memo[n];
        if(n == 0) return 1;
        if(n < 0) return 0;
        
        memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
        return memo[n];
    }
};