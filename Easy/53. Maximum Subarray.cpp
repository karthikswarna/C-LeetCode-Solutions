#include<algorithm>

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int max = nums[0];
        int max_current = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            // Maximum subarray ending at current index is either the (previous maximum subarray + current element) or just the current element.
            max_current = std::max(nums[i], nums[i] + max_current);
            
            if (max < max_current)
                max = max_current;
        }
        
        return max;
    }
};