class Solution {
public:
    // Time: O(N), Space: O(1)
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        int len = nums.size();
        int evenId = 0;
        int oddId = 1;

        // This works because there are exactly half of even and odd numbers.
        while(evenId < len && oddId < len)
        {
            if(nums[evenId] % 2 == 0)
                evenId += 2;
            
            else if(nums[oddId] % 2 != 0)
                oddId += 2;
            
            else
            {
                swap(nums[evenId], nums[oddId]);
                evenId += 2;
                oddId += 2;
            }
        }
    
        return nums;
    }

    // Time: O(N), Space: O(N)
//     vector<int> sortArrayByParityII(vector<int>& nums)
//     {
//         int evenId = 0;
//         int oddId = 1;
//         vector<int> result(nums.size());

//         for(int i = 0; i < nums.size(); ++i)
//         {
//             if(nums[i] % 2 == 0)
//             {
//                 result[evenId] = nums[i];
//                 evenId += 2;
//             }
//             else
//             {
//                 result[oddId] = nums[i];
//                 oddId += 2;
//             }
//         }
        
//         return result;
//     }
};