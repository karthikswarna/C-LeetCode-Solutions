class Solution {
public:
    // Simple Dynamic Programming solution.
    int findLength(vector<int>& A, vector<int>& B)
    {
        int m = A.size();
        int n = B.size();
        int ans = 0;
        
        // dp[i][j] represents the length of the longest common subarray ending at i in A and j in B. 
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialization - 0th column
        for(int i = 0; i < m; i++)
        {
            dp[i][0] = A[i] == B[0] ? 1 : 0;
            
            if(ans == 0 && dp[i][0] == 1)
                ans = 1;
        }
        
        // Initialization - 0th row
        for(int j = 1; j < n; j++)
        {
            dp[0][j] = A[0] == B[j] ? 1 : 0;

            if(ans == 0 && dp[0][j] == 1)
                ans = 1;
        }
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = std::max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }

// Using Hash Table and matching.
//     int findLength(vector<int>& nums1, vector<int>& nums2)
//     {
//         unordered_map<int, vector<int>> nums1_map;
//         for(int i = 0; i < nums1.size(); i++)
//         {
//             if(nums1_map.find(nums1[i]) != nums1_map.end())
//                 nums1_map[nums1[i]].push_back(i);
//             else
//                 nums1_map[nums1[i]] = vector<int>{i};
//         }
        
//         int max = 0;
//         for(int i = 0; i < nums2.size(); i++)
//         {
//             // If current element is also present in nums1
//             if(nums1_map.find(nums2[i]) != nums1_map.end())
//             {
//                 // Get all the indices of this element in nums1 and iterate through them. 
//                 vector<int> indices = nums1_map[nums2[i]];
//                 for(int j = 0; j < indices.size(); j++)
//                 {
//                     // Find the length of the subarray starting at this matching element.
//                     int ii = i;
//                     int k = indices[j];
//                     int len = 0;
//                     while(nums1[k] == nums2[ii] && k < nums1.size() && ii < nums2.size())
//                     {
//                         len++;
//                         ii++;
//                         k++;
//                     }
                    
//                     max = std::max(len, max);
//                 }
//             }
//         }
    
//         return max;
//     }
};