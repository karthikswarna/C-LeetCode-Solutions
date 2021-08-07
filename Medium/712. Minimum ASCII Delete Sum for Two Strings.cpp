class Solution {
public:
    int minimumDeleteSum(string s1, string s2)
    {
        vector<vector<int>> table(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return minDelSum(s1, s2, s1.size(), s2.size(), table);
    }
    
    int minDelSum(string& s1, string& s2, int i, int j, vector<vector<int>>& memo)
    {
        if(memo[i][j] != -1) return memo[i][j];

        if(i == 0 && j == 0) return 0;
        else if(i == 0) return memo[i][j] = SumAscii(s2, j);
        else if(j == 0) return memo[i][j] = SumAscii(s1, i);
        
        
        if(s1[i - 1] == s2[j - 1])
            return memo[i][j] = minDelSum(s1, s2, i - 1, j - 1, memo);
        
        else
            return memo[i][j] = std::min(
                                (int)s1[i - 1] + minDelSum(s1, s2, i - 1, j, memo), 
                                (int)s2[j - 1] + minDelSum(s1, s2, i, j - 1, memo));
    }
    
    int SumAscii(string s, int end)
    {
        int sum = 0;
        for(int i = 0; i < end; i++)
            sum += s[i];
        
        return sum;
    }
};