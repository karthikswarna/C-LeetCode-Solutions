class Solution {
public:
    // Faster and simpler version. 
    // Idea: The condition will be false for all the elements before the peak. At the first peak, it returns true
    int findPeakElement(vector<int>& nums)
    {
        for(int i = 0; i < nums.size() - 1; ++i)
            if(nums[i] > nums[i + 1])
                return i;

        return nums.size() - 1;
    }
 
    // Original Solution
//     int findPeakElement(vector<int>& nums)
//     {
//         if((nums.size() == 1) || (nums[0] > nums[1])) return 0;

//         int i;
//         for(i = 1; i < nums.size() - 1; ++i)
//             if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
//                 return i;
        
//         if(nums[i] > nums[i - 1]) return i;
//         return -1;
//     }
};