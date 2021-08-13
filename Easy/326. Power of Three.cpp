class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if(n <= 0) return false;

        // n = 3^x  <=>  x = log_{3}(n)
        int x = log2(n) / log2(3);
        return n == pow(3, x);
    }
};