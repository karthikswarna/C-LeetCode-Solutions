class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;

        // Check if every bit is 1 by taking AND operation with each bit. If result is non-0, that bit is 1.
        for(int i = 0; i < 32; ++i)
            if( ((1 << i) & n) != 0 )
                ++count;

        return count;
    }
};