class Solution {
public:
    string addBinary(string a, string b)
    {
        if(a.size() > b.size())
            b = string(a.size() - b.size(), '0') + b;
        if(a.size() < b.size())
            a = string(b.size() - a.size(), '0') + a;

        char carry = '0';
        string sum(a.size(), '0');
        for(int i = a.size() - 1; i >= 0; i--)
        {
            if(a[i] == '1' && b[i] == '1')
            {
                if(carry == '1')
                    sum[i] = '1';
                else
                    sum[i] = '0';

                carry = '1';
            }
            
            else if((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0'))
            {
                if(carry == '1')
                {
                    sum[i] = '0';
                    carry = '1';
                }
                else
                {
                    sum[i] = '1';
                    carry = '0';
                }
            }
            
            else
            {
                sum[i] = carry;
                carry = '0';
            }

        }
        
        if(carry == '1')
            sum = '1' + sum; 
        
        return sum;
    }
};