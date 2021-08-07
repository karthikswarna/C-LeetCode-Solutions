class Solution {
public:
    int reverse(int x)
    {
        int reverse = 0;
        while(x != 0)
        {
            reverse = (reverse * 10) + (x % 10);
            x = x / 10;
            
            if(x != 0) // If there is anything remaining
            {
                if(( x > 0 && reverse > (INT_MAX - (x % 10)) / 10 ) ||
                   ( x < 0 && reverse < (INT_MIN - (x % 10)) / 10 ))
                    return 0;
            }
        }
        
        return reverse;
    }
};