class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int len = digits.size();
        digits[len - 1] += 1;
        int carry = 0;
        int temp;

        for(int i = len - 1; i >= 0; i--)
        {
            digits[i] += carry;
            temp = digits[i];
            digits[i] = temp % 10;
            carry = temp / 10;
        }
        
        if(carry != 0)
            digits.insert(digits.begin(), carry);
        
        return digits;
    }
};