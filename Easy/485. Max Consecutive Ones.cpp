class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int currentStreak = (nums[0] == 0) ? 0 : 1;
        int maxStreak = currentStreak;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == 0 && currentStreak > 0)
            {
                maxStreak = std::max(currentStreak, maxStreak);
                currentStreak = 0;
            }
            else if(nums[i] == 1)
                ++currentStreak;
        }
        maxStreak = std::max(currentStreak, maxStreak);

        return maxStreak;
    }
};