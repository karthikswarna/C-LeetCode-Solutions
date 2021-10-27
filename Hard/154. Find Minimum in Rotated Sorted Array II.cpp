class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        // No rotations
        if(nums[low] < nums[high])
            return nums[low];

        while(low < high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] < nums[low])
            {
                high = mid;
                ++low;          // nums[low] is already greater than nums[mid], so can be increased.
            }

            else if(nums[mid] > nums[high])
                low = mid + 1;  // nums[mid] is already greater than nums[0], so mid + 1 can be used.

            else                // nums[lo] <= nums[mi] <= nums[hi]
                --high;
        }

        return nums[low];
    }
};