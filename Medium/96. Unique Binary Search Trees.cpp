class Solution
{
public:
    int numTrees(int n)
    {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        return numBSTrees(1, n, memo);
    }
    
    int numBSTrees(int left, int right, vector<vector<int>>& memo)
    {
        if(left >= right) return 1;
        if(memo[left][right] != 0) return memo[left][right];

        int count = 0;
        for(int i = left; i <= right; ++i)
            count += numBSTrees(left, i - 1, memo) * numBSTrees(i + 1, right, memo);

        return memo[left][right] = count;
    }
};