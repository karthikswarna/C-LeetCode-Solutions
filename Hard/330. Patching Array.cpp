class Solution {
public:
    // Thought Process: We want to generate all the numbers in [1, N]. So we can simply follow approach like Sieve of Eratosthenes and take an N-sized boolean array initialized to false. Then set true for all the possible sums of numbers in the given input.
    // Then the minimum number that is still false (which cannot be generated) should be patched to our array.
    // Continue this process till all N values become true in boolean array.

    // This is optimized version of above algorithm. We always patch with the minimum possible values.
    int minPatches(vector<int>& nums, int n)
    {
        int patchCount = 0;
        long nextNumber = 1;
        int i = 0;
        while (nextNumber <= n)
        {
            if (i < nums.size() && nums[i] <= nextNumber)
                nextNumber += nums[i++];

            else
            {
                nextNumber += nextNumber;
                ++patchCount;
            }
        }
        
        return patchCount;
    }
};