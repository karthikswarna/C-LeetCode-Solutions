class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int zeros = 0;
        int ones = 0;
        for(auto &i: nums)
        {
            if(i == 0)
                ++zeros;
            else if(i == 1)
                ++ones;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i < zeros)
                nums[i] = 0;
            else if(i >= zeros && i < zeros + ones)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};s