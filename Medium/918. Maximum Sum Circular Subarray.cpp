class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        // Approach-4: Kadane's Algorithm (Min Variant)
        if(nums.size() == 1) return nums.at(0);        
        
        // Maximum sum - one-interval subarrays.
        int sum = nums.at(0);
        int local_ans = nums.at(0);
        int ans1 = nums.at(0);
        for(int i = 1; i < nums.size(); i++)
        {
            local_ans = std::max(nums.at(i), local_ans + nums.at(i));
            ans1 = std::max(local_ans, ans1);
            
            sum += nums.at(i);
        }
        
        // Minimum sum - interior part of two-interval subarray. interior in A[1:]
        local_ans = nums.at(1); 
        int ans2 = nums.at(1);
        for(int i = 2; i < nums.size(); i++)
        {
            local_ans = std::min(local_ans + nums.at(i), nums.at(i));
            ans2 = std::min(local_ans, ans2);
        }
        ans2 = sum - ans2;
        
        // Minimum sum - interior part of two-interval subarray. interior in A[:-1]
        local_ans = nums.at(0);
        int ans3 = nums.at(0);
        for(int i = 1; i < nums.size() - 1; i++)
        {
            local_ans = std::min(local_ans + nums.at(i), nums.at(i));
            ans3 = std::min(local_ans, ans3);
        }
        ans3 = sum - ans3;
        
        return std::max(ans1, std::max(ans2, ans3));
    }
};