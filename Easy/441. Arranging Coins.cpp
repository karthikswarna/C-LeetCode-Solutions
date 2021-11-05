class Solution {
public:
    int arrangeCoins(int n)
    {
        // largest n for which (n(n + 1) / 2) <= coinCount
        long i = 0, sum = 0;
        while (sum <= n) 
            sum += ++i;
        
        return i - 1;
    }
};