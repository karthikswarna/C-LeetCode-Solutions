class Solution {
public:
    int minStartValue(vector<int>& nums)
    {
        int currValue = 1;
        int startValue = 1;
        for(auto num: nums)
        {
            currValue += num;

            if(currValue < 1)
                startValue = max(1 + (1 - currValue), startValue);
        }
        
        return startValue;
    }
};