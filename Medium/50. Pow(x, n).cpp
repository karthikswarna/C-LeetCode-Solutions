class Solution {
public:
    double myPow(double x, long n)
    {
        if(n == 0) return 1;
        if(n < 0)
        {
            n = -n;
            x = 1 / x;
        }

        // (x^2)^(n/2) == x^n.
        return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
    }
    
    // TIMEOUT
//     double myPow(double x, int n)
//     {
//         double result = 1;
//         long absPow = abs((long)n);
        
//         while(absPow > 0)
//         {
//             result *= x;
//             --absPow;
//         }
        
//         return (n < 0) ? (1 / result) : result;
//     }
};