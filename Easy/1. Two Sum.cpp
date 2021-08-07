class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // One-pass Hash Table approach.
        unordered_map<int, int> M;
        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if(M.find(complement) != M.end())
                return vector<int>{M[complement], i};
            
            M[nums.at(i)] = i;
        }
        
        return vector<int>{};
        
        // Another 2-pointer approach using sorted array is also good. See 3Sum and 4Sum submissions.
    }
};