class Solution {
public:
    int getSum(int a, int b)
    {
        // Binary Addition.
        int result = 0;
        int carry = 0;
        for(int i = 0; i < 32; ++i)
        {
            int aBit = (a & (1 << i));
            int bBit = (b & (1 << i));

            result = result ^ (aBit ^ bBit ^ carry);
            
            carry = (aBit & bBit) | (bBit & carry) | (aBit & carry);
            // Carry should be given to the next bit.
            if(carry > 0)
                carry = carry << 1;
        }
        
        return result;
    }
};