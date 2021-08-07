class Solution {
public:
    // Sliding Window Technique
    int minSubArrayLen(int target, vector<int>& A)
    {
        int minLen = INT_MAX;
        int sum = 0;
        int left = 0;

        for(int right = 0; right < A.size(); right++)
        {
            sum += A[right];
            while((sum >= target) && (left <= right))
            {
                minLen = std::min(minLen, right - left + 1);
                sum -= A[left];
                left++;
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
    
// Brute Force
//     int minSubArrayLen(int target, vector<int>& A)
//     {
//         int minLen = INT_MAX;
//         int currLen = 0;
//         int sum = 0;
        
//         // For every index, find the minimum length subarray that starts at that index.
//         for(int i = 0; i < A.size(); i++)
//         {
//             // Calculate the minimum length subarray that starts at i.
//             sum = 0;
//             currLen = 0;
//             for(int j = i; j < A.size(); j++)
//             {
//                 sum += A[j];
//                 currLen++;
//                 if(sum >= target)
//                 {
//                     minLen = std::min(currLen, minLen);
//                     break;
//                 }
//             }
//         }
        
//         return minLen == INT_MAX ? 0 : minLen;
//     }
};