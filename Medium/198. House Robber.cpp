class Solution {
public:
    int rob(vector<int>& nums)
    {
        vector<int> memo(nums.size(), -1);
        return rob(nums, -1, memo);
    }

    int rob(vector<int>& nums, int curr, vector<int> &memo)
    {
        if(curr != -1 && memo[curr] != -1) return memo[curr];

        if(curr == -1)
        {
            int profit = 0;
            for(int i = 0; i < nums.size(); ++i)
                profit = std::max(rob(nums, i, memo), profit);            
            
            return profit;
        }

        int profit = nums[curr];
        for(int i = curr + 2; i < nums.size(); ++i)
            profit = std::max(nums[curr] + rob(nums, i, memo), profit);
        
        return memo[curr] = profit;
    }
};