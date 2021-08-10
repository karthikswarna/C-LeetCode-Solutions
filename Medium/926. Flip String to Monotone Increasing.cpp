class Solution {
public:
    int minFlipsMonoIncr(string s)
    {
        int n = s.size();
        vector<int> leftOnes(n, 0);       // Prefix sums of ones. i.e. leftOnes[i] = number of ones in s[0..i] 
        vector<int> rightZeroes(n, 0);    // Suffix sums of zeroes. i.e rightZeroes[i] = zeroes in s[i..n-1]
        
        if(s[0] == '1') leftOnes[0] = 1;
        if(s[n - 1] == '0') rightZeroes[n - 1] = 1;
        
        for(int i = 1; i < n; i++)
        {
            leftOnes[i]  =  (s[i] == '1')  ?  (1 + leftOnes[i - 1])  :  leftOnes[i - 1];
            rightZeroes[n - i - 1]  =  (s[n - i - 1] == '0')  ?  (1 + rightZeroes[n - i])  :  rightZeroes[n - i];
        }
    
        int minFlips = n;
        for(int i = -1; i < n; i++) // -1 to cover corner case (Making all bits 1)
        {
            int left = (i == -1)  ?  0  :  leftOnes[i];
            int right = (i == n - 1)  ?  0  :  rightZeroes[i + 1];
            
            minFlips = std::min(left + right, minFlips);
        }
        
        return minFlips;
    }
};