class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        unordered_map<int, int> sums;
        for(auto i: nums1)
            for(auto j: nums2)
                ++sums[i + j];

        int count = 0;
        for(auto i: nums3)
            for(auto j: nums4)
                count += sums[-(i + j)];

        return count;
    }
};