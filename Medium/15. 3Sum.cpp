class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        if(nums.size() <= 2) return vector<vector<int>>{};
        
        sort(nums.begin(), nums.end());
     
        vector<vector<int>> result;
        for(int i = 0; i < nums.size() - 2; i++)
        {
            // If current element is same as previous one, we would have already generated tuples using that element. So continue;
            if(i == 0 || (i > 0 && nums.at(i) != nums.at(i - 1)))
            {
                // Solve 2Sum with nums[i] as target.
                int target = 0-nums.at(i);
                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right)
                {
                    if(nums[left] + nums[right] == target)
                    {
                        result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        
                        while(left < right && nums[left] == nums[left + 1]) left++;
                        left++;
                        while(left < right && nums[right] == nums[right - 1]) right--;
                        right--;
                    }
                    
                    else if(nums[left] + nums[right] > target)
                        right--;
                    
                    else if(nums[left] + nums[right] < target)
                        left++;
                }
            }
        }
        
        return result;
    }
};