class Solution {
public:
    int lengthOfLIS(vector<int>& A)
    {
        vector<int> dp(A.size(), 1);
        for(int i = 1; i < A.size(); i++)
            for(int j = 0; j < i; j++)
                if(A[j] < A[i])
                    dp[i] = std::max(dp[i], dp[j] + 1);
        
        return *max_element(dp.begin(), dp.end());
    }
};