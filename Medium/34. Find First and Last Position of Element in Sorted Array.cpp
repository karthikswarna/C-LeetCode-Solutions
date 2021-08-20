class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        auto itPair = equal_range(nums.begin(), nums.end(), target);
        
        if(itPair.first == nums.end() || *itPair.first != target)
            return vector<int>{-1, -1};

        return vector<int>{ static_cast<int>(itPair.first - nums.begin()), 
                            static_cast<int>(itPair.second - nums.begin() - 1) };
    }
};