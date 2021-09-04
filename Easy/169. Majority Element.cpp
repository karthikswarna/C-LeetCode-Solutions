class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        // My Original Solution. Time: O(NlogN), Space: O(1)
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() / 2];

        // Boyer-Moore Voting Algorithm. Time: O(N), Space: O(1)
        int ans;
        int count = 0;
        for(int num: nums)
        {
            if(count == 0) ans = num;
            
            if(num == ans)
                count += 1;
            else
                count -= 1;
        }
        
        return ans;
    }
};