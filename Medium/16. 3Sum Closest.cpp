class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        // This is solution simplified using the 'minDiff'. For solution using 'closestSum', refer previous submission.
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int minDiff = INT_MAX;

        for(int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
    
                if(std::abs(target - sum) < std::abs(minDiff))
                    minDiff = target - sum; // Not abs(target - sum)
                
                if(sum == target)
                    return target;
                
                else if(sum < target)
                    j++;
                
                else if(sum > target)
                    k--;
            }
        }
        
        return target - minDiff;
    }
};