class Solution {
public:
    // Time: O(N) Space: O(N)
//     vector<int> productExceptSelf(vector<int>& nums)
//     {
//         int len = nums.size();
//         vector<int> prefix(len, 1);
//         vector<int> suffix(len, 1);
        
//         prefix[0] = 1;
//         for(int i = 1; i < len; ++i)
//             prefix[i] = prefix[i - 1] * nums[i - 1];

//         suffix[len - 1] = 1;
//         for(int i = len - 2; i >= 0; --i)
//             suffix[i] = suffix[i + 1] * nums[i + 1];

//         for(int i = 0; i < nums.size(); ++i)
//             nums[i] = prefix[i] * suffix[i];

//         return nums;
//     }

    // Time: O(N) Space: O(1)
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int len = nums.size();
        int prefixProd = 1;
        int suffixProd = 1;
        
        vector<int> output(len, 1);
        for(int i = 0; i < len; ++i)
        {
            output[i] *= prefixProd;
            prefixProd *= nums[i];
        }
        
        for(int i = len - 1; i >= 0; --i)
        {
            output[i] *= suffixProd;
            suffixProd *= nums[i];
        }

        return output;
    }
};