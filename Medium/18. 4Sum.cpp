class Solution {
public:
    // Two Pointers - kSum - Just in case they lock the solution! xP
    // Implement outside k-2 loops using recursion and when k = 2, call 2Sum function.
    // Time Complexity: O(n^{k - 1}). Space Complexity: O(n) (recursion stack)
    vector<vector<int>> fourSum(vector<int>& A, int target)
    {
        sort(A.begin(), A.end());
        vector<vector<int>> result;
        
        int len = A.size();
        for(int i = 0; i < len - 3; i++)
        {
            for(int j = i + 1; j < len - 2; j++)
            {
                // Solve for 2Sum with halfTarget.
                int halfTarget = target - (A[i] + A[j]);
                int left = j + 1;
                int right = len - 1;
                while(left < right)
                {
                    if(A[left] + A[right] == halfTarget)
                    {
                        result.push_back(vector<int>{A[i], A[j], A[left], A[right]});
                            
                        while(left < right && A[left] == A[left + 1]) left++;
                        left++;
                        while(left < right && A[right] == A[right - 1]) right--;
                        right--;
                    }
                    
                    else if(A[left] + A[right] < halfTarget)
                        left++;
                        
                    else if(A[left] + A[right] > halfTarget)
                        right--;
                }

            // Avoid duplicate quadruples - can skip same elements as we have already generated quads with that.
                while((j < len - 2) && (A[j] == A[j + 1])) j++;
            }
            
            // Avoid duplicate quadruples - can skip same elements as we have already generated quads with that.
            while((i < len - 3) && (A[i] == A[i + 1])) i++;
        }
        
        return result;
    }
};


// Hash Set Solution - kSum - Just in case they lock the solution! xP
// This solution just differs from above in twoSum function implementation. Has an additional if condition to check duplicates.
// Time Complexity: O(n^{k - 1}). Space Complexity: O(n) (Hash set)

// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     sort(begin(nums), end(nums));
//     return kSum(nums, target, 0, 4);
// }
// vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
//     vector<vector<int>> res;
//     if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
//         return res;
//     if (k == 2)
//         return twoSum(nums, target, start);
//     for (int i = start; i < nums.size(); ++i)
//         if (i == start || nums[i - 1] != nums[i])
//             for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
//                 res.push_back({nums[i]});
//                 res.back().insert(end(res.back()), begin(set), end(set));
//             }
//     return res;
// }
// vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
//     vector<vector<int>> res;
//     unordered_set<int> s;
//     for (auto i = start; i < nums.size(); ++i) {
//         if (res.empty() || res.back()[1] != nums[i])
//             if (s.count(target - nums[i]))
//                 res.push_back({ target - nums[i], nums[i]});
//         s.insert(nums[i]);
//     }
//     return res;
// }