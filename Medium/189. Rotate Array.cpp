class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        k %= nums.size();
        
        // std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
    
        std::reverse(nums.begin(), nums.end());
        // The last k elements which will be in the start after k rotations will now be in the start 
        // (in a reversed order.)
        
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};