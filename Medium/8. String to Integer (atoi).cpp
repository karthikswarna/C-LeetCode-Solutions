class Solution {
public:
    int myAtoi(string s)
    {
        if(s.size() == 0) return 0;

        int n = s.size();
        int index = 0;

        // Ignore whitespace.
        while(index < n && s[index] == ' ')
            ++index;
        
        // Find the sign of the number.
        bool isNegative = false;
        if(index < n && s[index] == '-')
        {
            isNegative = true;
            ++index;
        }
        else if(index < n && s[index] == '+')
            ++index;
    
        // Read in the number.
        int num = 0;
        while(index < n && s[index] <= '9' && s[index] >= '0')
        {
            // Bound checking. And clamping to the maximum/minimum value.
            if( !isNegative && ((num > INT_MAX / 10) || (num == INT_MAX / 10 && (s[index] - '0' >= 7))) )
                return INT_MAX;

            else if( isNegative && ((num > INT_MAX / 10) || (num == INT_MAX / 10 && (s[index] - '0' >= 8))) )
                return INT_MIN;

            num = (num * 10) + (s[index] - '0');
            ++index;
        }
    
        return isNegative == true ? -num : num;
    }
};