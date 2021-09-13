class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        // Recursion + Memoization
//         int n = nums.size();
//         vector<vector<unordered_map<int, int>>> memo(n, vector<unordered_map<int, int>>(n + 1));

//         int count = 0;
//         for(int i = 0; i < n; ++i)
//             for(int j = i + 1; j < n; ++j)
//                 count += countSeqs(nums, j, 2, (long)nums[j] - (long)nums[i], memo);

//         return count;
        
        // Iteration + Tabulation
        int count = 0;
        vector<unordered_map<long, int>> memo(nums.size());

        for(int i = 0; i < nums.size(); i++) 
        {
            for(int j = 0; j < i; j++) 
            {
                long d = (long)nums[i] - (long)nums[j];
                
                ++memo[i][d];

                if(memo[j].find(d) != memo[j].end())
                {
                    memo[i][d] += memo[j][d];
                    count += memo[j][d];
                }
            }
        }

        return count;
    }

    int countSeqs(vector<int>& nums, int currId, int seqLen, long d, vector<vector<unordered_map<int, int>>>& memo)
    {
        if(memo[currId][seqLen].find(d) != memo[currId][seqLen].end()) return memo[currId][seqLen][d];

        int count = (seqLen >= 3) ? 1 : 0;
        for(int nextId = currId + 1; nextId < nums.size(); ++nextId)
            if((long)nums[nextId] - (long)nums[currId] == d)
                count += countSeqs(nums, nextId, seqLen + 1, d, memo);

        return memo[currId][seqLen][d] = count;
    }
};