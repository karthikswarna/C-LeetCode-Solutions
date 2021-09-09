class Solution {
public:
    // Time: O(N*log(N))
//     int longestConsecutive(vector<int>& nums)
//     {
//         sort(nums.begin(), nums.end());

//         int longestSeqLen = 0;
//         int currentSeqLen = 0;
//         for(int i = 0; i < nums.size(); ++i)
//         {
//             if(i == 0 || nums[i] == nums[i - 1] + 1)
//                 ++currentSeqLen;
//             else
//             {
//                 longestSeqLen = std::max(currentSeqLen, longestSeqLen);
//                 currentSeqLen = 1;
//             }

//             // Avoid duplicates.
//             while(i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
//         }

//         longestSeqLen = std::max(currentSeqLen, longestSeqLen);
        
//         return longestSeqLen;
//     }
    
    // Time: O(N)
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> S;
        for(auto num: nums)
            S.insert(num);
        
        int longestSeqLen = 0;
        int currentSeqLen = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            // If any less number is not present, this is the start of a sequence.
            if(S.find(nums[i] - 1) == S.end())
            {
                int curr = nums[i];
                currentSeqLen = 0;
                while(S.find(curr) != S.end())
                {
                    ++currentSeqLen;
                    ++curr;
                }
                
                longestSeqLen = std::max(currentSeqLen, longestSeqLen);
            }
        }
        
        return longestSeqLen;
    }
};