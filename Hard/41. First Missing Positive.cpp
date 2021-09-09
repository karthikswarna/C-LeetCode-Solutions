class Solution {
public:
    // Space: O(N)
//     int firstMissingPositive(vector<int>& nums)
//     {
//         int len = nums.size();
//         vector<bool> isSmallest(len, true);
//         for(int i = 0; i < len; ++i)
//         {
//             if(nums[i] > 0 && nums[i] <= len)
//                 isSmallest[nums[i] - 1] = false;
//         }
        
//         for(int i = 0; i < len; ++i)
//             if(isSmallest[i]) return i + 1;
        
//         return len + 1;
//     }
    
    // Space: O(1)   
    int firstMissingPositive(vector<int>& A)
    {
        int len = A.size();
        for(int i = 0; i < len; ++ i)
            while(A[i] > 0 && A[i] <= len && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < len; ++ i)
            if(A[i] != i + 1) return i + 1;
        
        return len + 1;
    }
};