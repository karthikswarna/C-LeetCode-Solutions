class Solution {
public:
    int lengthOfLIS(vector<int>& A)
    {
        // Memoization
        // vector<vector<int>> memo(nums.size(), vector<int>(nums.size() + 1, -1));
        // return lengthOfLISUtil(nums, -1, 0, memo);

        //Tabulation
        vector<int> dp(A.size(), 1);
        for(int i = 1; i < A.size(); i++)
            for(int j = 0; j < i; j++)
                if(A[j] < A[i])
                    dp[i] = std::max(dp[i], dp[j] + 1);
        
        return *max_element(dp.begin(), dp.end());
    }

    int lengthOfLISUtil(vector<int>& nums, int prev, int curr, vector<vector<int>>& memo)
    {
        if(curr >= nums.size()) return 0;
        if(memo[prev + 1][curr] != -1) return memo[prev + 1][curr];

        int count = 0;
        if(prev == -1)
        {
            for(int i = 0; i < nums.size(); ++i)
                count = max(1 + lengthOfLISUtil(nums, i, i + 1, memo), count);
        }
        else
        {
            if(nums[curr] > nums[prev])
                count = max( lengthOfLISUtil(nums, prev, curr + 1, memo), 1 + lengthOfLISUtil(nums, curr, curr + 1, memo) );
            else
                count = lengthOfLISUtil(nums, prev, curr + 1, memo);
        }
        
        return memo[prev + 1][curr] = count;
    }
};