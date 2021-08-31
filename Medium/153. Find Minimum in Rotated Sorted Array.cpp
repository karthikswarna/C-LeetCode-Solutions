class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        
        // No rotations.
        if(nums[low] <= nums[high]) 
            return nums[0];

        // Binary Search.
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            
            else if(nums[mid - 1] > nums[mid])
                return nums[mid];

            else if(nums[mid] > nums[0])       // [k+1, k+2, k+3,..., N, 0, 1, .., k] where k < N - k.
                low = mid + 1;

            else
                high = mid - 1;
        }
        
        return -1;
    }
};