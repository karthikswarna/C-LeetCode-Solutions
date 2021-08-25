class Solution {
public:
    string complexNumberMultiply(string num1, string num2)
    {
        int len1 = num1.size();
        int len2 = num2.size();
        
        int plusId1 = num1.find('+');
        int plusId2 = num2.find('+');
        
        int r1 = stoi(num1.substr(0, plusId1));
        int r2 = stoi(num2.substr(0, plusId2));
        
        int i1 = stoi(num1.substr(plusId1 + 1, len1 - plusId1 - 2));
        int i2 = stoi(num2.substr(plusId2 + 1, len2 - plusId2 - 2));
        
        string result = to_string((r1 * r2) - (i1 * i2)) + "+" + to_string((r1 * i2) + (r2 * i1)) + "i";

        return result;
    }
};