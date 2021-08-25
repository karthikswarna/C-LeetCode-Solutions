class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";
        
        string result;
        if (numerator > 0 ^ denominator > 0)    //  Just one of them is positive
            result += '-';

        long num = labs(numerator);
        long den = labs(denominator);
        long rem = num % den;
        
        // Integral Part
        result += to_string(num / den);
        if (rem == 0) return result;

        // Fractional Part
        result += '.';
        unordered_map<long, int> rems;  // (Remainder -> index in result) mapping
        while(rem > 0)
        {
            if(rems.find(rem) != rems.end())
            {
                result.insert(rems[rem], "(");
                result += ')';
                break;
            }

            rems[rem] = result.size();
            rem *= 10;
            result += to_string(rem / den);
            rem %= den;
        }

        return result;
    }
};