class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int prev = nums[0];
        if(target <= prev)
            return 0;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] >= target)
            {
                return i;
            }
        }
        return nums.size();
    }
};