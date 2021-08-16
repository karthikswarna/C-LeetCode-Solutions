class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
        int smallest = INT_MAX;
        int nextSmallest = INT_MAX;
        for(auto &n: nums)
        {
            if(n <= smallest)
                smallest = n;

            else if(n <= nextSmallest)
                nextSmallest = n;

            else
                return true;
        }

        return false;
    }
};