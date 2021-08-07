class Solution {
public:
    string longestPalindrome(string s)
    {
        // Create Table
        int **memo = new int*[s.size()];
        for(int i = 0; i < s.size(); i++)
            memo[i] = new int[s.size()];
        
        
        // Fill table for substrings of length 1 and 2.
        int maxLength = 1;
        string longest(1, s[0]);
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(i == j)
                    memo[i][j] = 1;

                else if((j - i == 1) && (s[i] == s[j]))
                {
                    if(2 > maxLength)
                    {
                        maxLength = 2;
                        longest = s.substr(i, 2);
                    }
                    
                    memo[i][j] = 1;
                }
                
                else
                    memo[i][j] = 0;    
            }
        }
        
        
        // Fill the rest of the table in a "diagonal way".
        // For the substring s[i][j] to be a palindrome, s[i+1][j-1] must be a palindrom and s[i] == s[j].
        for(int len = 2; len < s.size(); len++)
        {
            for(int i = 0; i+len < s.size(); i++)
            {
                //Filling the cell memo[i][i + len]
                int j = i + len;
                if((memo[i+1][j-1] == 1) && (s[i] == s[j]))
                {
                    if((j - i + 1) > maxLength)
                    {
                        maxLength = j - i + 1;
                        longest = s.substr(i, maxLength);
                    }
                    
                    memo[i][j] = 1;
                }
            }
        }
        
        return longest;
    }
};