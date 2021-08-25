class Solution
{
public:
    // Ans: Number of multiples of 10 in n! --> Number of multiples of 5 in n! (There are adequate 2's in n!)
    // We need to find numbers with 5 as a factor.

//     Given number 4617.
//     5^1 : 4617 ÷ 5 = 923.4, so we get 923 factors of 5
//     5^2 : 4617 ÷ 25 = 184.68, so we get 184 additional factors of 5
//     5^3 : 4617 ÷ 125 = 36.936, so we get 36 additional factors of 5
//     5^4 : 4617 ÷ 625 = 7.3872, so we get 7 additional factors of 5
//     5^5 : 4617 ÷ 3125 = 1.47744, so we get 1 more factor of 5
//     5^6 : 4617 ÷ 15625 = 0.295488, which is less than 1, so stop here.

//     Then 4617! has 923 + 184 + 36 + 7 + 1 = 1151 trailing zeroes.

    int trailingZeroes(int n)
    {
        int multiple = 5;
        int result = 0;
        int numFactors = INT_MAX;
        while(numFactors > 0)
        {
            numFactors = n / multiple;
            result += numFactors;
            
            multiple *= 5;
        }
        
        return result;
    }
};