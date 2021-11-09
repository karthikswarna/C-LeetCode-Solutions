class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int exor = 0;
        for(auto num: nums)
            exor ^= num;
        
        // Now, in exor atleast one bit must be set (as the two unique numbers are >= 2)
        // So, since "exor" is xor of those two numbers, each of the set bit in "exor" belongs to only one of the either numbers.
        // We find the least set bit in "exor" and find the number that has this bit set.
        int lsbIdx;
        for(int i = 0; i < 32; ++i)
        {
            if(exor & (1 << i))
            {
                lsbIdx = i;
                break;
            }
        }
        
        // Find the number for which least set bit (lsb) is set.
        int firstNum = 0;
        for(auto num: nums)
        {
            if(num & (1 << lsbIdx))     // If the bit is set.
                firstNum ^= num;
        }
        
        return {firstNum, exor ^ firstNum};
    }
};