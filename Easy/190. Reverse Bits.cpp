class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;

        for(int i = 0; i < 32; ++i)
        {
            result = result << 1;

            // If ith bit from (right to left) in n is 1,
            if( ((1 << i) & n) != 0 )
                result = result | 1;
        }
        
        return result;
    }
};