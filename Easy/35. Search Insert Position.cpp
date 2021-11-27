class Solution {
public:
    // O(log N)
    int searchInsert(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size();
        
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[mid] < target)
                low = mid + 1;

            else // nums[mid] > target. mid can potentially be the answer. And hence, high is not mid - 1.
                high = mid;
                
        }
        
        return low;
    }

    // O(N)
    // int searchInsert(vector<int>& nums, int target) 
    // {
    //     int prev = nums[0];
    //     if(target <= prev)
    //         return 0;

    //     for(int i = 1; i < nums.size(); i++)
    //     {
    //         if(nums[i] >= target)
    //         {
    //             return i;
    //         }
    //     }
    //     return nums.size();
    // }
};