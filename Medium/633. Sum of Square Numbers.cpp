class Solution {
public:
    // a, b can be in [0, sqrt(c)] (Because a, b cannot be larger than c it self.)
    bool judgeSquareSum(int c)
    {
        long low = 0;
        long high = sqrt(c);
        while(low <= high)
        {
            long val = low * low + high * high;
            
            if(val == c)
                return true;
            else if(val < c)
                ++low;
            else
                --high;
        }
        
        return false;
    }
};