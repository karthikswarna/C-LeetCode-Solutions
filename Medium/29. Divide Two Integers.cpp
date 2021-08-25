class Solution {
public:
    int divide(int dividend, int divisor)
    {
        // Cases where overflow occurs.
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        if(divisor == INT_MIN) return dividend == INT_MIN;
        if(dividend == 0) return 0;

        bool isNeg = true;
        if((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) isNeg = false;

        long dend = abs(dividend);
        long sor = abs(divisor);
        int quotient = 0;
        long sum = 0;
        while(sum <= dend)
        {
            if(quotient == INT_MAX) return quotient;

            sum += sor;
            ++quotient;
        }

        return isNeg ? -(quotient - 1) : quotient - 1;
    }
};