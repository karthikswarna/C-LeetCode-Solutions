class Solution {
    vector<int> original;
    vector<int> current;
    default_random_engine rng = std::default_random_engine{};
public:
    Solution(vector<int>& nums)
    {
        original = nums;
        current = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        current = original;
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        std::shuffle(current.begin(), current.end(), rng);
        return current;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */